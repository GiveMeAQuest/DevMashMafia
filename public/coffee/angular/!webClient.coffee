webClient = angular.module 'webClient', ['ngRoute', 'ui.bootstrap']

webClient.config ['$routeProvider', ($routeProvider)->
	$routeProvider

	.when '/',
		templateUrl: '/pages/rooms'
		controller: 'roomsCtrl'

	.when '/room/:id',
		templateUrl: (params)-> "/pages/room/#{params.id}",
		controller: 'roomCtrl'

	.otherwise
		redirectTo: '/'

]