TEMPLATE = app
TARGET = NYSSE

QT += core gui widgets network multimedia

CONFIG += c++14

HEADERS += \
    ../Course/CourseLib/actors/nysse.hh \
    ../Course/CourseLib/actors/passenger.hh \
    ../Course/CourseLib/actors/stop.hh \
    ../Course/CourseLib/core/location.hh \
    ../Course/CourseLib/core/logic.hh \
    ../Course/CourseLib/creategame.hh \
    ../Course/CourseLib/doxygeninfo.hh \
    ../Course/CourseLib/errors/gameerror.hh \
    ../Course/CourseLib/errors/initerror.hh \
    ../Course/CourseLib/graphics/simpleactoritem.hh \
    ../Course/CourseLib/graphics/simplemainwindow.hh \
    ../Course/CourseLib/interfaces/iactor.hh \
    ../Course/CourseLib/interfaces/icity.hh \
    ../Course/CourseLib/interfaces/ipassenger.hh \
    ../Course/CourseLib/interfaces/istatistics.hh \
    ../Course/CourseLib/interfaces/istop.hh \
    ../Course/CourseLib/interfaces/ivehicle.hh \
    ../Course/CourseLib/offlinereader.hh \
    alien.hh \
    city.hh \
    creategame_test.hh \
    mainwindow.hh \
    startdialog.hh \
    statistics.hh


SOURCES += \
    alien.cpp \
    city.cpp \
    creategame_test.cpp \
    main.cc\
    ../Course/CourseLib/actors/nysse.cc \
    ../Course/CourseLib/actors/passenger.cc \
    ../Course/CourseLib/actors/stop.cc \
    ../Course/CourseLib/core/location.cc \
    ../Course/CourseLib/core/logic.cc \
    ../Course/CourseLib/errors/gameerror.cc \
    ../Course/CourseLib/errors/initerror.cc \
    ../Course/CourseLib/graphics/simpleactoritem.cpp \
    ../Course/CourseLib/graphics/simplemainwindow.cpp \
    ../Course/CourseLib/offlinereader.cc \
    mainwindow.cpp \
    startdialog.cpp \
    statistics.cpp

FORMS += \
    ../Course/CourseLib/graphics/simplemainwindow.ui\
    mainwindow.ui \
    startdialog.ui

RESOURCES += \
    ../Course/CourseLib/offlinedata.qrc\


win32:CONFIG(release, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/release/ -lCourseLib
else:win32:CONFIG(debug, debug|release): LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/debug/ -lCourseLib
else:unix: LIBS += \
    -L$$OUT_PWD/../Course/CourseLib/ -lCourseLib

INCLUDEPATH += \
    $$PWD/../Course/CourseLib

DEPENDPATH += \
    $$PWD/../Course/CourseLib

win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/libCourseLib.a
else:win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/libCourseLib.a
else:win32:!win32-g++:CONFIG(release, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/release/CourseLib.lib
else:win32:!win32-g++:CONFIG(debug, debug|release): PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/debug/CourseLib.lib
else:unix: PRE_TARGETDEPS += \
    $$OUT_PWD/../Course/CourseLib/libCourseLib.a
