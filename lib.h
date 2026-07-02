#ifndef LIB_H
#define LIB_H

#include "GlobalLib_global.h"
#include "parameter.h"
#include <QString>
#include <QStringList>
#include <QList>

namespace lib {
template <typename T>
GLOBALLIB_EXPORT int indexOf(QList<T*> list, std::function<bool (const T *)> &predicate) {
  auto it = std::find_if(list.begin(), list.end(), predicate);
  return (it != list.end()) ? std::distance(list.begin(), it) : -1;
}
template <typename T>
GLOBALLIB_EXPORT T* find(QList<T*> list, std::function<bool (const T *)> &predicate) {
  auto it = std::find_if(list.begin(), list.end(), predicate);
  return it.value();
}
GLOBALLIB_EXPORT int endsWith(QStringList list, QString value);
GLOBALLIB_EXPORT double round(double value, int digits);
GLOBALLIB_EXPORT double avg(QList<double> array);
GLOBALLIB_EXPORT double avg(QList<Parameter*> mid);
GLOBALLIB_EXPORT double increment(int persecond, double &index, int digits = 3);
GLOBALLIB_EXPORT QString &trim(QString &text);
GLOBALLIB_EXPORT QDateTime toDate(const QByteArray &data);
GLOBALLIB_EXPORT QDateTime toOleTime(const QByteArray &data);
GLOBALLIB_EXPORT double toDouble(const QByteArray &data);
GLOBALLIB_EXPORT float toFloat(const QByteArray &data);
GLOBALLIB_EXPORT int toInt(const QByteArray &data);
GLOBALLIB_EXPORT ulong toULong(const QByteArray &data);
GLOBALLIB_EXPORT short toShort(const QByteArray &data);

};

#endif // LIB_H
