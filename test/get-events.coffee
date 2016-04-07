should = require 'should'
request = require 'request'

describe 'get events', ->
	it 'should get events list via http request', (done)->
		request.get 'http://localhost:3000/api/events', (err, response)->
			should(err).be.null()
			should(response).not.be.null()
			if typeof response.body is 'string' then response.body = JSON.parse response.body
			response.body.should.be.an.Object().and.not.be.empty()
			done()