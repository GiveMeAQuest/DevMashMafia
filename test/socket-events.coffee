HOST = 'http://localhost:3000'

should = require 'should'
request = require 'request'
Promise = require 'promise'
socket = require('socket.io-client') HOST
socket2 = require('socket.io-client') HOST

describe 'socket events', ->
	@slow 4000
	@timeout 5000

	@room_id = @player = @player2 = EVENTS = null

	it 'should create room (1)', (done)=>

		request.get "#{HOST}/api/events", (err, response)=>

			EVENTS = response.body
			if typeof EVENTS is 'string' then EVENTS = JSON.parse EVENTS

			data =
				players: 10

			socket.on EVENTS['room created'], (data)=>
				socket.removeAllListeners EVENTS['room created']
				data = JSON.parse data

				data.should.have.property 'id'
				data.id.should.be.Number()

				@room_id = data.id

				done()

			socket.emit EVENTS['create room'], data

	it 'should join room (1)', (done)=>

		data =
			room_id: @room_id
			nickname: 'test'

		socket.emit EVENTS['join room'], JSON.stringify data

		socket.on EVENTS['room joined'], (player)=>
			socket.removeAllListeners EVENTS['room joined']
			player = JSON.parse player

			player.should.have.properties ['id', 'nickname', 'room_id', 'reconnect_token']
			player.id.should.be.Number()
			player.nickname.should.be.String().and.should.not.be.empty()
			player.room_id.should.be.Number().and.equal @room_id
			player.reconnect_token.should.be.String().and.should.not.be.empty()

			@player = player

			done()

	it 'should get room info (1)', (done)=>

		socket.emit EVENTS['get room']

		socket.on EVENTS['room'], (data)=>
			socket.removeAllListeners EVENTS['room']
			data = JSON.parse data

			data.should.have.properties ['id', 'host_id', 'phase']
			data.id.should.be.Number().and.equal @room_id
			data.host_id.should.be.Number().and.equal @player.id
			data.phase.should.be.String()
			done()

	it 'should get waiting players (1)', (done)->

		socket.emit EVENTS['get waiting players']

		socket.on EVENTS['players'], (data)->
			socket.removeAllListeners EVENTS['players']
			data = JSON.parse data

			data.should.have.property 'players'
			data.players.length.should.be.exactly 1
			for player in data.players
				player.should.have.properties ['id', 'nickname']
				player.id.should.be.Number()
				player.nickname.should.be.String()
			done()

	it 'should join room (2)', (done)=>

		data =
			room_id: @room_id
			nickname: 'test2'

		socket2.emit EVENTS['join room'], data

		socket2.on EVENTS['room joined'], (data)=>
			socket2.removeAllListeners EVENTS['room joined']
			data = JSON.parse data

			data.should.have.properties ['id', 'nickname', 'room_id', 'reconnect_token']
			data.room_id.should.equal @room_id
			@player2 = data
			done()

	it 'should get waiting players (2)', (done)->

		socket2.emit EVENTS['get waiting players']

		socket2.on EVENTS['players'], (data)->
			socket2.removeAllListeners EVENTS['players']
			data = JSON.parse data

			data.players.length.should.be.exactly 2
			done()

	it 'should not start the game', (done)->

		socket2.emit EVENTS['start game']

		socket2.on EVENTS['err'], ->
			socket2.removeAllListeners EVENTS['err']
			done()

	it 'should start the game and receive roles (1)', ->

		q1 = new Promise (resolve, reject)->

			socket.on EVENTS['role'], (data)->
				socket.removeAllListeners EVENTS['role']
				data = JSON.parse data

				data.should.have.property 'name'
				console.log 'player 1 is', data.name
				resolve()

		q2 = new Promise (resolve, reject)->

			socket2.on EVENTS['role'], (data)->
				socket2.removeAllListeners EVENTS['role']
				data = JSON.parse data

				data.should.have.property 'name'
				console.log 'player 2 is', data.name
				resolve()

		socket.emit EVENTS['start game']

		Promise.all [q1, q2]

	it 'should receive "night begin" event', ->

		q1 = new Promise (resolve, reject)->

			socket.on EVENTS['phase changed'], (data)->
				socket.removeAllListeners EVENTS['phase changed']
				data = JSON.parse data

				data.should.have.property 'phase_name'
				data.phase_name.should.be.exactly 'night begin'
				resolve()

		q2 = new Promise (resolve, reject)->

			socket2.on EVENTS['phase changed'], (data)->
				socket2.removeAllListeners EVENTS['phase changed']
				data = JSON.parse data

				data.should.have.property 'phase_name'
				data.phase_name.should.be.exactly 'night begin'
				resolve()

		Promise.all [q1, q2]

	it 'should receive "mafia begin" event', ->

		q1 = new Promise (resolve, reject)->

			socket.on EVENTS['phase changed'], (data)->
				socket.removeAllListeners EVENTS['phase changed']
				data = JSON.parse data

				data.should.have.property 'phase_name'
				data.phase_name.should.be.exactly 'mafia begin'
				resolve()

		q2 = new Promise (resolve, reject)->

			socket2.on EVENTS['phase changed'], (data)->
				socket2.removeAllListeners EVENTS['phase changed']
				data = JSON.parse data

				data.should.have.property 'phase_name'
				data.phase_name.should.be.exactly 'mafia begin'
				resolve()

		Promise.all [q1, q2]



	it 'should leave room (1) and pass host to (2)', =>

		q1 = new Promise (resolve, reject)->

			socket.on EVENTS['room left'], ->
				resolve()

		q2 = new Promise (resolve, reject)=>

			socket2.on EVENTS['host changed'], (data)=>

				data = JSON.parse data
				data.should.have.property 'id'
				data.id.should.equal @player2.id
				resolve()

		socket.emit EVENTS['leave room']

		Promise.all [q1, q2]
		
	it.skip 'should reconnect (1)', (done)=>

		socket.close()

		socket = require('socket.io-client') HOST

		socket.on 'connect', =>

			data =
				reconnect_token: @player.reconnect_token

			socket.emit EVENTS['reconnect'], JSON.stringify data

			socket.on EVENTS['room joined'], (data)=>
				data = JSON.parse data

				data.room_id.should.be.equal @room_id
				data.nickname.should.be.equal @player.nickname
				done()

	it.skip 'should not reconnect (1)', (done)=>

		socket.close()

		socket = require('socket.io-client') HOST

		socket.on 'connect', =>

			data =
				reconnect_token: @player.reconnect_token

			socket.emit EVENTS['reconnect'], JSON.stringify data

			socket.on EVENTS['err'], (error)->
				done()

	it.skip 'should reconnect (2)', (done)=>

		socket2.close()

		socket2 = require('socket.io-client') HOST

		socket2.on 'connect', =>

			data =
				reconnect_token: @player.reconnect_token

			socket2.emit EVENTS['reconnect'], JSON.stringify data

			socket2.on EVENTS['room joined'], (data)=>
				data = JSON.parse data

				data.room_id.should.be.equal @room_id
				data.nickname.should.be.equal @player2.nickname
				done()

	it 'should leave room (2)', (done)->

		socket2.emit EVENTS['leave room']

		socket2.on EVENTS['room left'], ->
			done()