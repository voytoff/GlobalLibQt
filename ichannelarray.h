#ifndef ICHANNELARRAY_H
#define ICHANNELARRAY_H

#include <QtPlugin>

class IChannelArray
{
public:
  virtual ~IChannelArray() {}

  virtual qsizetype count() = 0;
};

// Associate the class with a unique identifier
#define IChannelArray_iid "com.globallib.IChannelArray"
Q_DECLARE_INTERFACE(IChannelArray, IChannelArray_iid)

#endif // ICHANNELARRAY_H
