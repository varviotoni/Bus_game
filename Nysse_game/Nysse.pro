TEMPLATE = subdirs

SUBDIRS += \
	CourseLib \
	Game \
	Statistics_unit_test

CourseLib.subdir = Course/CourseLib
Game.depends = CourseLib
