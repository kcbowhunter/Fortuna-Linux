//
// Created by ron on 26/09/17.
//

#ifndef FORTUNA_LINUX_TASKFACTORY_H
#define FORTUNA_LINUX_TASKFACTORY_H

class ITask;

#include <string>
#include <map>

using namespace std;

// This class is based on this article:
// https://www.codeproject.com/Articles/363338/Factory-Pattern-in-Cplusplus

// Factory class to create Fortuna Task objects
// A Task object runs Fortuna CSPRNG with a specific configuration

typedef ITask* (*CreateTaskFn)(void);

class TaskFactory {
   public:
      TaskFactory();
     ~TaskFactory();

      void Register(const string& taskName, CreateTaskFn pfunc);

      // return nullptr if taskName is not found
      ITask *CreateTask(const string& taskName);

private:
    std::map<std::string, CreateTaskFn> m_factoryMap;
};


#endif //FORTUNA_LINUX_TASKFACTORY_H
