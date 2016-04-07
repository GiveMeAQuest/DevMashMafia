should = require 'should'

describe 'socket connection', ->
	it 'should connect to socket server', (done)->
		@timeout 5000
		
		socket = require('socket.io-client') 'devmashmafia.herokuapp.com'
		socket.on 'connect', ->
			done()