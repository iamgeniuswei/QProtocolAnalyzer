#ifndef QPAMEMEORY_GLOBAL_H
#define QPAMEMEORY_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPAMEMEORY_LIBRARY)
#  define QPAMEMEORYSHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPAMEMEORYSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPAMEMEORY_GLOBAL_H
