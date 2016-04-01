events = [
	'err'
	'login'
	'logged'
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