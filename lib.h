#ifndef LIB_H
#define LIB_H

#include "GlobalLib_global.h"
#include "parameter.h"
#include <QString>
#include <QStringList>

namespace lib {
GLOBALLIB_EXPORT int endsWith(QStringList list, QString value);
GLOBALLIB_EXPORT double round(double value, int digits);
GLOBALLIB_EXPORT double avg(QList<double> array);
GLOBALLIB_EXPORT double avg(QList<Parameter*> mid);
GLOBALLIB_EXPORT double increment(int persecond, double &index, int digits = 3);
GLOBALLIB_EXPORT QDateTime toDate(const QByteArray &data);
GLOBALLIB_EXPORT QDateTime toOleTime(const QByteArray &data);
GLOBALLIB_EXPORT double toDouble(const QByteArray &data);
GLOBALLIB_EXPORT float toFloat(const QByteArray &data);
};

#endif // LIB_H
