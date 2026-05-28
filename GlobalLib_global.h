#ifndef GLOBALLIB_GLOBAL_H
#define GLOBALLIB_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QList>

#if defined(GLOBALLIB_LIBRARY)
#define GLOBALLIB_EXPORT Q_DECL_EXPORT
#else
#define GLOBALLIB_EXPORT Q_DECL_IMPORT
#endif

const QList frequencies({1, 10, 100});

enum DataType: int {
  none = 0     /*Ошибка*/,
  acdtInt16   = 8194  /*0x2002*/,
  acdtFloat   = 8196  /*0x2004*/,
  acdtDouble  = 12288 /*0x3000*/,
  acdtUChar   = 8199  /*0x2007*/,
  acdtUInt32  = 8197  /*0x2005*/,
  acdtTime    = 12293 /*0x3005*/
}; // enum DataType

#endif // GLOBALLIB_GLOBAL_H
