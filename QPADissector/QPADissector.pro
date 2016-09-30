#-------------------------------------------------
#
# Project created by QtCreator 2016-09-30T10:01:05
#
#-------------------------------------------------

QT       -= gui

TARGET = QPADissector
TEMPLATE = lib

DEFINES += QPADISSECTOR_LIBRARY

SOURCES += qpadissector.cpp \
    frame_data.cpp \
    frame_data_sequence.cpp

HEADERS += qpadissector.h\
        qpadissector_global.h \
    frame_data.h \
    frame_data_sequence.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/release/ -lQPAUtilization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/debug/ -lQPAUtilization
else:unix: LIBS += -L$$OUT_PWD/../QPAUtilization/ -lQPAUtilization

INCLUDEPATH += $$PWD/../QPAUtilization
DEPENDPATH += $$PWD/../QPAUtilization

QMAKE_CFLAGS += -std=c++11

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAVFAccessor/release/ -lQPAVFAccessor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAVFAccessor/debug/ -lQPAVFAccessor
else:unix: LIBS += -L$$OUT_PWD/../QPAVFAccessor/ -lQPAVFAccessor

INCLUDEPATH += $$PWD/../QPAVFAccessor
DEPENDPATH += $$PWD/../QPAVFAccessor
