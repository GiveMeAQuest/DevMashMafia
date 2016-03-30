mongoose = require 'mongoose'

PhaseSchema = new mongoose.Schema
	name:
		required: true
		type: String

#PlayerSchema.plugin require 'mongoose-findorcreate'

Phase = module.exports = mongoose.model 'phases', PhaseSchema