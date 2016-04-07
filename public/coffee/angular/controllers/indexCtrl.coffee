webClient.controller 'indexCtrl', ['$scope', '$rootScope', '$q', '$location', 'socket', ($scope, $rootScope, $q, $location, socket)->

	loadInit = $q.defer()

	if $rootScope.player?
		if $rootScope.$storage.reconnect_token?
			socket.on 'err', (error)->
				loadInit.resolve()
			socket.emit 'reconnect', $rootScope.$storage.reconnect_token
		else
			delete $rootScope.player

	formData = {}

	socket.on 'room joined', (room_id)->
		$location.url '/lobby'

	$scope.joinRoom = ->


]