express = require 'express'
pg = require '../pg'
router = express.Router()

router.get '/user/:id', (req, res, next)->
	pg.query "SELECT players.id, players.nickname, players.state, rooms.name AS room, roles.name AS role FROM players, rooms, roles WHERE players.id=#{req.params.id} AND players.room_id=rooms.id AND players.role_id=roles.id;", (result)->
		res.end JSON.stringify result.rows[0]

router.get '/rooms', (req, res, next)->
	pg.query "SELECT rooms.id, rooms.name, phases.name AS phase FROM rooms, phases WHERE rooms.phase_id=phases.id;", (result)->
		res.end JSON.stringify result.rows

router.get '/room/:id', (req, res, next)->
	pg.query "SELECT rooms.id, rooms.name, phases.name AS phase FROM rooms, phases WHERE rooms.id=#{req.params.id} AND rooms.phase_id=phases.id;", (result)->
		res.end JSON.stringify result.rows[0]

module.exports = router