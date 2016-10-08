#-------------------------------------------------
#
# Project created by QtCreator 2016-10-08T09:50:47
#
#-------------------------------------------------

QT       -= gui

TARGET = QPACore
TEMPLATE = lib

DEFINES += QPACORE_LIBRARY

SOURCES += qpacore.cpp \
    packet.cpp \
    column-info.cpp \
    frame_data_sequence.cpp \
    frame_data.cpp \
    tvbuff.cpp \
    proto.cpp \
    frame_tvbuff.cpp

HEADERS += qpacore.h\
        qpacore_global.h \
    packet.h \
    column-info.h \
    frame_data_sequence.h \
    frame_data.h \
    tvbuff.h \
    epan_dissect.h \
    proto.h \
    packet_info.h \
    epan-int.h \
    address.h \
    frame_tvbuff.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CFLAGS += -std=c++11

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAVariableFormat/release/ -lQPAVariableFormat
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAVariableFormat/debug/ -lQPAVariableFormat
else:unix: LIBS += -L$$OUT_PWD/../QPAVariableFormat/ -lQPAVariableFormat

INCLUDEPATH += $$PWD/../QPAVariableFormat
DEPENDPATH += $$PWD/../QPAVariableFormat

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/release/ -lQPAUtilization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/debug/ -lQPAUtilization
else:unix: LIBS += -L$$OUT_PWD/../QPAUtilization/ -lQPAUtilization

INCLUDEPATH += $$PWD/../QPAUtilization
DEPENDPATH += $$PWD/../QPAUtilization

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/release/ -lQPAMemeory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/debug/ -lQPAMemeory
else:unix: LIBS += -L$$OUT_PWD/../QPAMemeory/ -lQPAMemeory

INCLUDEPATH += $$PWD/../QPAMemeory
DEPENDPATH += $$PWD/../QPAMemeory

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/release/ -lQPADissector
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/debug/ -lQPADissector
else:unix: LIBS += -L$$OUT_PWD/../QPADissector/ -lQPADissector

INCLUDEPATH += $$PWD/../QPADissector
DEPENDPATH += $$PWD/../QPADissector

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAFieldType/release/ -lQPAFieldType
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAFieldType/debug/ -lQPAFieldType
else:unix: LIBS += -L$$OUT_PWD/../QPAFieldType/ -lQPAFieldType

INCLUDEPATH += $$PWD/../QPAFieldType
DEPENDPATH += $$PWD/../QPAFieldType
