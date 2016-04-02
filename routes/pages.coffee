express = require 'express'
router = express.Router()

router.get '/index', (req, res, next)->
	res.render 'pages/index'

router.get '/room/:id', (req, res, next)->
	res.render 'pages/room'

router.get '/createRoom', (req, res, next)->
	res.render 'pages/createRoom'

module.exports = router