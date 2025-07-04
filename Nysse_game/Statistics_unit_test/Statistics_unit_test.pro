QT += testlib
QT -= gui

TARGET = tst_statistics
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

DEFINES += SRCDIR=\\\"$$PWD/\\\"

SOURCES +=  tst_statistics.cpp \
    ../Game/statistics.cpp



HEADERS += \
    ../Game/statistics.hh \
    ../Course/CourseLib/interfaces/istatistics.hh
