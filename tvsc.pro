#-------------------------------------------------
#
# Project created by QtCreator 2014-09-27T22:33:18
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = tvsc
TEMPLATE = app


SOURCES += src/main.cpp\
        src/tvsc.cpp \
    src/tvscmodel.cpp \
    src/tvscshow.cpp \
    src/tvscepisode.cpp

HEADERS  += src/tvsc.h \
    src/tvscmodel.h \
    src/tvscshow.h \
    src/tvscepisode.h

FORMS    += ui/tvsc.ui

LIBS += -L$$PWD/../libtvdb-0.4.0-build/lib/ -ltvdb

INCLUDEPATH += $$PWD/../libtvdb-0.4.0
INCLUDEPATH += /usr/include/kde4
DEPENDPATH += $$PWD/../libtvdb-0.4.0
