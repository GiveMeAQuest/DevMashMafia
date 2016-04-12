should = require 'should'

HOST = 'http://localhost:3000'

describe 'socket connection', ->
	it 'should connect to socket server', (done)->
		@timeout 5000
		
		socket = require('socket.io-client') HOST
		socket.on 'connect', ->
			done()