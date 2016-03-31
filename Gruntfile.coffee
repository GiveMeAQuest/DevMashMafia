module.exports = (grunt)->
	grunt.initConfig
		pkg: grunt.file.readJSON 'package.json'

		cssmin:
			css:
				options:
					shorthandCompacting: false
					roundingPrecision: -1
				src: ['public/css/*.css', '!public/css/all.css']
				dest: 'public/css/all.css'
				
		coffee:
			compile:
				expand: true
				cwd: 'public/coffee'
				src: '**/*.coffee'
				dest: 'public/js/compiled'
				ext: '.js'
				flatten: true
				options:
					bare: true
		
		uglify:
			minify:
				src: 'public/js/compiled/*.js'
				dest: 'public/js/all_compiled.js'
				options:
					bare: true
		
		concat:
			addSource:
				src: ['public/js/source/*.js', 'public/js/all.js']
				dest: 'public/js/all.js'
				options:
					bare: true
			full:
				src: ['public/js/source/*.js', 'public/js/compiled/*.js']
				dest: 'public/js/all.js'
				options:
					bare: true

		clean: ['public/js/compiled']

		watch:
			self:
				files: ['Gruntfile.coffee']
			coffee:
				files: ['public/**/*.coffee']
				tasks: ['js']
			js:
				files: ['public/**/*.js', '!public/js/compiled/*.js', '!public/js/all.js']
				tasks: ['js']
			css:
				files: ['public/css/**/*.css', '!public/css/all.css']
				tasks: ['css']

	grunt.loadNpmTasks 'grunt-contrib-coffee'
	grunt.loadNpmTasks 'grunt-contrib-uglify'
	grunt.loadNpmTasks 'grunt-contrib-clean'
	grunt.loadNpmTasks 'grunt-contrib-concat'
	grunt.loadNpmTasks 'grunt-contrib-cssmin'
	grunt.loadNpmTasks 'grunt-contrib-watch'
	grunt.registerTask 'default', ['cssmin', 'coffee', 'uglify', 'concat:addSource', 'clean']
	grunt.registerTask 'js', ['coffee', 'concat:full', 'clean']
	grunt.registerTask 'css', 'cssmin'