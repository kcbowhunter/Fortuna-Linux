// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "Source.h"
#include "SourceManager.h"
#include "ISourceBytes.h"
#include "SleepUtils.h"
#include "Pool.h"
#include "PoolManager.h"
#include "Fortuna.h"
#include <cstdio>

using namespace SleepUtils;

Source::Source(SourceManager *sourceManager, int sourceNumber, ISourceBytes *pSourceBytes)
:
    m_pFortuna(sourceManager->GetFortuna()),
    m_sourceManager(sourceManager),
    m_sourceNumber(sourceNumber),
    m_pSourceBytes(pSourceBytes)
{
}

Source::Source(Fortuna *pFortuna, ISourceBytes *pSourceBytes)
        :
        m_pFortuna(pFortuna),
        m_sourceManager(pFortuna->GetSourceManager()),
        m_sourceNumber(-1),
        m_pSourceBytes(pSourceBytes),
        m_shutdownFlag(nullptr)
{
    m_shutdownFlag = m_sourceManager->GetShutdownFlag();
}

Source::~Source()
{
    bool dumpCtor = m_sourceManager->GetFortuna()->DumpCtor();
    if (dumpCtor) printf("Begin Source %d Dtor\n", m_sourceNumber);

    if (m_pSourceBytes != nullptr)
    {
        delete m_pSourceBytes;
    }
}


// Main thread execute method
void Source::ThreadExecute()
{
    bool dump = true;
    if (dump) printf("Begin Source::ThreadExecute %d\n", m_sourceNumber);

    if (m_pools.empty())
    {
        PoolManager *poolmgr = m_pFortuna->GetPoolManager();
        m_pools = poolmgr->GetPools();

        if (m_pools.empty())
        {
            if (dump) printf("Source::ThreadExecute ERROR ***** m_pools is empty\n");
            return;
        }
    }


    if (*m_shutdownFlag == true)
        return;

    vector<unsigned char> bytes;
    size_t nextPool = 0;

    int count = 0;
    while(1)
    {
        // todo - add a sleep policy for this call
        sleep_ms(100);

        if (*m_shutdownFlag == true)
            return;

        // todo - add a shutdown policy here?
        if (dump) printf("Source::ThreadExecute source = %d, count = %d\n", m_sourceNumber, count);
        if (count++ >= 1024)
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

    if (dump) printf("End Source::ThreadExecute %d\n", m_sourceNumber);
}
