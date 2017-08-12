// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include "PoolManager.h"


Fortuna::Fortuna()
   :
   m_dumpCtor(true),
   m_shutDown(false)
{
   if (m_dumpCtor) printf("Fortuna Ctor\n");

    int numberOfPools = 32;

   m_poolManager = new PoolManager(this, numberOfPools);
}

Fortuna::~Fortuna()
{
    if (m_dumpCtor) printf("Begin Fortuna Dtor\n");
    m_shutDown= true;
    delete m_poolManager;
    if (m_dumpCtor) printf("End Fortuna Dtor\n");
}
