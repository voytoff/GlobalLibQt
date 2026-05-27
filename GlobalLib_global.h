#ifndef GLOBALLIB_GLOBAL_H
#define GLOBALLIB_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(GLOBALLIB_LIBRARY)
#define GLOBALLIB_EXPORT Q_DECL_EXPORT
#else
#define GLOBALLIB_EXPORT Q_DECL_IMPORT
#endif

#endif // GLOBALLIB_GLOBAL_H
