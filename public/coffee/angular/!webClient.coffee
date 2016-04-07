webClient = angular.module 'webClient', ['ngRoute', 'ui.bootstrap', 'ngStorage']

webClient.config ['$routeProvider', ($routeProvider)->
	$routeProvider

	.when '/',
		templateUrl: '/pages/index'
		controller: 'indexCtrl'

	.when '/new',
		templateUrl: '/pages/createRoom'
		controller: 'createRoomCtrl'

	.when '/lobby',
		templateUrl: "/pages/room"
		controller: 'roomCtrl'

	.otherwise
		redirectTo: '/'

]

webClient.run ['$rootScope', '$localStorage', ($rootScope, $localStorage)->

	$rootScope.$storage = $localStorage

]