QT += core
QT -= gui

CONFIG += c++11

TARGET = QPAnalyzer
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0




win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPRFAccessor/release/ -lQPRFAccessor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPRFAccessor/debug/ -lQPRFAccessor
else:unix: LIBS += -L$$OUT_PWD/../QPRFAccessor/ -lQPRFAccessor

INCLUDEPATH += $$PWD/../QPRFAccessor
DEPENDPATH += $$PWD/../QPRFAccessor

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/release/ -lQPAUtilization
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAUtilization/debug/ -lQPAUtilization
else:unix: LIBS += -L$$OUT_PWD/../QPAUtilization/ -lQPAUtilization

INCLUDEPATH += $$PWD/../QPAUtilization
DEPENDPATH += $$PWD/../QPAUtilization

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAVFAccessor/release/ -lQPAVFAccessor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAVFAccessor/debug/ -lQPAVFAccessor
else:unix: LIBS += -L$$OUT_PWD/../QPAVFAccessor/ -lQPAVFAccessor

INCLUDEPATH += $$PWD/../QPAVFAccessor
DEPENDPATH += $$PWD/../QPAVFAccessor

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/release/ -lQPADissector
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPADissector/debug/ -lQPADissector
else:unix: LIBS += -L$$OUT_PWD/../QPADissector/ -lQPADissector

INCLUDEPATH += $$PWD/../QPADissector
DEPENDPATH += $$PWD/../QPADissector
