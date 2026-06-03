#include "qtdynamometer.h"
#include "lib.h"

QtDynamometer::QtDynamometer(QObject *parent): QObject{parent} {}

QVariant QtDynamometer::convert(const QByteArray &data) {
  auto text = QString::fromStdString(data.toStdString());
  auto parts = text.split("\r\n", Qt::SkipEmptyParts);
  if (parts.length() > 0) {
    QString part = nullptr;
    if (parts.length() >= 2) part = *(parts.end() - 2); // предпоследний;
    else part = parts.first();
    lib::trim(part);
    return part.toDouble();
  } else return QVariant();
}
