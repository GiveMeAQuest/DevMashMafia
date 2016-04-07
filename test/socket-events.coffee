should = require 'should'
request = require 'request'
socket = require('socket.io-client') 'devmashmafia.herokuapp.com'

describe 'socket events', ->
	@slow 5000
	#@timeout 10000

	@room_id = @player = EVENTS = null

	it 'should create room', (done)=>

		request.get 'http://devmashmafia.herokuapp.com/api/events', (err, response)=>

			EVENTS = response.body
			if typeof EVENTS is 'string' then EVENTS = JSON.parse EVENTS

			data =
				players: 10

			socket.on EVENTS['room created'], (data)=>
				data = JSON.parse data

				data.should.have.property 'id'
				data.id.should.be.Number()

				@room_id = data.id

				done()

			socket.emit EVENTS['create room'], data

	it 'should join room', (done)=>

		data =
			room_id: @room_id
			nickname: 'test'

		socket.emit EVENTS['join room'], JSON.stringify data

		socket.on EVENTS['room joined'], (player)=>
			player = JSON.parse player

			player.should.have.properties ['id', 'nickname', 'room_id', 'reconnect_token']
			player.id.should.be.Number()
			player.nickname.should.be.String().and.should.not.be.empty()
			player.room_id.should.be.Number().and.equal @room_id
			player.reconnect_token.should.be.String().and.should.not.be.empty()

			@player = player

			done()

	it 'should get room info', (done)=>

		socket.emit EVENTS['get room']

		socket.on EVENTS['room'], (data)=>
			data = JSON.parse data

			data.should.have.properties ['id', 'host_id', 'phase']
			data.id.should.be.Number().and.equal @room_id
			data.host_id.should.be.Number().and.equal @player.id
			data.phase.should.be.String()
			done()

	it 'should get waiting players', (done)->

		socket.emit EVENTS['get waiting players']

		socket.on EVENTS['players'], (data)->
			data = JSON.parse data

			data.should.have.property 'players'
			data.players.length.should.be.exactly 1
			for player in data.players
				player.should.have.properties ['id', 'nickname']
				player.id.should.be.Number()
				player.nickname.should.be.String()
			done()

	it 'should leave room', (done)->

		socket.emit EVENTS['leave room']

		socket.on EVENTS['room left'], ->
			done()

	it 'should not reconnect', (done)=>

		socket.close()

		socket = require('socket.io-client') 'devmashmafia.herokuapp.com'

		socket.on 'connect', =>

			data =
				reconnect_token: @player.reconnect_token

			socket.emit EVENTS['reconnect'], JSON.stringify data

			socket.on EVENTS['err'], (error)->
				done()

	it.skip 'should reconnect', (done)=>

		socket.close()

		socket = require('socket.io-client') 'http://localhost:3000'

		socket.on 'connect', =>

			data =
				reconnect_token: @player.reconnect_token

			socket.emit EVENTS['reconnect'], JSON.stringify data

			socket.on EVENTS['join room'], (data)=>
				data = JSON.parse data

				data.id.should.be.equal @player.id
				data.room_id.should.be.equal @room_id
				data.nickname.should.be.equal @player.nickname
				done()