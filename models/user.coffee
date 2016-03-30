mongoose = require 'mongoose'

UserSchema = new mongoose.Schema
	nickname:
		required: true
		type: String
	player: String

#PlayerSchema.plugin require 'mongoose-findorcreate'

User = module.exports = mongoose.model 'users', UserSchema