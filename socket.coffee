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

pg.query "DELETE FROM players; DELETE FROM rooms;", ->
	console.log 'players and rooms erased'

funcs =

	'leave room': (socket)->
		i = findPlayer socket.id
		if i is -1 then return
		player_id = PLAYERS[i].id
		pg.query "DELETE FROM players WHERE id=#{player_id} RETURNING room_id, id AS player_id;", (result)->
			PLAYERS.splice i, 1

			socket.emit EVENTS['room left']

			if result.rows.length > 0
				console.log "player ID #{player_id} is leaving his room"

				room_id = result.rows[0].room_id
				player_id = result.rows[0].player_id

				io.to(room_id).emit EVENTS['player left'], player_id
				console.log "player from room ID #{room_id} left"

				pg.query "SELECT players.id FROM players, rooms WHERE rooms.id=#{room_id} AND players.id=rooms.host_id;", (result)->
					if result.rows.length is 0
						pg.query "SELECT id FROM players WHERE room_id=#{room_id} LIMIT 1;", (result)->
							if result.rows.length > 0
								new_host = result.rows[0]

								pg.query "UPDATE rooms SET host_id=#{new_host.id} WHERE id=#{room_id};", ->
									console.log "host in room ID #{room_id} changed to ID #{new_host.id}"
									io.to(room_id).emit EVENTS['host changed'], new_host.id
							else
								pg.query "DELETE FROM rooms WHERE id=#{room_id};"

	'join room': (socket, data)->
		if typeof data is 'string'
			try
				data = JSON.parse data
			catch e
				console.log 'join room: invalid data!'
				socket.emit EVENTS['err'], 'Invalid data!'
				return

		if isNaN data.room_id or !data.nickname?
			console.log 'join room: invalid data!'
			socket.emit EVENTS['err'], 'Invalid data!'
			return

		console.log "join room with nickname #{data.nickname} to room ID #{data.room_id}"
		pg.query "SELECT * FROM rooms WHERE id=#{data.room_id};", (result)->
			if result.rows.length is 0
				console.log 'Error: no such room'
				socket.emit EVENTS['err'], 'Room with such ID doesn\'t exist'
			else
				pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
					if result.rows.length > 0
						console.log 'Error: user exists'
						socket.emit EVENTS['err'], 'Player with same username has already joined this room'
					else
						pg.query "INSERT INTO players (nickname, room_id) VALUES ('#{data.nickname}', #{data.room_id}) RETURNING *;", (result)->

							player = result.rows[0]

							PLAYERS.push new Player
								id: player.id
								socket_id: socket.id
								room_id: data.room_id

							pg.query "UPDATE rooms SET host_id=#{player.id} WHERE id=#{data.room_id} AND (SELECT COUNT(*) FROM players WHERE room_id=#{data.room_id})=1;", ->

								io.to(data.room_id).emit EVENTS['player joined'], JSON.stringify player

								socket.join data.room_id

								socket.emit EVENTS['room joined'], JSON.stringify player

	'get waiting players': (socket)->
		i = findPlayer socket.id
		if i is -1
			console.log 'get waiting players: user is not in room'
			socket.emit EVENTS['err'], 'You are not in room'
			return
		player = PLAYERS[i]
		console.log player
		console.log "get players of room ID #{player.room_id}"
		pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{player.room_id}';", (result)->
			socket.emit EVENTS['players'], JSON.stringify result.rows

	'create room': (socket, params)->
		if typeof params is 'string'
			try
				params = JSON.parse params
			catch e
				console.log 'create room: invalid data!'
				socket.emit EVENTS['err'], 'Invalid data!'
				return

		if isNaN params.players
			console.log 'create room: invalid data!'
			socket.emit EVENTS['err'], 'Invalid data!'
			return
		
		console.log "create room"
		roomQuery = "INSERT INTO rooms (params_id) VALUES ((select params_id from params)) RETURNING id AS room_id"
		paramsQuery = "INSERT INTO room_params (players) VALUES (#{params.players}) RETURNING id AS params_id"

		pg.query "WITH RECURSIVE room AS (#{roomQuery}), params AS (#{paramsQuery}) SELECT * FROM room, params;", (result)->

			room_id = result.rows[0].room_id
			params_id = result.rows[0].params_id

			pg.query "UPDATE room_params SET room_id=#{room_id} WHERE id=#{params_id};", ->
				console.log "created room ID #{room_id}"
				socket.emit EVENTS['room created'], room_id

	'get room': (socket, room_id)->
		if isNaN room_id
			console.log "get room: invalid data!"
			console.log "room_id is #{room_id}"
			socket.emit EVENTS['err'], "Invalid data!"
			return

		console.log "get room ID #{room_id} info"

		pg.query "SELECT rooms.id, rooms.host_id, phases.name AS phase, room_params.players FROM rooms, phases, room_params WHERE rooms.id=#{room_id} AND phases.id=rooms.phase_id AND room_params.room_id=#{room_id};", (result)->
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
		console.log 'new socket connection'

		funcsWithOneArg = [
			'leave room', 
			'join room',
			'get waiting players', 
			'create room' ,
			'get room',
		]
	
		for event in funcsWithOneArg
			console.log event, EVENTS[event]
			socket.on EVENTS[event], do (event) ->
				(arg) -> funcs[event] socket, arg

		socket.on 'disconnect', ->
			funcs['disconnect'] socket

	io