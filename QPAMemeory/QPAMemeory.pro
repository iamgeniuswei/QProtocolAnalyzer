#-------------------------------------------------
#
# Project created by QtCreator 2016-10-02T11:36:37
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAMemeory
TEMPLATE = lib

DEFINES += QPAMEMEORY_LIBRARY

SOURCES += qpamemeory.cpp

HEADERS += qpamemeory.h\
        qpamemeory_global.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}
