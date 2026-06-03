#ifndef QTDYNAMOMETER_H
#define QTDYNAMOMETER_H

#include "interfacefactory.h"
#include "isensorconverter.h"
#include <QObject>
#include <QUuid>

class QtDynamometer : public QObject, public ISensorConverter {
  Q_OBJECT
  Q_PLUGIN_METADATA(IID ISensorConverter_iid)
  Q_INTERFACES(ISensorConverter)

public:
  explicit QtDynamometer(QObject *parent = nullptr);
  QVariant convert(const QByteArray &data) override;
  Q_PROPERTY(QUuid id READ id)
  static QUuid reg;

  QUuid id() const override { return QUuid::fromString("{f6ee2edb-3406-4743-9e68-0a50f5bfb5fb}"); }

};
REGISTER_CLASS({f6ee2edb-3406-4743-9e68-0a50f5bfb5fb}, QtDynamometer, Динамометр)

#endif // QTDYNAMOMETER_H
