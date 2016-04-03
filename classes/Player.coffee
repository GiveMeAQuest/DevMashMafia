class Player

	constructor: (data)->
		@id = data.id
		@socket_id = data.socket_id
		@room_id = data.room_id
		
		console.log "new player ID #{@id} created"

module.exports = Player