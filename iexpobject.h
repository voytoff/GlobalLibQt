#ifndef IEXPOBJECT_H
#define IEXPOBJECT_H

#include <QtPlugin>

class IExpObject {
public:
  virtual ~IExpObject() {}
  virtual double convert(QByteArray data) = 0;
};

// Associate the class with a unique identifier
#define IExpObject_iid "com.globallib.IExpObject"
Q_DECLARE_INTERFACE(IExpObject, IExpObject_iid)

#endif // IEXPOBJECT_H
