commands = [
	'err'
	'login'
	'logged'
	'get waiting players'
	'waiting players'
	'leave room'
	'room left'
]

commands_new = {}

ind = 0

for command in commands
	commands_new[command] = '' + ind++

module.exports = commands_new