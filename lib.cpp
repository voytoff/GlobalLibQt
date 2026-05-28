#include "lib.h"
#include <qendian.h>
#include <QTimeZone>

namespace lib {

int endsWith(QStringList list, QString value) {
  auto it = std::find_if(list.begin(), list.end(), [=](const QString &s) {
    return s.endsWith(value);
  });
  return (it != list.end()) ? std::distance(list.begin(), it) : -1;
}
double round(double value, int digits) {
  double factor = std::pow(10, digits);
  return std::round(value * factor) / factor;
}
double avg(QList<double> array) {
  double sum = std::accumulate(array.begin(), array.end(), 0.0);
  return sum / array.size();
}
double avg(QList<Parameter*> mid) {
  QList<double> temp;
  temp.reserve(mid.size());
  std::transform(mid.begin(), mid.end(), std::back_inserter(temp), [](Parameter* x) { return x->value; });
  return lib::avg(temp);
}
double increment(int persecond, double &index, int digits) {
  auto result = index;
  index += lib::round(1.0 / persecond, digits);
  index = lib::round(index, 3);
  return result;
}

QDateTime toDate(const QByteArray &data) {
  if (data.size() < sizeof(double))
    return QDateTime();
  qint64 fileTimeTicks = qFromLittleEndian<qint64>(reinterpret_cast<const uchar*>(data.data()));
  qint64 msecsSinceEpoch = (fileTimeTicks - 116444736000000000LL) / 10000LL;
  return QDateTime::fromMSecsSinceEpoch(msecsSinceEpoch, QTimeZone::systemTimeZone());
}
QDateTime toOleTime(const QByteArray &data) {
  if (data.size() < sizeof(double))
    return QDateTime();
  double oleValue;
  std::memcpy(&oleValue, data.constData(), sizeof(double));
  QDateTime epoch(QDate(1899, 12, 30), QTime(0, 0, 0), Qt::UTC);
  qint64 msecs = static_cast<qint64>(oleValue * 86400000.0);
  return epoch.addMSecs(msecs);
}
double toDouble(const QByteArray &data) {
  if (data.size() < sizeof(double))
    return double();
  double result;
  std::memcpy(&result, data.constData(), 8);
  return result;
}
float toFloat(const QByteArray &data) {
  if (data.size() < sizeof(float))
    return float();
  float result;
  std::memcpy(&result, data.constData(), 4);
  return result;
}

} // namespace lib
