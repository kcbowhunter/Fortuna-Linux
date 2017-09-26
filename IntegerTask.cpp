//
// Created by ron on 16/09/17.
//

#include "IntegerTask.h"

#include <vector>
using namespace std;

#include "Fortuna.h"
#include "Source.h"
#include "SourceFixedInteger.h"


IntegerTask::IntegerTask()
{

}


IntegerTask::~IntegerTask()
{

}

bool IntegerTask::RunTask()
{
    const int numSources = 16;
    const int numPools   = 16;
    const int numBytes   = 16;  // number of bytes for each source to send to the Pools
    int i=0;

    vector<Source*> sources;

    // create Fortuna
    // Fortuna creates the pools and starts the Pool threads in the ctor
    Fortuna* pFortuna = new Fortuna();

    // create the Sources
    for(i=0; i<numSources; ++i)
    {
      auto *sourceBytes = new SourceFixedInteger(i);
      auto *source = new Source(sourceBytes);
      sources.push_back(source);
    }

    // Add the Sources to Fortuna and start the source threads
    // (each source runs on it's own thread
    pFortuna->AssignSourcesAndStartThreads(sources);

    // Wait for Fortuna source threads
    // To shutdown while the Integer test executes
    pFortuna->WaitForSourceShutdown();

    pFortuna->Shutdown();

    delete pFortuna;
}