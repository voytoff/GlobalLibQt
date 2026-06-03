#include "interfacefactory.h"

void InterfaceFactory::registerClass(const QString &id, const QString &name, const QString caption, CreatorFunc creator) {
  QUuid uid = QUuid::fromString(id);
  ConverterInfo info;
  info.uid = uid;
  info.name = name;
  info.caption = caption;
  info.creator = creator;
  registry()[uid] = info;
}

QList<ConverterInfo> InterfaceFactory::availableClasses() const {
  return registry().values();
}

bool InterfaceFactory::contains(const QUuid &uid) {
  return registry().contains(uid);
}

ConverterInfo* InterfaceFactory::getConverter(const QUuid &uid) {
  if (registry().contains(uid)) return &registry()[uid];
  else return nullptr;
}

std::unique_ptr<ISensorConverter> InterfaceFactory::create(const QUuid &uid) const {
  if (!registry().contains(uid)) return nullptr;
  CreatorFunc creater = registry()[uid].creator;
  return creater();
}

QMap<QUuid, ConverterInfo>& InterfaceFactory::registry() {
  static QMap<QUuid, ConverterInfo> instance;
  return instance;
}