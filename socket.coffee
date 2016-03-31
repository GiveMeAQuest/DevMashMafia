CONFIG = require './config'
pg = require './pg'

module.exports = (server)->
	io = require('socket.io').listen server
	io.on 'connection', (socket)->
		console.log 'new connection'

		socket.on CONFIG['get rooms'], ->
			console.log 'get rooms'
			pg.query "SELECT rooms.id, rooms.name, phases.name AS phase FROM rooms, phases WHERE rooms.phase_id=phases.id;", (result)->
				console.log 'rooms: ', result.rows
				socket.emit CONFIG['rooms'], JSON.stringify result.rows

	io