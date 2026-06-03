#ifndef ISENSORCONVERTER_H
#define ISENSORCONVERTER_H

#include <QtPlugin>

class ISensorConverter
{
public:
  virtual ~ISensorConverter() {}
  virtual QUuid id() const = 0;
  virtual QVariant convert(const QByteArray &data) = 0;
};

// Associate the class with a unique identifier
#define ISensorConverter_iid "com.globallib.ISensorConverter"
Q_DECLARE_INTERFACE(ISensorConverter, ISensorConverter_iid)

#endif // ISENSORCONVERTER_H
