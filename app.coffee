require 'coffee-script/register'
require 'coffee-script'
express = require 'express'
path = require 'path'
favicon = require 'serve-favicon'
logger = require 'morgan'
cookieParser = require 'cookie-parser'
bodyParser = require 'body-parser'
http = require 'http'
pg = require './pg'

routes = require './routes/index'
api = require './routes/api'
pages = require './routes/pages'

app = express()

# view engine setup
app.set 'views', path.join __dirname, 'views'
app.set 'view engine', 'jade'

# uncomment after placing your favicon in /public
#app.use(favicon(path.join(__dirname, 'public', 'favicon.ico')));
app.use logger 'dev'
app.use bodyParser.json()
app.use bodyParser.urlencoded extended: false
app.use cookieParser()
app.use express.static path.join __dirname, 'public'

app.use (err, req, res, next)->
	if req.ip is '89.22.47.142'
		res.end()

app.use '/', routes
app.use '/api', api
app.use '/pages', pages

# catch 404 and forward to error handler
app.use (req, res, next)->
	err = new Error 'Not Found'
	err.status = 404
	next err

# error handlers
# development error handler
# will print stacktrace
if app.get 'env' is 'development'
	app.use (err, req, res, next)->
		res.status err.status or 500
		res.render 'error',
			message: err.message
			error: err

# production error handler
# no stacktraces leaked to user
app.use (err, req, res, next)->
	res.status err.status or 500
	res.render 'error',
		message: err.message
		error: {}

module.exports = app

app.set 'port', process.env.PORT or 3000
server = http.createServer app
server.listen app.get 'port'
server.on 'listening', ->
	console.log 'Server running on port ' + app.get 'port'

socket = require('./socket')(server)