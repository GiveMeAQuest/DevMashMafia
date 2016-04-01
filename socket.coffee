EVENTS = require './events'
pg = require './pg'
Player = require './classes/Player'
Phase = require './classes/Phase'

module.exports = (server)->
	io = require('socket.io').listen server
	io.on 'connection', (socket)->
		console.log 'new connection'

		socket.on EVENTS['join room'], (data)->
			if typeof data is 'string' then data = JSON.parse data
			console.log "join room with nickname #{data.nickname} to room##{data.room_id}"
			pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
				if result.rows.length > 0
					console.log 'Error: such user exists'
					socket.emit EVENTS['err'], 'Player with such username has already logged in to this room'
				else
					pg.query "INSERT INTO players (nickname, room_id) VALUES ('#{data.nickname}', '#{data.room_id}');", (result)->
						pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
							player = result.rows[0]
							io.to(data.room_id).emit 'player joined', JSON.stringify player
							socket.join data.room_id

							socket.emit EVENTS['room joined'], JSON.stringify player

		socket.on EVENTS['get waiting players'], (roomid)->
			console.log "get players of room##{roomid}"
			pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{roomid}';", (result)->
				socket.emit EVENTS['players'], JSON.stringify result.rows

		socket.on EVENTS['leave room'], (playerid)->
			console.log "leave room##{playerid}"
			pg.query "DELETE FROM players WHERE id=#{playerid};", ->
				socket.emit EVENTS['room left']

	io