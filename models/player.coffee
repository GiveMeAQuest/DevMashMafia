mongoose = require 'mongoose'

PlayerSchema = new mongoose.Schema
	nickname:
		required: true
		type: String
	room:
		required: true
		type: String
	role:
		required: true
		type: String
	status:
		required: true
		type: Number

#PlayerSchema.plugin require 'mongoose-findorcreate'

Player = module.exports = mongoose.model 'players', PlayerSchema