events_list = [
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
	'player left'
	'get room'
	'room'
	'host changed'
	'reconnect'
	'start game'
	'phase changed'
	'role'
	'mafia vote'
	'sheriff vote'
	'sheriff info'
	'killed'
	'citizen vote'
	'doctor vote'
	'prostitute vote'
	'arrested'
	'end game'
]

events = {}

ind = 0

for event in events_list
	events[event] = '' + ind++

module.exports = events