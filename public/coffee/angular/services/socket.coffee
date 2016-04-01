webClient.factory 'socket', ['$rootScope', '$q', '$http', ($rootScope, $q, $http)->
		socketReady = $q.defer()
		eventReady = $q.defer()

		EVENTS = null

		socket = io.connect()

		socket.on 'connect', ->
			socketReady.resolve()

		$http.get('/api/events').then (response)->
			EVENTS = response.data
			eventReady.resolve()

		{
			on: (event, cb)->
				$q.all([socketReady.promise, eventReady.promise]).then ->
					socket.on EVENTS[event], cb

			emit: (event, data)->
				$q.all([socketReady.promise, eventReady.promise]).then ->
					socket.emit EVENTS[event], data

			removeAllListeners: (event)->
				socket.removeAllListeners EVENTS[event]
		}
]