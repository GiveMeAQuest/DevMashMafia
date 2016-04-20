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

			PLAYERS[i].online = false
			reconnect_token = PLAYERS[i].reconnect_token
			do(reconnect_token)->
				setTimeout ->
					for player, i in PLAYERS
						if player.reconnect_token is reconnect_token
							if player.online then return
							PLAYERS.splice i, 1
							break
				, 5000

			socket.emit EVENTS['room left']

			if result.rows.length > 0
				console.log "player ID #{player_id} is leaving his room"

				room_id = result.rows[0].room_id
				player_id = result.rows[0].player_id

				socket.leave room_id

				io.to(room_id).emit EVENTS['player left'], JSON.stringify
					id: player_id

				console.log "player from room ID #{room_id} left"

				pg.query "SELECT players.id FROM players, rooms WHERE rooms.id=#{room_id} AND players.id=rooms.host_id;", (result)->
					if result.rows.length is 0
						pg.query "SELECT id FROM players WHERE room_id=#{room_id} LIMIT 1;", (result)->
							if result.rows.length > 0
								new_host = result.rows[0]

								pg.query "UPDATE rooms SET host_id=#{new_host.id} WHERE id=#{room_id};", ->
									console.log "host in room ID #{room_id} changed to ID #{new_host.id}"
									io.to(room_id).emit EVENTS['host changed'], JSON.stringify
										id: new_host.id
							else
								pg.query "DELETE FROM rooms WHERE id=#{room_id};"

	'join room': (socket, data)->
		if typeof data is 'string'
			try
				data = JSON.parse data
			catch e
				console.log 'join room: invalid data!'
				socket.emit EVENTS['err'], JSON.stringify
					event: 'join room'
					error: 'Invalid data!'
				return

		if (!data.reconnect_token?) and (isNaN data.room_id or !data.nickname?)
			console.log 'join room: invalid data!'
			socket.emit EVENTS['err'], JSON.stringify
				event: 'join room'
				error: 'Invalid data!'
			return

		console.log "join room with nickname #{data.nickname} to room ID #{data.room_id}"
		pg.query "SELECT * FROM rooms WHERE id=#{data.room_id};", (result)->
			if result.rows.length is 0
				console.log 'Error: no such room'
				socket.emit EVENTS['err'], JSON.stringify
					event: 'join room'
					error: 'Room with such ID doesn\'t exist'
			else
				pg.query "SELECT * FROM players WHERE nickname='#{data.nickname}' AND room_id=#{data.room_id};", (result)->
					if result.rows.length > 0
						console.log 'Error: user exists'
						socket.emit EVENTS['err'], JSON.stringify
							event: 'join room'
							error: 'Player with same username has already joined this room'
					else
						pg.query "INSERT INTO players (nickname, room_id, socket_id) VALUES ('#{data.nickname}', #{data.room_id}, '#{socket.id}') RETURNING *;", (result, err)->

							if err?
								socket.emit EVENTS['err'], JSON.stringify
									event: 'join room'
									error: err
								return

							player = result.rows[0]
							new_player = null

							if data.reconnect_token
								data.player.id = player.id
								new_player = data.player
							else
								for cur, i in PLAYERS
									if cur.socket_id is socket.id
										PLAYERS.splice i, 1
										break
								PLAYERS.push new Player
									id: player.id
									nickname: player.nickname
									socket_id: socket.id
									room_id: data.room_id
								new_player = PLAYERS[PLAYERS.length - 1]

								player = new_player

							pg.query "UPDATE rooms SET host_id=#{player.id} WHERE id=#{data.room_id} AND (SELECT COUNT(*) FROM players WHERE room_id=#{data.room_id})=1;", ->

								player_to_return =
									id: player.id
									nickname: player.nickname
									room_id: player.room_id
									reconnect_token: player.reconnect_token

								io.to(data.room_id).emit EVENTS['player joined'], JSON.stringify player_to_return

								socket.join data.room_id

								socket.emit EVENTS['room joined'], JSON.stringify player_to_return


	'get waiting players': (socket)->
		i = findPlayer socket.id
		if i is -1
			console.log 'get waiting players: user is not in room'
			socket.emit EVENTS['err'], JSON.stringify
				event: 'get waiting players'
				error: 'You are not in room'
			return
		player = PLAYERS[i]
		console.log "get players of room ID #{player.room_id}"
		pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{player.room_id}';", (result)->
			socket.emit EVENTS['players'], JSON.stringify
				players: result.rows

	'create room': (socket, params)->
		if typeof params is 'string'
			try
				params = JSON.parse params
			catch e
				console.log 'create room: invalid data!'
				socket.emit EVENTS['err'], JSON.stringify
					event: 'create room'
					error: 'Invalid data!'
				return

		if isNaN params.players
			console.log 'create room: invalid data!'
			socket.emit EVENTS['err'], JSON.stringify
				event: 'create room'
				error: 'Invalid data!'
			return
		
		console.log "create room"
		roomQuery = "INSERT INTO rooms (params_id) VALUES ((select params_id from params)) RETURNING id AS room_id"
		paramsQuery = "INSERT INTO room_params (players) VALUES (#{params.players}) RETURNING id AS params_id"

		pg.query "WITH RECURSIVE room AS (#{roomQuery}), params AS (#{paramsQuery}) SELECT * FROM room, params;", (result)->

			room_id = result.rows[0].room_id
			params_id = result.rows[0].params_id

			pg.query "UPDATE room_params SET room_id=#{room_id} WHERE id=#{params_id};", ->
				console.log "created room ID #{room_id}"
				socket.emit EVENTS['room created'], JSON.stringify
					id: room_id

	'get room': (socket)->

		i = findPlayer socket.id
		player = PLAYERS[i]

		console.log "get room ID #{player.room_id} info for player ID #{player.id}"

		pg.query "SELECT rooms.id, rooms.host_id, phases.name AS phase, room_params.players FROM rooms, phases, room_params WHERE rooms.id=#{player.room_id} AND phases.id=rooms.phase_id AND room_params.room_id=#{player.room_id};", (result)->
			room = result.rows[0]
			socket.emit EVENTS['room'], JSON.stringify room

	'reconnect': (socket, data)->
		if typeof data is 'string' then data = JSON.parse data
		console.log "player is trying to reconnect with token #{data.reconnect_token}"
		player = null
		player_i = null
		for cur, i in PLAYERS
			if cur.reconnect_token is data.reconnect_token
				player = cur
				player_i = i
				break
		if player?
			console.log "reconnected player:", player
			funcs['join room'] socket,
				reconnect_token: data.reconnect_token
				player: player
				room_id: player.room_id
				nickname: player.nickname
		else
			console.log 'error: invalid reconnect token'
			socket.emit EVENTS['err'], JSON.stringify
				event: 'reconnect'
				error: 'Invalid reconnect token'

	'start game': (socket)->
		i = findPlayer socket.id
		if i is -1
			console.log 'error: player is not in room'
			socket.emit EVENTS['err'], JSON.stringify
				event: 'start game'
				error: 'You are not in room'
			return

		player = PLAYERS[i]

		pg.query "SELECT id, host_id FROM rooms WHERE id=#{player.room_id};", (result)->

			room = result.rows[0]
			if room.host_id isnt player.id
				console.log 'error: player is not a host'
				socket.emit EVENTS['err'], JSON.stringify
					event: 'start game'
					error: 'You are not a host'
				return

			console.log "Player #{player.nickname} is starting game in room ID #{player.room_id}"

			pg.query "SELECT * FROM players WHERE room_id=#{player.room_id}", (result)->
				players = result.rows
				for cur, i in players
					players[i].socket = io.sockets.connected[cur.socket_id]

				# Shuffling the array
				currentIndex = players.length
				while (currentIndex isnt 0)
					randomIndex = Math.floor Math.random() * currentIndex
					--currentIndex
					temporaryValue = players[currentIndex]
					players[currentIndex] = players[randomIndex]
					players[randomIndex] = temporaryValue

				pg.query "SELECT * FROM roles;", (result)->
					roles = {}
					for role in result.rows
						roles[role.name] = role

					for player, i in players
						if player.nickname is '1'
							players[i].role = roles.mafia
						else
							players[i].role = roles.citizen

					###players[0].role = roles.mafia
					if players.length >= 2
						players[1].role = roles.citizen
					if players.length >= 3
						players[2].role = roles.citizen###

					for cur_player in players
						i = findPlayer cur_player.socket.id
						PLAYERS[i].role = cur_player.role
						pg.query "UPDATE players SET role_id=#{cur_player.role.id} WHERE id=#{cur_player.id};"
						cur_player.socket.emit EVENTS['role'], JSON.stringify
							name: cur_player.role.name
				setTimeout ->
					funcs['change phase'] socket,
						room_id: room.id
						phase_name: 'night begin'
				, 2000

	'mafia vote': (socket, data)->
		if typeof data is 'string' then data = JSON.parse data

		if isNaN data.id
			console.log 'Error: invalid player ID'
			socket.emit EVENTS['err'], JSON.stringify
				event: 'mafia vote'
				error: 'Invalid player ID'
			return

		i = findPlayer socket.id
		player = PLAYERS[i]
		if player.role.name isnt 'mafia'
			console.log "Player #{player.nickname} isn't mafia!"
			socket.emit EVENTS['err'], JSON.stringify
				event: 'mafia vote'
				error: 'You are not mafia'
			return

		pg.query "UPDATE players SET votes=votes+1 WHERE id=#{data.id};", ->
			pg.query "SELECT SUM(votes) FROM players WHERE room_id=#{player.room_id};", (result)->
				total_votes = result.rows[0].sum


			console.log "Player #{player.name} voted for #{voted_player.name}"
			

	'change phase': (socket, data)->

		i = findPlayer socket.id
		player = PLAYERS[i]

		pg.query "WITH phase as (SELECT id FROM phases WHERE name='#{data.phase_name}') UPDATE rooms SET phase_id=phase.id FROM phase WHERE rooms.id=#{data.room_id};", ->
			console.log "Phase changed to '#{data.phase_name}' in room ID #{data.room_id}"

			switch data.phase_name

				when 'night begin'
					io.to(data.room_id).emit EVENTS['phase changed'], JSON.stringify
						phase_name: 'night begin'
					pg.query "UPDATE players SET votes=0 WHERE room_id=#{data.room_id};", ->
						setTimeout ->
							funcs['change phase'] socket,
								room_id: data.room_id
								phase_name: 'mafia begin'
						, 1000

				when 'mafia begin'
					pg.query "WITH mafia_role AS (SELECT id FROM roles WHERE name='mafia') SELECT players.* FROM players, mafia_role WHERE room_id=#{data.room_id} AND role_id=mafia_role.id;", (result)->
						mafia_players = result.rows
						for cur, i in mafia_players
							mafia_players[i].socket = io.sockets.connected[cur.socket_id]
						pg.query "WITH mafia_role AS (SELECT id FROM roles WHERE name='mafia') SELECT * FROM players, mafia_role WHERE room_id=#{data.room_id} AND NOT(role_id=mafia_role.id);", (result)->
							non_mafia_players = result.rows
							for cur, i in non_mafia_players
								non_mafia_players[i].socket = io.sockets.connected[cur.socket_id]

								for mafia_player in mafia_players
									console.log "emitting 'mafia begin' to #{mafia_player.nickname}"
									mafia_player.socket.emit EVENTS['phase changed'], JSON.stringify
										phase_name: 'mafia begin'
										players: non_mafia_players.map (cur)->
											id: cur.id
											nickname: cur.nickname
						

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

		socket.on EVENTS['join room'], (data)->
			funcs['join room'] socket, data

		socket.on EVENTS['get waiting players'], ->
			funcs['get waiting players'] socket

		socket.on EVENTS['leave room'], ->
			funcs['leave room'] socket

		socket.on EVENTS['create room'], (data)->
			funcs['create room'] socket, data

		socket.on EVENTS['get room'], ->
			funcs['get room'] socket,

		socket.on EVENTS['reconnect'], (data)->
			funcs['reconnect'] socket, data

		socket.on EVENTS['start game'], ->
			funcs['start game'] socket

		socket.on EVENTS['mafia vote'], (data)->
			funcs['mafia vote'] socket, data

		socket.on 'disconnect', ->
			funcs['disconnect'] socket 

	io