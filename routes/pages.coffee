express = require 'express'
router = express.Router()

router.get '/rooms', (req, res, next)->
	res.render 'pages/rooms'

module.exports = router