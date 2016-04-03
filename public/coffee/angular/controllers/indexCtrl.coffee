webClient.controller 'indexCtrl', ['$scope', '$rootScope', '$location', 'socket', ($scope, $rootScope, $location, socket)->

	$scope.$on '$destroy', ->
		socket.removeAllListeners 'err'

	socket.on 'err', (error)->
		$scope.loading = false
		$scope.error = error
		$scope.$apply()

	socket.on 'room joined', (player)->
		socket.removeAllListeners 'room joined'
		if typeof player is 'string' then player = JSON.parse player
		$rootScope.player = player
		$location.url "/room/#{player.room_id}"
		$scope.$apply()

	$scope.joinRoom = (valid)->
		if not valid
			$scope.error = 'Some fields are incorrectly filled!'
			return
			
		$scope.loading = true

		socket.emit 'join room',
			nickname: $scope.nickname
			room_id: $scope.room_id

	$scope.createRoom = ->
		$scope.loading = true
		$location.url '/room/create'

]