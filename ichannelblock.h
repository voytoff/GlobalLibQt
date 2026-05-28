#ifndef ICHANNELBLOCK_H
#define ICHANNELBLOCK_H

#include <QtPlugin>

class IChannelBlock
{
public:
  virtual ~IChannelBlock() {}
};

// Associate the class with a unique identifier
#define IChannelBlock_iid "com.globallib.IChannelBlock"
Q_DECLARE_INTERFACE(IChannelBlock, IChannelBlock_iid)

#endif // ICHANNELBLOCK_H
