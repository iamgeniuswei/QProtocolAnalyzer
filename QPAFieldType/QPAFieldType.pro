#-------------------------------------------------
#
# Project created by QtCreator 2016-10-02T18:46:18
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAFieldType
TEMPLATE = lib

DEFINES += QPAFIELDTYPE_LIBRARY

SOURCES += qpafieldtype.cpp \
    ftypes.cpp \
    ftype-bytes.cpp

HEADERS += qpafieldtype.h\
        qpafieldtype_global.h \
    ftypes.h \
    ft_structtest.h \
    ftypes-int.h

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
