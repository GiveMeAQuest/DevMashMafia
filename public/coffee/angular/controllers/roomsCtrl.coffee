webClient.controller 'roomsCtrl', ['$scope', '$location', 'socket', ($scope, $location, socket)->

	$scope.loading = true

	socket.on 'rooms', (rooms)->
		$scope.rooms = JSON.parse rooms
		$scope.loading = false
		$scope.$apply()

	socket.emit 'get rooms'

	$scope.joinRoom = (room)->
		$location.url "/room/#{room.id}"

]