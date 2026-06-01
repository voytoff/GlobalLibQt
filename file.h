#ifndef FILE_H
#define FILE_H

#include "GlobalLib_global.h"
#include <QFile>
#include <QDateTime>
#include <QStringDecoder>

class GLOBALLIB_EXPORT File : public QFile
{
public:
  File(const QString &name);

  bool seekNext(qint64 offset);
  QByteArray readExt(const qint64 position, const qint64 count);

  template <typename T> inline T get(const qint64 count) {
    T result;
    if constexpr (std::is_same_v<T, QString>)
      result = read_string(count);
    else if constexpr (std::is_same_v<T, QDateTime>)
      result = read_date(count);
    else if constexpr (std::is_same_v<T, double>)
      result = read_double(count);
    else if constexpr (std::is_same_v<T, int>)
      result = read_int(count);
    else if constexpr (std::is_same_v<T, ulong>)
      result = read_ulong(count);
    else if constexpr (std::is_same_v<T, short>)
      result = read_short(count);
    else result = T();
    return result;
  }

protected:
  QString read_string(const qint64 count);
  QDateTime read_date(const qint64 count = 8);
  double read_double(const qint64 count = 8);
  int read_int(const qint64 count = 8);
  ulong read_ulong(const qint64 count = 8);
  short read_short(const qint64 count = 2);

private:
#if defined(Q_OS_WIN)
  QStringDecoder decoder = QStringDecoder(QStringConverter::System);
#elif defined(Q_OS_LINUX)
    QStringDecoder decoder = QStringDecoder("Windows-1251");
#elif defined(Q_OS_MAC)
  QStringDecoder decoder = QStringDecoder("Windows-1251");
#endif

};

#endif // FILE_H
