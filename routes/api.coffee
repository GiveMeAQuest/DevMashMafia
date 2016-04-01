express = require 'express'
pg = require '../pg'
EVENTS = require '../events'
router = express.Router()

router.get '/events', (req, res, next)->
	res.end JSON.stringify EVENTS

module.exports = router