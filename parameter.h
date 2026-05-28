#ifndef PARAMETER_H
#define PARAMETER_H

#include "GlobalLib_global.h"
#include <QDateTime>

class GLOBALLIB_EXPORT Parameter
{
public:
  Parameter();

  bool operator<(const Parameter &other) const {
    return time < other.time;
  }

  Parameter(double index, QDateTime time, double value);
  QDateTime time;
  double index;
  double value;
};

#endif // PARAMETER_H
