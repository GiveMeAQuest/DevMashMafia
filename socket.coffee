CONFIG = require './config'
pg = require './pg'
Player = require './classes/Player'
Phase = require './classes/Phase'
#Room = require './classes/Room'

module.exports = (server)->
	io = require('socket.io').listen server
	io.on 'connection', (socket)->
		console.log 'new connection'

		socket.on CONFIG['login'], (data)->
			if typeof data is 'string' then data = JSON.parse data
			console.log "login with nickname #{data.nickname} to room ID #{data.room_id}"
			pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
				if result.rows.length > 0
					console.log 'Error: such user exists'
					socket.emit CONFIG['err'], 'Player with such username has already logged in to this room'
				else
					pg.query "INSERT INTO players (nickname, room_id) VALUES ('#{data.nickname}', '#{data.room_id}');", (result)->
						pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
							player = result.rows[0]
							io.to(data.room_id).emit 'player logged', JSON.stringify player
							socket.join data.room_id

							socket.emit CONFIG['logged'], JSON.stringify player

		socket.on CONFIG['get waiting players'], (roomid)->
			console.log "get players of room ID #{roomid}"
			pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{roomid}';", (result)->
				socket.emit CONFIG['players'], JSON.stringify result.rows

		socket.on CONFIG['leave room'], (playerid)->
			console.log "leave room ID #{playerid}"
			pg.query "DELETE FROM players WHERE id=#{playerid};", ->
				socket.emit CONFIG['room left']

	io