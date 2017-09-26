// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include "PoolManager.h"
#include "SourceManager.h"


Fortuna::Fortuna()
   :
   m_dumpCtor(true),
   m_shutDown(false),
   m_poolManager(nullptr),
   m_sourceManager(nullptr)
{
   if (m_dumpCtor) printf("Fortuna Ctor\n");

   int numberOfPools = 32;

   m_poolManager = new PoolManager(this, numberOfPools);

   m_sourceManager = new SourceManager(this);
}

Fortuna::~Fortuna()
{
    if (m_dumpCtor) printf("Begin Fortuna Dtor\n");
    m_shutDown= true;

    if (m_dumpCtor) printf("Delete Source Manager\n");
    delete m_sourceManager;

    if (m_dumpCtor) printf("Delete Pool Manager\n");
    delete m_poolManager;

    if (m_dumpCtor) printf("End Fortuna Dtor\n");
}


// Set the sources in Fortuna and start the source threads
bool Fortuna::AssignSourcesAndStartThreads(vector<Source*>& sources)
{
    return m_sourceManager->AssignSourcesAndStartThreads(sources);
}

// Wait for the Sources to shutdown
// This is used for testing different Source options
bool Fortuna::WaitForSourceShutdown()
{
    m_sourceManager->JoinSourceThreads();

    return true;
}

// Shutown Fortuna, ie Source and Pool threads
bool Fortuna::Shutdown()
{
    m_shutDown = true;

    m_sourceManager->JoinSourceThreads();

    m_poolManager->JoinPoolThreads();

    return true;
}
