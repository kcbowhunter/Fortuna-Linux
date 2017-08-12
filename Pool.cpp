// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "Pool.h"
#include "PoolManager.h"
#include "SleepUtils.h"

using namespace SleepUtils;


Pool::Pool(PoolManager* poolManager)
   :
    m_poolManager(poolManager),
    m_shutdownFlag(nullptr)
{
    m_shutdownFlag = m_poolManager->GetShutdownFlag();
}

Pool::~Pool()
{
}

void Pool::AddByte(unsigned char uc)
{
   m_data.push_back(uc);
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
