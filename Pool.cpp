// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "Pool.h"
#include "PoolManager.h"
#include "SleepUtils.h"

using namespace SleepUtils;


Pool::Pool(PoolManager* poolManager, int poolNumber)
   :
    m_poolManager(poolManager),
    m_poolNumber(poolNumber),
    m_shutdownFlag(nullptr),
    m_poolMutex(PTHREAD_MUTEX_INITIALIZER)
{
    m_shutdownFlag = m_poolManager->GetShutdownFlag();
    int status = pthread_mutex_init(&m_poolMutex, nullptr);
}

Pool::~Pool()
{
    int status = pthread_mutex_destroy(&m_poolMutex);
}

void Pool::AddByte(unsigned char uc)
{
   int status = pthread_mutex_lock(&m_poolMutex);

   m_data.push_back(uc);

   status = pthread_mutex_unlock(&m_poolMutex);
}

// Main thread execute method
void Pool::ThreadExecute()
{
    while(true)
    {
        sleep_ms(200);

        if (*m_shutdownFlag == false)
        {
            break;
        }
    }
}
