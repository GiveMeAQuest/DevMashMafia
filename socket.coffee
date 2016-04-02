EVENTS = require './events'
pg = require './pg'
Player = require './classes/Player'

io = null

PLAYERS = []

findPlayer = (socket_id)->
	for i of PLAYERS
		player = PLAYERS[i]
		if player.socket_id is socket_id
			return i
	-1

pg.query "DELETE FROM players; DELETE FROM ROOMS;", ->
	console.log 'players and rooms erased'

funcs =

	'leave room': (socket, player_id)->
		pg.query "DELETE FROM players WHERE id=#{player_id} RETURNING room_id, id AS player_id;", (result)->
			socket.emit EVENTS['room left']

			if result.rows.length > 0
				console.log "player ID #{player_id} is leaving his room"

				room_id = result.rows[0].room_id
				player_id = result.rows[0].player_id

				io.to(room_id).emit EVENTS['player left'], player_id
				console.log "player from room ID #{room_id} left"

				pg.query "DELETE FROM rooms WHERE id=#{room_id} AND (SELECT COUNT(*) AS count FROM players WHERE room_id=#{room_id})=0;"

	'join room': (socket, data)->
		if typeof data is 'string' then data = JSON.parse data
		console.log "join room with nickname #{data.nickname} to room ID #{data.room_id}"
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

							PLAYERS.push new Player player.id, socket.id

							io.to(data.room_id).emit EVENTS['player joined'], JSON.stringify player

							socket.join data.room_id

							socket.emit EVENTS['room joined'], JSON.stringify player

	'get waiting players': (socket, room_id)->
		console.log "get players of room ID #{room_id}"
		pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{room_id}';", (result)->
			socket.emit EVENTS['players'], JSON.stringify result.rows

	'create room': (socket, params)->
		console.log 'create room'
		roomQuery = "INSERT INTO rooms (params_id) VALUES ((select params_id from params)"
		paramsQuery = "INSERT INTO room_params (players) VALUES (#{params.players}) RETURNING id AS params_id"

		pg.query "WITH RECURSIVE room AS (#{roomQuery}) RETURNING id AS room_id), params AS (#{paramsQuery}) SELECT * FROM room, params;", (result)->

			room_id = result.rows[0].room_id
			params_id = result.rows[0].params_id

			pg.query "UPDATE room_params SET room_id=#{room_id} WHERE id=#{params_id};", ->
				console.log "created room ID #{room_id}"
				socket.emit EVENTS['room created'], room_id

	'get room': (socket, room_id)->
		pg.query "SELECT rooms.id, phases.name AS phase, room_params.players FROM rooms, phases, room_params WHERE rooms.id=#{room_id} AND phases.id=rooms.phase_id AND room_params.room_id=#{room_id};", (result)->
			room = result.rows[0]
			socket.emit EVENTS['room'], JSON.stringify room

	'disconnect': (socket)->
		ind = findPlayer socket.id
		if ind isnt -1
			player = PLAYERS[ind]
			console.log "player ID #{player.id} disconnected"
			funcs['leave room'] socket, player.id
		else
			console.log 'socket disconnected'

module.exports = (server)->
	io = require('socket.io').listen server
	io.on 'connection', (socket)->
		console.log 'new connection'

		socket.on EVENTS['join room'], (data)->
			funcs['join room'] socket, data

		socket.on EVENTS['get waiting players'], (room_id)->
			funcs['get waiting players'] socket, room_id

		socket.on EVENTS['leave room'], (player_id)->
			funcs['leave room'] socket, player_id

		socket.on EVENTS['create room'], (params)->
			funcs['create room'] socket, params

		socket.on EVENTS['get room'], (room_id)->
			funcs['get room'] socket, room_id

		socket.on 'disconnect', ->
			funcs['disconnect'] socket

	io