

#include "PoolManager.h"
#include "Pool.h"

PoolManager::PoolManager()
{

}

PoolManager::~PoolManager()
{

}

bool PoolManager::CreatePools(const int count)
{
   m_pools.resize(count);

   for(int i=0; i<count; ++i)
      {
         Pool *p = new Pool();
         m_pools[i] = p;
      }   
   return true;
}
