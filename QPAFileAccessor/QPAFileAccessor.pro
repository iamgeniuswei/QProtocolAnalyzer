#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T11:13:40
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAFileAccessor
TEMPLATE = lib

DEFINES += QPRFACCESSOR_LIBRARY

SOURCES += \
    qpafileaccessor.cpp

HEADERS +=\
        qprfaccessor_global.h \
    qpacapturefile.h \
    qpafileaccessor.h

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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/release/ -lQPADissector
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/debug/ -lQPADissector
else:unix: LIBS += -L$$OUT_PWD/../QPADissector/ -lQPADissector

INCLUDEPATH += $$PWD/../QPADissector
DEPENDPATH += $$PWD/../QPADissector



win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAVariableFormat/release/ -lQPAVariableFormat
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAVariableFormat/debug/ -lQPAVariableFormat
else:unix: LIBS += -L$$OUT_PWD/../QPAVariableFormat/ -lQPAVariableFormat

INCLUDEPATH += $$PWD/../QPAVariableFormat
DEPENDPATH += $$PWD/../QPAVariableFormat

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/release/ -lQPADissector
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/debug/ -lQPADissector
else:unix: LIBS += -L$$OUT_PWD/../QPADissector/ -lQPADissector

INCLUDEPATH += $$PWD/../QPADissector
DEPENDPATH += $$PWD/../QPADissector

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPACore/release/ -lQPACore
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPACore/debug/ -lQPACore
else:unix: LIBS += -L$$OUT_PWD/../QPACore/ -lQPACore

INCLUDEPATH += $$PWD/../QPACore
DEPENDPATH += $$PWD/../QPACore

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAFieldType/release/ -lQPAFieldType
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAFieldType/debug/ -lQPAFieldType
else:unix: LIBS += -L$$OUT_PWD/../QPAFieldType/ -lQPAFieldType

INCLUDEPATH += $$PWD/../QPAFieldType
DEPENDPATH += $$PWD/../QPAFieldType

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/release/ -lQPAMemeory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/debug/ -lQPAMemeory
else:unix: LIBS += -L$$OUT_PWD/../QPAMemeory/ -lQPAMemeory

INCLUDEPATH += $$PWD/../QPAMemeory
DEPENDPATH += $$PWD/../QPAMemeory
