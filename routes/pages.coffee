express = require 'express'
router = express.Router()

router.get '/rooms', (req, res, next)->
	res.render 'pages/rooms'

router.get '/room/:id', (req, res, next)->
	res.render 'pages/room'

module.exports = router