// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include "PoolManager.h"
#include "Pool.h"


PoolManager::PoolManager(Fortuna *pFortuna)
   :
   m_pFortuna(pFortuna)
{
   bool dumpCtor = pFortuna->DumpCtor();
   if (dumpCtor) printf("PoolManager Ctor\n");

   m_pools.resize(16);
   for (int i=0; i<16; ++i)
      {
         auto *p = new Pool(this);
         m_pools[i] = p;
      }
}

PoolManager::~PoolManager()
{
   bool dumpCtor = m_pFortuna->DumpCtor();

   for( Pool * p : m_pools)
      {
         delete p;
      }
   m_pools.clear();

   if (dumpCtor) printf("PoolManager Dtor\n");
}
