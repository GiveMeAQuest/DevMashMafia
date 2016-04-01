webClient = angular.module 'webClient', ['ngRoute', 'ui.bootstrap']

webClient.config ['$routeProvider', ($routeProvider)->
	$routeProvider

	.when '/',
		templateUrl: '/pages/index'
		controller: 'indexCtrl'

	.when '/room/:id',
		templateUrl: (params)-> "/pages/room/#{params.id}",
		controller: 'roomCtrl'

	.otherwise
		redirectTo: '/'

]