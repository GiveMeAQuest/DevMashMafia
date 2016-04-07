should = require 'should'

describe 'socket connection', ->
	it 'should connect to socket server', (done)->
		@timeout 5000
		
		socket = require('socket.io-client') 'http://localhost:3000'
		socket.on 'connect', ->
			done()