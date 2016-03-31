webClient.controller 'roomCtrl', ['$scope', '$rootScope', '$routeParams', '$q', 'socket', ($scope, $rootScope, $routeParams, $q, socket)->

	if !$rootScope.player?
		$location.url '/'

	roomInit = $q.defer()
	playersInit = $q.defer()

	$scope.room = {}
	$scope.room.id = $routeParams.id

	socket.on 'room', (room)->
		$scope.room = JSON.parse room
		$scope.$apply()

	socket.on 'players', (players)->
		$scope.players = JSON.parse players
		$scope.$apply()

	socket.emit 'get room', $scope.room.id
	socket.emit 'get waiting players', $scope.room.id

	socket.on 'room left', ->
			$location.url '/'
			$scope.$apply()

	$scope.leaveRoom = ->
		socket.emit 'leave room', $rootScope.player.id

]