webClient.controller 'indexCtrl', ['$scope', '$location', 'socket', ($scope, $location, socket)->

	$scope.joinRoom = ->
		socket.on 'room joined', (roomid)->
			$scope.loading = true
			$location.url "/room/#{roomid}"

		socket.emit 'join room',
			nickname: $scope.nickname
			room_id: $scope.room_id

]