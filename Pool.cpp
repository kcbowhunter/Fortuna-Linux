
#include "Pool.h"

Pool::Pool()
{


}

Pool::~Pool()
{

}


void Pool::AddByte(const unsigned char byte)
{
   m_poolData.push_back(byte);
}

unsigned char Pool::GetLastByte() const
{
   if (m_poolData.empty())
      return 0;
  
   size_t j = m_poolData.size();
   unsigned char uc = m_poolData[j-1];


   return uc;
}
