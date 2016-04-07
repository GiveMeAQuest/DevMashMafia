pg = require 'pg'

pg.defaults.ssl = true

module.exports =

	query: (query, cb)->
		pg.connect process.env.DATABASE_URL, (err, client, done)->
			if err then throw err
			client.query query, (err, result)->
				if err
					console.log 'PG error:', err
					cb? null, err.detail
				else
					cb? result
				done()