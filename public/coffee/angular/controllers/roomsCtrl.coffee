webClient.controller 'roomsCtrl', ['$scope', '$location', '$uibModal', 'socket', ($scope, $location, $uibModal, socket)->

	$scope.loading = true

	socket.on 'rooms', (rooms)->
		$scope.rooms = JSON.parse rooms
		$scope.loading = false
		$scope.$apply()

	socket.emit 'get rooms'

	$scope.joinRoom = (room)->
		authModal = $uibModal.open
			templateUrl: 'authModal'
			controller: 'authModalCtrl'
			size: 'sm'
			resolve:
				title: -> room.name

		do(room)->
			authModal.result.then (nickname)->

				socket.on 'logged', ->
					$location.url "/room/#{room.id}"
					$scope.$apply()

				socket.emit 'login',
					nickname: nickname
					room_id: room.id

]

webClient.controller 'authModalCtrl', ['$scope', '$uibModalInstance', 'title', ($scope, $uibModalInstance, title)->

	$scope.title = title

	$scope.ok = ->
		$uibModalInstance.close $scope.nickname

]