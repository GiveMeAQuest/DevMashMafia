webClient.factory 'socket', ['$rootScope', '$q', '$http', ($rootScope, $q, $http)->
		socketReady = $q.defer()
		configReady = $q.defer()

		CONFIG = null

		socket = io.connect()

		socket.on 'connect', ->
			socketReady.resolve()

		$http.get('/api/config').then (response)->
			CONFIG = response.data
			configReady.resolve()

		{
			on: (event, cb)->
				$q.all([socketReady.promise, configReady.promise]).then ->
					socket.on CONFIG[event], cb

			emit: (event, data)->
				$q.all([socketReady.promise, configReady.promise]).then ->
					socket.emit CONFIG[event], data

			removeAllListeners: (event)->
				socket.removeAllListeners CONFIG[event]
		}
]