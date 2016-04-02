webClient.controller 'createRoomCtrl', ['$scope', '$rootScope', '$location', 'socket', ($scope, $rootScope, $location, socket)->

	$scope.formData = {}
	$scope.formData.players = 5

	$scope.back = ->
		$scope.loading = true
		$location.url '/'

	socket.on 'room joined', (player)->
		socket.removeAllListeners 'room joined'
		player = JSON.parse player
		$rootScope.player = player
		$location.url "/room/#{player.room_id}"
		$scope.$apply()

	socket.on 'room created', (id)->
		socket.removeAllListeners 'room created'
		socket.emit 'join room',
			nickname: $scope.formData.nickname
			room_id: id

	$scope.createRoom = ->
		$scope.loading = true
		socket.emit 'create room',
			players: $scope.formData.players
			customRoles: $scope.formData.customRoles

]