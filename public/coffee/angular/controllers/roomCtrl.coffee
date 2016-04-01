webClient.controller 'roomCtrl', ['$scope', '$rootScope', '$routeParams', '$q', '$location', 'socket', ($scope, $rootScope, $routeParams, $q, $location, socket)->

	if !$rootScope.player?
		$location.url '/'

	roomInit = $q.defer()
	playersInit = $q.defer()
	$scope.loading = true

	$q.all([roomInit.promise, playersInit.resolve]).then ->
		$scope.loading = false

	$scope.room = {}
	$scope.room.id = $routeParams.id

	socket.on 'room', (room)->
		roomInit.resolve()
		$scope.room = JSON.parse room
		$scope.$apply()

	socket.on 'players', (players)->
		playersInit.resolve()
		$scope.players = JSON.parse players
		$scope.$apply()

	socket.emit 'get room', $scope.room.id
	socket.emit 'get waiting players', $scope.room.id

	socket.on 'room left', ->
			socket.removeAllListeners 'room left'
			$location.url '/'
			$scope.$apply()

	$scope.leaveRoom = ->
		$scope.loading = true
		socket.emit 'leave room', $rootScope.player.id

]