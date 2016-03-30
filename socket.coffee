http = require 'http'

module.exports = (app)->
	server = http.createServer app
	io = require('socket.io')(server)
	io.on 'connection', (socket)->
		console.log 'new connection'

	io