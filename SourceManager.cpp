// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <cstdio>
#include "SourceManager.h"
#include "PoolManager.h"
#include "Source.h"
#include "Fortuna.h"

void *StartSourceThread(void *arg)
{
    Source *source = (Source*)arg;
    source->ThreadExecute();
    return nullptr;
}


SourceManager::SourceManager(Fortuna *fortuna)
    :
    m_pFortuna(fortuna),
    m_poolManager(fortuna->GetPoolManager()),
    m_bSourceMgrIsShutdown(false)
{
    m_pools = m_poolManager->GetPools();
}

SourceManager::~SourceManager()
{
    bool dumpCtor = m_pFortuna->DumpCtor();
    if (dumpCtor) printf("Begin SourceManager Dtor\n");

    JoinSourceThreads();

    for(Source *s : m_sources)
    {
        delete s;
    }

    m_sources.clear();
    m_pools.clear();  // Pools are deleted by the Pool Manager
}

bool SourceManager::AssignSourcesAndStartThreads(std::vector<Source*>& sources)
{
    m_sources = sources; // copy the pointers to the Source objects

    bool dump = true;

    pthread_t threadId = 0;
    int threadStatus = 0;
    for (Source* source: m_sources)
    {
        threadId = 0;

        threadStatus = pthread_create(&threadId, NULL, StartSourceThread, (void*)source);
        if (dump) printf("SourceMgr::AssignSourcesStartThreads thread tid=0x%lx\n", (unsigned long) threadId);

        m_sourceThreads.push_back(threadId);
    }
    return true;
}

// Join each of the pool threads
void SourceManager::JoinSourceThreads()
{
    if (m_bSourceMgrIsShutdown)
        return;

    int count = 0;
    int status = 0;
    bool dumpCtor = m_pFortuna->DumpCtor();
    for(auto tid: m_sourceThreads)
    {
        if (dumpCtor)
        {
            printf("Joining source thread %2d 0x%lx\n", count++, (unsigned long)tid);
        }

        status = pthread_join(tid, NULL);
    }

    m_bSourceMgrIsShutdown = true;
}


bool* SourceManager::GetShutdownFlag()
{
    return m_pFortuna->GetShutdownFlag();
}