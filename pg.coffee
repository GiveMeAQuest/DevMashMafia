pg = require 'pg'

pg.defaults.ssl = true

module.exports =

	query: (query, cb)->
		pg.connect 'postgres://phiyolxqlfoajb:qQ_7ulpwRpzFy71fazVzr6XO2q@ec2-54-235-199-36.compute-1.amazonaws.com:5432/d7mks99df261gc' or process.env.DATABASE_URL, (err, client, done)->
			if err then throw err
			#console.log 'PG:', query
			client.query query, (err, result)->
				if err
					console.log 'PG error:', err
					cb? null, err.detail
				else
					cb? result
				done()