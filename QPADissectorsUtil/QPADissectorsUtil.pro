#-------------------------------------------------
#
# Project created by QtCreator 2016-10-02T19:00:50
#
#-------------------------------------------------

QT       -= gui

TARGET = QPADissectorsUtil
TEMPLATE = lib

DEFINES += QPADISSECTORSUTIL_LIBRARY

SOURCES += qpadissectorsutil.cpp \
    ipv4.cpp \
    to_str.cpp \
    addr_and_mask.cpp \
    address.cpp \
    tvbuff.cpp \
    guid-utils.cpp

HEADERS += qpadissectorsutil.h\
        qpadissectorsutil_global.h \
    ipv4.h \
    to_str.h \
    addr_and_mask.h \
    address.h \
    tvbuff.h \
    time_fmt.h \
    guid-utils.h \
    ipv6-utils.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CFLAGS += -std=c++11

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0


win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/release/ -lQPAMemeory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/debug/ -lQPAMemeory
else:unix: LIBS += -L$$OUT_PWD/../QPAMemeory/ -lQPAMemeory

INCLUDEPATH += $$PWD/../QPAMemeory
DEPENDPATH += $$PWD/../QPAMemeory

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/release/ -lQPAUtilization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/debug/ -lQPAUtilization
else:unix: LIBS += -L$$OUT_PWD/../QPAUtilization/ -lQPAUtilization

INCLUDEPATH += $$PWD/../QPAUtilization
DEPENDPATH += $$PWD/../QPAUtilization
