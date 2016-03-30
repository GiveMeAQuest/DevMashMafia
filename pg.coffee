pg = require 'pg'

pg.defaults.ssl = true

module.exports =

	query: (query, cb)->
		pg.connect process.env.DATABASE_URL, (err, client, done)->
			if err then throw err
			client.query query, (err, result)->
				if err then throw err
				cb result