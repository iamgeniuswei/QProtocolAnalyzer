#-------------------------------------------------
#
# Project created by QtCreator 2016-10-02T11:36:37
#
#-------------------------------------------------

QT       -= gui

TARGET = QPAMemeory
TEMPLATE = lib

DEFINES += QPAMEMEORY_LIBRARY

SOURCES += qpamemeory.cpp \
    wmem_core.cpp \
    wmem_user_cb.cpp \
    wmem_allocator_simple.cpp \
    wmem_allocator_block.cpp \
    wmem_allocator_block_fast.cpp \
    wmem_allocator_strict.cpp \
    wmem_scopes.cpp \
    wmem_map.cpp \
    wmem_array.cpp \
    wmem_list.cpp \
    wmem_stack.cpp \
    wmem_tree.cpp \
    wmem_strutl.cpp \
    wmem_strbuf.cpp \
    wmem_miscutl.cpp

HEADERS += qpamemeory.h\
        qpamemeory_global.h \
    wmem_core.h \
    wmem_allocator.h \
    wmem_user_cb.h \
    wmem_allocator_simple.h \
    wmem_allocator_block.h \
    wmem_allocator_block_fast.h \
    wmem_allocator_strict.h \
    wmem_scopes.h \
    wmem_map.h \
    wmem_array.h \
    wmem_list.h \
    wmem_queue.h \
    wmem_stack.h \
    wmem_tree.h \
    wmem_strutl.h \
    wmem_strbuf.h \
    wmem_miscutl.h \
    wmem.h

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CFLAGS += -std=c++11

INCLUDEPATH += /usr/include/glib-2.0
INCLUDEPATH += /usr/lib64/glib-2.0/include
LIBS += -lglib-2.0
