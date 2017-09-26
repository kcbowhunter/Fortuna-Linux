// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "Source.h"
#include "SourceManager.h"
#include "ISourceBytes.h"
#include "SleepUtils.h"
#include "Pool.h"

using namespace SleepUtils;

Source::Source(SourceManager *sourceManager, int sourceNumber, ISourceBytes *pSourceBytes)
:
    m_sourceManager(sourceManager),
    m_sourceNumber(sourceNumber),
    m_pSourceBytes(pSourceBytes)
{
}

Source::Source(ISourceBytes *pSourceBytes)
        :
        m_sourceManager(nullptr),
        m_sourceNumber(-1),
        m_pSourceBytes(pSourceBytes),
        m_shutdownFlag(nullptr)
{
    m_shutdownFlag = m_sourceManager->GetShutdownFlag();
}

Source::~Source()
{
    if (m_pSourceBytes != nullptr)
    {
        delete m_pSourceBytes;
    }
}


// Main thread execute method
void Source::ThreadExecute()
{
    if (*m_shutdownFlag == true)
        return;

    vector<unsigned char> bytes;
    size_t nextPool = 0;

    int count = 0;
    while(1)
    {
        // todo - add a sleep policy for this call
        sleep_ms(200);

        if (*m_shutdownFlag == true)
            return;

        // todo - add a shutdown policy here?
        if (count >= 1024)
            break;

        // todo - add error handling for this call
        m_pSourceBytes->GetBytes(bytes);

        Pool *p = nullptr;
        for(unsigned char uc: bytes)
        {
            // todo - add a mechanism to randomly access the pools
            if (nextPool >= m_pools.size())
                nextPool = 0;

            p = m_pools[nextPool++];

            p->AddByte(uc);
        }

    }


}
