
#include <stdio.h>
#include "Fortuna.h"
#include "PoolManager.h"


Fortuna::Fortuna()
   :
   m_dumpCtor(true)
{
   if (m_dumpCtor) printf("Fortuna Ctor\n");
   m_poolManager = new PoolManager(this);
}

Fortuna::~Fortuna()
{
   delete m_poolManager;
   if (m_dumpCtor) printf("Fortuna Dtor\n");
}
