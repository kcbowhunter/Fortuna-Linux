

#include "PoolTests.h"
#include "Pool.h"

PoolTest01::PoolTest01()
:
TestBase()
{
}

PoolTest01::~PoolTest01()
{
}

bool PoolTest01::Execute()
{
   Pool *pool = new Pool();

   const unsigned char byte = 0x07;

   pool->AddByte(byte);

   unsigned char byte2 = pool->GetLastByte();

   bool status = byte == byte2;

  SetStatus(status);

  delete pool;

  return status;
}
