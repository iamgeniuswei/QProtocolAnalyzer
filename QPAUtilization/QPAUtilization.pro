#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T17:23:00
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAUtilization
TEMPLATE = lib

DEFINES += QPAUTILIZATION_LIBRARY

SOURCES += qpautilization.cpp \
    buffer.cpp \
    nstime.cpp

HEADERS += qpautilization.h\
        qpautilization_global.h \
    buffer.h \
    nstime.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CFLAGS += -std=c++11

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0
