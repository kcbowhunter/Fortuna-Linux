

#include "Pool.h"

Pool::Pool()
{
}

Pool::~Pool()
{
}

void Pool::AddByte(const unsigned char uc)
{
   m_data.push_back(uc);
}
