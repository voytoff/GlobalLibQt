#ifndef IEXPOBJECT_H
#define IEXPOBJECT_H

#include <QtPlugin>
#include "ichannelarray.h"

class IExpObject
{
public:
  virtual ~IExpObject() {}

  IChannelArray* channels = nullptr;

public slots:
  virtual void load() {};
  virtual void close() {};

signals:
  void channelBlockRead(QString fileName, int channelID, QString name);
  void dataBlockRead(QString fileName, int channelID, int blockID, int size);
  void fileLoaded(int index, QString fileName); // Загружен очередной файл
};

// Associate the class with a unique identifier
#define IExpObject_iid "com.globallib.IExpObject"
Q_DECLARE_INTERFACE(IExpObject, IExpObject_iid)

#endif // IEXPOBJECT_H
