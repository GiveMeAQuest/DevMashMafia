uuid = require 'uuid'

class Player

	constructor: (params)->
		for k of params
			this[k] = params[k]
		@reconnect_token = uuid.v4()
		@online = true

		console.log "new player ID #{@id} created"

module.exports = Player