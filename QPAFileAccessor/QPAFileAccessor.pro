#-------------------------------------------------
#
# Project created by QtCreator 2016-09-29T11:13:40
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAFileAccessor
TEMPLATE = lib

DEFINES += QPRFACCESSOR_LIBRARY

SOURCES += qprfaccessor.cpp \
    qpfileaccessor.cpp \
    wtap_pkthdr.cpp

HEADERS += qprfaccessor.h\
        qprfaccessor_global.h \
    teststruct.h \
    qpfileaccessor.h \
    qpfileaccessstat.h \
    qpfilestat.h

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
