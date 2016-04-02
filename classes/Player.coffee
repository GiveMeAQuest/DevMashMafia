class Player

	constructor: (@id, @socket_id)->
		console.log "new player ID #{@id} created"

module.exports = Player