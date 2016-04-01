webClient.controller 'roomCtrl', ['$scope', '$rootScope', '$routeParams', '$location', 'socket', ($scope, $rootScope, $routeParams, $location, socket)->

	if !$rootScope.player?
		$location.url '/'

	$scope.loading = true

	$scope.roomid = $routeParams.id

	socket.on 'players', (players)->
		$scope.loading = false
		$scope.players = JSON.parse players
		$scope.$apply()

	socket.emit 'get waiting players', $scope.roomid

	socket.on 'room left', ->
			socket.removeAllListeners 'room left'
			$location.url '/'
			$scope.$apply()

	$scope.leaveRoom = ->
		$scope.loading = true
		socket.emit 'leave room', $rootScope.player.id

]