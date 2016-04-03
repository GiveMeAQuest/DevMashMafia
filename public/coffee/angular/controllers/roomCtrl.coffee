webClient.controller 'roomCtrl', ['$scope', '$rootScope', '$routeParams', '$location', '$q', 'socket', ($scope, $rootScope, $routeParams, $location, $q, socket)->

	$scope.$on '$destroy', ->
		socket.removeAllListeners 'player joined'
		socket.removeAllListeners 'player left'
		socket.removeAllListeners 'host changed'

	if !$rootScope.player?
		$location.url '/'

	$scope.loading = true

	playersInit = $q.defer()
	roomInit = $q.defer()

	$scope.room =
		id: $routeParams.id

	socket.on 'players', (players)->
		socket.removeAllListeners 'players'
		playersInit.resolve()
		$scope.players = JSON.parse players
		$scope.$apply()

	socket.on 'room', (room)->
		if typeof room is 'string' then room = JSON.parse room
		socket.removeAllListeners 'room'
		roomInit.resolve()
		$scope.room = room
		$scope.$apply()

	$q.all([playersInit.promise, roomInit.promise]).then ->
		$scope.loading = false

	socket.emit 'get waiting players', $scope.room.id
	socket.emit 'get room', $scope.room.id

	socket.on 'room left', ->
		socket.removeAllListeners 'room left'
		$location.url '/'
		$scope.$apply()

	$scope.leaveRoom = ->
		$scope.loading = true
		socket.emit 'leave room', $rootScope.player.id

	socket.on 'player joined', (player)->
		player = JSON.parse player
		$scope.players.push player
		$scope.$apply()

	socket.on 'player left', (player_id)->
		for player, i in $scope.players
			if player.id is player_id
				$scope.players.splice i, 1
				$scope.$apply()
				break

	socket.on 'host changed', (host_id)->
		$scope.room.host_id = host_id
		$scope.$apply()

]