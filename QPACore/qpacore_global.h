#ifndef QPACORE_GLOBAL_H
#define QPACORE_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(QPACORE_LIBRARY)
#  define QPACORESHARED_EXPORT Q_DECL_EXPORT
#else
#  define QPACORESHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // QPACORE_GLOBAL_H
