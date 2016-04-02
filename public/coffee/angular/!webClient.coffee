webClient = angular.module 'webClient', ['ngRoute', 'ui.bootstrap']

webClient.config ['$routeProvider', ($routeProvider)->
	$routeProvider

	.when '/',
		templateUrl: '/pages/index'
		controller: 'indexCtrl'

	.when '/room/create',
		templateUrl: '/pages/createRoom'
		controller: 'createRoomCtrl'

	.when '/room/:id',
		templateUrl: (params)-> "/pages/room/#{params.id}",
		controller: 'roomCtrl'

	.otherwise
		redirectTo: '/'

]