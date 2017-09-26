// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <cstdio>
#include "Fortuna.h"
#include <unistd.h>
#include "ITask.h"
#include "TaskFactory.h"
#include <string>

using namespace std;

TaskFactory gTaskFactory;

// Return the Task to be executed
ITask *GetTaskFromArguments(int argc, char* argv[]);

int main(int argc, char* argv[])
{
   pid_t pid = getpid();
   printf("\nHello Fortuna-Linux!\n   pid=%lu\n", (unsigned long)pid);

   ITask *task = GetTaskFromArguments(argc, argv);

    if (task != nullptr)
    {
        bool status = task->RunTask();

        return status ? 0 : 100;
    }

   auto *pFortuna = new Fortuna();

   int count = 0;
   int seconds = 5;
   for (int i=0; i<seconds; ++i)
   {
       sleep(1);
       printf("FortunaMain %d seconds\n", ++count);
   }

   delete pFortuna;

   return 0;
}


// Return the Task to be executed
ITask *GetTaskFromArguments(int argc, char* argv[])
{
    ITask *task = nullptr;

    if (argc <= 1)
        return task;

    string taskName(argv[1]);

    // Is the 2nd argument the name of a task?
    task = gTaskFactory.CreateTask(taskName);

    return task;

}
