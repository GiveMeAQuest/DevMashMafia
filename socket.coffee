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
			pg.query "SELECT * FROM rooms WHERE id=#{data.room_id};", (result)->
				if result.rows.length is 0
					console.log 'Error: no such room'
					socket.emit EVENTS['err'], 'Room with such ID doesn\'t exist'
				else
					pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
						if result.rows.length > 0
							console.log 'Error: such user exists'
							socket.emit EVENTS['err'], 'Player with such username has already logged in to this room'
						else
							pg.query "INSERT INTO players (nickname, room_id) VALUES ('#{data.nickname}', '#{data.room_id}') RETURNING *;", (result)->
								player = result.rows[0]
								io.to(data.room_id).emit 'player joined', JSON.stringify player
								socket.join data.room_id

								socket.emit EVENTS['room joined'], JSON.stringify player

		socket.on EVENTS['get waiting players'], (roomid)->
			console.log "get players of room##{roomid}"
			pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{roomid}';", (result)->
				socket.emit EVENTS['players'], JSON.stringify result.rows

		socket.on EVENTS['leave room'], (playerid)->
			console.log "player##{playerid} is leaving his room"
			pg.query "DELETE FROM players WHERE id=#{playerid} RETURNING room_id;", (result)->
				room_id = result.rows[0].room_id

				socket.emit EVENTS['room left']

				pg.query "DELETE FROM rooms WHERE id=#{room_id} AND (SELECT COUNT(*) AS count FROM players WHERE room_id=#{room_id})=0;"


		socket.on EVENTS['create room'], (params)->
			console.log 'create room'
			pg.query 'WITH RECURSIVE room AS (INSERT INTO rooms (params_id) VALUES ((select params_id from params)) RETURNING id AS room_id), params AS (INSERT INTO room_params (room_id) VALUES (NULL) RETURNING id AS params_id) SELECT * FROM room, params;', (result)->

				room_id = result.rows[0].room_id
				params_id = result.rows[0].params_id

				pg.query "UPDATE room_params SET room_id=#{room_id} WHERE id=#{params_id};", ->
					console.log "created room##{room_id}"
					socket.emit EVENTS['room created'], room_id

	io