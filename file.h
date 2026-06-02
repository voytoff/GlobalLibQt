#ifndef FILE_H
#define FILE_H

#include "GlobalLib_global.h"
#include <QFile>
#include <QDateTime>
#include <QStringDecoder>

class GLOBALLIB_EXPORT File : public QFile {
public:
  File(const QString &name);

  bool seekNext(qint64 offset);
  QByteArray readExt(const qint64 position, const qint64 count);

  template <typename T> inline T get(const qint64 count) {
    T result;
    if constexpr (std::is_same_v<T, QString>)
      result = get_string(count);
    else if constexpr (std::is_same_v<T, QDateTime>)
      result = get_date(count);
    else if constexpr (std::is_same_v<T, double>)
      result = get_double(count);
    else if constexpr (std::is_same_v<T, float>)
      result = get_float(count);
    else if constexpr (std::is_same_v<T, int>)
      result = get_int(count);
    else if constexpr (std::is_same_v<T, ulong>)
      result = get_ulong(count);
    else if constexpr (std::is_same_v<T, short>)
      result = get_short(count);
    else result = T();
    return result;
  }

protected:
  QString get_string(const qint64 count);
  QDateTime get_date(const qint64 count = 8);
  double get_double(const qint64 count = 8);
  double get_float(const qint64 count = 4);
  int get_int(const qint64 count = 4);
  ulong get_ulong(const qint64 count = 8);
  short get_short(const qint64 count = 2);

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
