//
// Created by ron on 16/09/17.
//

#include "IntegerTask.h"

#include <vector>
using namespace std;

#include "Fortuna.h"
#include "Source.h"
#include "SourceFixedInteger.h"
#include <cstdio>
#include "SleepUtils.h"

IntegerTask::IntegerTask()
{

}


IntegerTask::~IntegerTask()
{

}

bool IntegerTask::RunTask()
{
    bool status = true;

    bool dump = true;
    if (dump) printf("Enter IntegerTask::RunTask\n");

    const int numSources = 16;
    const int numPools   = 16;
    const int numBytes   = 16;  // number of bytes for each source to send to the Pools
    int i=0;

    vector<Source*> sources;

    // create Fortuna
    // Fortuna creates the pools and starts the Pool threads in the ctor
    Fortuna* pFortuna = new Fortuna();

    if (dump) printf("\t\tCreate Sources\n");
    // create the Sources
    for(i=0; i<numSources; ++i)
    {
//      if (dump) printf("Create SourceFixedInteger %d\n", i);
      auto *sourceBytes = new SourceFixedInteger(i);

//      if (dump) printf("Create Source %d\n", i);
      auto *source = new Source(pFortuna, sourceBytes);
      source->SetSourceNumber(i);
      sources.push_back(source);
    }

    // Add the Sources to Fortuna and start the source threads
    // (each source runs on it's own thread
    if (dump) printf("\t\tAssignSourcesAndStartThreads\n");
    pFortuna->AssignSourcesAndStartThreads(sources);

    SleepUtils::sleep_ms(5000);

    // Wait for Fortuna source threads
    // To shutdown while the Integer test executes
    if (dump) printf("\t\tWaitForSourceShutdown\n");
    pFortuna->WaitForSourceShutdown();

    if (dump) printf("\t\tFortuna Shutdown\n");
    pFortuna->Shutdown();

    delete pFortuna;

    if (dump) printf("Exit IntegerTask::RunTask\n");

    return status;
}