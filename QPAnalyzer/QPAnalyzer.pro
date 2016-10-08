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

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAFileAccessor/release/ -lQPAFileAccessor
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAFileAccessor/debug/ -lQPAFileAccessor
else:unix: LIBS += -L$$OUT_PWD/../QPAFileAccessor/ -lQPAFileAccessor

INCLUDEPATH += $$PWD/../QPAFileAccessor
DEPENDPATH += $$PWD/../QPAFileAccessor

win32:CONFIG(release, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/release/ -lQPAMemeory
else:win32:CONFIG(debug, debug|release): LIBS += -L$$OUT_PWD/../QPAMemeory/debug/ -lQPAMemeory
else:unix: LIBS += -L$$OUT_PWD/../QPAMemeory/ -lQPAMemeory

INCLUDEPATH += $$PWD/../QPAMemeory
DEPENDPATH += $$PWD/../QPAMemeory

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
