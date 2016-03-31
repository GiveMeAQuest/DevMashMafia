webClient.controller 'roomCtrl', ['$scope', '$routeParams', '$q', 'socket', ($scope, $routeParams, $q, socket)->

	roomInit = $q.defer()
	playersInit = $q.defer()

	$scope.room = {}
	$scope.room.id = $routeParams.id

	socket.on 'room', (room)->
		console.log room
		$scope.room = JSON.parse room
		$scope.$apply()

	socket.on 'players', (players)->
		console.log players
		$scope.players = JSON.parse players
		$scope.$apply()

	socket.emit 'get room', $scope.room.id
	socket.emit 'get waiting players', $scope.room.id

]