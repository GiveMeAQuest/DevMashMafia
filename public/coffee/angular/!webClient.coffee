webClient = angular.module 'webClient', ['ngRoute']

webClient.config ['$routeProvider', ($routeProvider)->
	$routeProvider

	.when '/',
		templateUrl: '/pages/rooms'
		controller: 'roomsCtrl'

	.when '/room/:id',
		templateUrl: '/pages/room',
		controller: 'roomCtrl'

	.otherwise
		redirectTo: '/'

]