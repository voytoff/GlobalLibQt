#include "file.h"
#include "lib.h"
#include <QTimeZone>
#include <QtEndian>
#include <QRegularExpression>

File::File(const QString &name) : QFile(name) {
  if (exists() && open(QIODevice::ReadOnly)) {
  } else throw new std::exception();
}

bool File::seekNext(qint64 offset) {
  return seek(pos() + offset);
}

QByteArray File::readExt(const qint64 position, const qint64 count) {
  seek(position);
  return read(count);
} // readExt

QString File::get_string(const qint64 count) {
  QTextStream in(this);
  QByteArray data = read(count);
  QString text = decoder(data);
  text.remove(QRegularExpression("^\\s+"));
  text.remove(QRegularExpression("[\\r\\n\\0]+$"));
  return text;
} // read_string
QDateTime File::get_date(const qint64 count) {
  return lib::toDate(read(count));
} // get_date
double File::get_double(const qint64 count) {
  return lib::toDouble(read(count));
} // get_double
double File::get_float(const qint64 count) {
  return lib::toFloat(read(count));
} // get_float
int File::get_int(const qint64 count) {
  return lib::toInt(read(count));
} // get_int
ulong File::get_ulong(const qint64 count) {
  return lib::toULong(read(count));
} // get_ulong
short File::get_short(const qint64 count) {
  return lib::toShort(read(count));
} // get_short
