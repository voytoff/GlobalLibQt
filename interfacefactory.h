#ifndef INTERFACEFACTORY_H
#define INTERFACEFACTORY_H

#include "GlobalLib_global.h"
#include "isensorconverter.h"
#include <QString>
#include <QMap>
#include <QStringList>
#include <functional>
#include <memory>

using CreatorFunc = std::function<std::unique_ptr<ISensorConverter>()>;

class GLOBALLIB_EXPORT ConverterInfo {
public:
  QUuid uid;
  QString name;
  QString caption;
  CreatorFunc creator;
};

class GLOBALLIB_EXPORT InterfaceFactory {
public:
  static InterfaceFactory& instance() {
    static InterfaceFactory factory;
    return factory;
  }

  // Регистрация нового класса
  static void registerClass(const QString &id, const QString& name, const QString caption, CreatorFunc creator);

  // Получение списка всех доступных имен классов (Перечисление)
  QList<ConverterInfo> availableClasses() const;

  bool contains(const QUuid &uid);

  ConverterInfo* getConverter(const QUuid &uid);

  // Создание объекта по имени
  std::unique_ptr<ISensorConverter> create(const QUuid& uid) const;

private:
  InterfaceFactory() = default;
  static QMap<QUuid, ConverterInfo>& registry();
};

// Макрос для автоматической регистрации (помещается в .cpp файлы наследников)
#define REGISTER_CLASS(ClassID, ClassName, Caption) \
static const bool ClassName##_registered = []() { \
  InterfaceFactory::instance().registerClass(#ClassID, #ClassName, #Caption, []() { \
    return std::make_unique<ClassName>(); \
  }); \
  return true; \
}();
#endif // INTERFACEFACTORY_H
