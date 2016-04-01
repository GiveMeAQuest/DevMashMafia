webClient.controller 'roomsCtrl', ['$scope', '$rootScope', '$location', '$uibModal', '$uibModalStack', 'socket', ($scope, $rootScope, $location, $uibModal, $uibModalStack, socket)->

	$scope.loading = true



	socket.on 'rooms', (rooms)->
		$scope.rooms = JSON.parse rooms
		$scope.loading = false
		$scope.$apply()

	socket.emit 'get rooms'

	socket.on 'err', (error)->
		socket.removeAllListeners 'error'

		$uibModalStack.dismissAll()

		$scope.loading = false

		errModal = $uibModal.open
			templateUrl: 'errorModal'
			controller: 'errorModalCtrl'
			size: 'sm'
			resolve:
				error: -> error

	$scope.joinRoom = (room)->
		authModal = $uibModal.open
			templateUrl: 'authModal'
			controller: 'authModalCtrl'
			size: 'sm'
			resolve:
				title: -> room.name

		do(room)->
			authModal.result.then (nickname)->

				$scope.loading = true

				socket.on 'logged', (player)->
					socket.removeAllListeners 'logged'
					if typeof player is 'string' then player = JSON.parse player
					console.log player
					$rootScope.player = player
					$location.url "/room/#{room.id}"
					$scope.$apply()

				socket.emit 'login',
					nickname: nickname
					room_id: room.id

	$scope.createRoom = ->
		createRoomModal = $uibModal.open
			templateUrl: 'createRoomModal'
			controller: 'createRoomModalCtrl'
			size: 'sm'
		
		createRoomModal.result.then (name)->
			$scope.loading = true

			socket.emit 'create room',
				name: name				

]

webClient.controller 'authModalCtrl', ['$scope', '$uibModalInstance', 'title', ($scope, $uibModalInstance, title)->

	$scope.title = title

	$scope.ok = ->
		$uibModalInstance.close $scope.nickname

]

webClient.controller 'errorModalCtrl', ['$scope', '$uibModalInstance', 'error', ($scope, $uibModalInstance, error)->

	$scope.error = error

	$scope.ok = $uibModalInstance.close

]