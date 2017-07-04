

#include "Fortuna.h"
#include "cmake-build-debug/PoolManager.h"

Fortuna::Fortuna()
{
   m_poolManager = new PoolManager();
}


Fortuna::~Fortuna()
{
   delete m_poolManager;
}
