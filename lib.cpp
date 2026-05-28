#include "lib.h"

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

} // namespace lib
