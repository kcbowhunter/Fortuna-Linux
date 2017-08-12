// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include "PoolManager.h"
#include "Pool.h"

void *StartPoolThread(void *arg)
{
    Pool *pool = (Pool*)arg;
    pool->ThreadExecute();
    return nullptr;
}

PoolManager::PoolManager(Fortuna *pFortuna, int numberOfPools)
   :
   m_pFortuna(pFortuna),
   m_numberOfPools(numberOfPools)
{
   bool dumpCtor = pFortuna->DumpCtor();
   if (dumpCtor) printf("PoolManager Ctor\n");

    pthread_t threadId = 0;
    int threadStatus = 0;
    m_pools.resize(m_numberOfPools);
    for (int i=0; i<m_numberOfPools; ++i)
      {
         auto *pool = new Pool(this);
         m_pools[i] = pool;
         threadStatus = pthread_create(&threadId, NULL, StartPoolThread, (void*)pool);
         m_poolThreads.push_back(threadId);
      }
}



PoolManager::~PoolManager()
{
    bool dumpCtor = m_pFortuna->DumpCtor();
    if (dumpCtor) printf("Begin PoolManager Dtor\n");

    JoinPoolThreads();

    for( Pool *p : m_pools)
       {
          delete p;
       }
    m_pools.clear();

    if (dumpCtor) printf("End PoolManager Dtor\n");
}

// Return the shutdown flag from Fortuna owner
bool *PoolManager::GetShutdownFlag() const
{
   return m_pFortuna->GetShutdownFlag();
}

void PoolManager::ThreadExecute()
{}

// Join each of the pool threads
void PoolManager::JoinPoolThreads()
{
    int count = 0;
    int status = 0;
    for(auto tid: m_poolThreads)
    {
        printf("Joining thread %2d 0x%lx\n", count++, (unsigned long)tid);
        status = pthread_join(tid, NULL);
    }
}
