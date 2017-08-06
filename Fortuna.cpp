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
   m_poolManager = new PoolManager(this);
}

Fortuna::~Fortuna()
{
    m_shutDown= true;
   delete m_poolManager;
   if (m_dumpCtor) printf("Fortuna Dtor\n");
}
