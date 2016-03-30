mongoose = require 'mongoose'

PhraseSchema = new mongoose.Schema
	text:
		required: true
		type: String
	phase:
		required: true
		type: String

#PlayerSchema.plugin require 'mongoose-findorcreate'

Player = module.exports = mongoose.model 'players', PlayerSchema