#include "datablockarray.h"

DataBlockArray::DataBlockArray(QString name, int frequency, int persecond, QString unit)
  : QList<Parameter>()
  , name(name)
  , frequency(frequency)
  , persecond(persecond)
  , unit(unit) {}

void DataBlockArray::setData(QVector<Parameter*> data) {
}
