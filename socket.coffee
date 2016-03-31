CONFIG = require './config'
pg = require './pg'

module.exports = (server)->
	io = require('socket.io').listen server
	io.on 'connection', (socket)->
		console.log 'new connection'

		socket.on CONFIG['get rooms'], ->
			console.log 'get rooms'
			pg.query "SELECT rooms.id, rooms.name, phases.name AS phase FROM rooms, phases WHERE rooms.phase_id=phases.id;", (result)->
				socket.emit CONFIG['rooms'], JSON.stringify result.rows

		socket.on CONFIG['login'], (data)->
			if typeof data is 'string' then data = JSON.parse data
			console.log "login with nickname #{data.nickname} to room ID #{data.room_id}"
			pg.query "INSERT INTO players (nickname, room_id) VALUES ('#{data.nickname}', '#{data.room_id}');", (result)->
				socket.emit CONFIG['logged']

		socket.on CONFIG['get room'], (roomid)->
			if typeof data is 'string' then data = JSON.parse data
			console.log "get room #{roomid}"
			pg.query "SELECT rooms.id, rooms.name, phases.name AS phase FROM rooms, phases WHERE rooms.id=#{roomid} AND rooms.phase_id=phases.id;", (result)->
				socket.emit CONFIG['room'], JSON.stringify result.rows[0]

		socket.on CONFIG['get waiting players'], (roomid)->
			if typeof data is 'string' then data = JSON.parse data
			console.log "get players of room ID #{roomid}"
			pg.query "SELECT id, nickname FROM players WHERE players.room_id='#{roomid}';", (result)->
				socket.emit CONFIG['players'], JSON.stringify result.rows

	io