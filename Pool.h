
#ifndef POOL_INCLUDE
#define POOL_INCLUDE

#include "FortunaTypes.h"

class Pool 
{
public:
   Pool();
  ~Pool();

   void AddByte(const unsigned char);
   unsigned char GetLastByte() const;

private:
   ucvector m_poolData;
};


#endif
