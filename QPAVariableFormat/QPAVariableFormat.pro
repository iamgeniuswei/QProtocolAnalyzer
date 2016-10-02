#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T15:08:10
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAVariableFormat
TEMPLATE = lib

DEFINES += QPRFFORMAT_LIBRARY

SOURCES += \
    qpopenroutinesfactory.cpp \
    qpopenroutine.cpp \
    qpopenroutinepcap.cpp \
    wtap.cpp \
    qpavfmediator.cpp \
    qparawfilereader.cpp

HEADERS +=\
        qprfformat_global.h \
    qpopenroutinesfactory.h \
    qpopenroutine.h \
    qpopenroutinepcap.h \
    qprfvfstat.h \
    qpdefinepcap.h \
    wtap_pkthdr.h \
    qprfvfdefine.h \
    wtap.h \
    teststruct1.h \
    qpavfmediator.h \
    qparawfilereader.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CFLAGS += -std=c++11

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/release/ -lQPAUtilization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/debug/ -lQPAUtilization
else:unix: LIBS += -L$$OUT_PWD/../QPAUtilization/ -lQPAUtilization

INCLUDEPATH += $$PWD/../QPAUtilization
DEPENDPATH += $$PWD/../QPAUtilization
