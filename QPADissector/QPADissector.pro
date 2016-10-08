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
    packet-frame.cpp

HEADERS += qpadissector.h\
        qpadissector_global.h \
    packet-frame.h \
    define.h \
    time_fmt.h

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAFieldType/release/ -lQPAFieldType
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAFieldType/debug/ -lQPAFieldType
else:unix: LIBS += -L$$OUT_PWD/../QPAFieldType/ -lQPAFieldType

INCLUDEPATH += $$PWD/../QPAFieldType
DEPENDPATH += $$PWD/../QPAFieldType

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPACore/release/ -lQPACore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPACore/debug/ -lQPACore
else:unix: LIBS += -L$$OUT_PWD/../QPACore/ -lQPACore

INCLUDEPATH += $$PWD/../QPACore
DEPENDPATH += $$PWD/../QPACore

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAVariableFormat/release/ -lQPAVariableFormat
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAVariableFormat/debug/ -lQPAVariableFormat
else:unix: LIBS += -L$$OUT_PWD/../QPAVariableFormat/ -lQPAVariableFormat

INCLUDEPATH += $$PWD/../QPAVariableFormat
DEPENDPATH += $$PWD/../QPAVariableFormat

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/release/ -lQPAMemeory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/debug/ -lQPAMemeory
else:unix: LIBS += -L$$OUT_PWD/../QPAMemeory/ -lQPAMemeory

INCLUDEPATH += $$PWD/../QPAMemeory
DEPENDPATH += $$PWD/../QPAMemeory
