events = [
	'err'
	'join room'
	'room joined'
	'get waiting players'
	'players'
	'leave room'
	'room left'
	'create room'
	'room created'
	'player joined'
	'get room'
	'room'
	'player left'
]

events_new = {}

ind = 0

for event in events
	events_new[event] = '' + ind++

module.exports = events_new