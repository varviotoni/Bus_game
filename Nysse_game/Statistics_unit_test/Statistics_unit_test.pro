QT += testlib
QT -= gui


CONFIG += console warn_on depend_includepath testcase
CONFIG -= app_bundle

TEMPLATE = app



SOURCES +=  tst_statistics.cpp \
    ../Game/statistics.cpp

HEADERS += \
    ../Game/statistics.hh \
    ../Course/CourseLib/interfaces/istatistics.hh


INCLUDEPATH += \
    ../Course/CourseLib \
    ../Game/
