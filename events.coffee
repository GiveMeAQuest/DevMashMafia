events = [
	'err'
	'join room'
	'room joined'
	'get waiting players'
	'waiting players'
	'leave room'
	'room left'
	'create room'
	'room created'
]

events_new = {}

ind = 0

for event in events
	events_new[event] = '' + ind++

module.exports = events_new