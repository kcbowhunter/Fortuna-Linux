//
// Created by ron on 26/09/17.
//

#include "TaskFactory.h"
#include "ITask.h"
#include "IntegerTask.h"

TaskFactory::TaskFactory()
{
    Register("IntegerTask", &IntegerTask::Create);
}

TaskFactory::~TaskFactory()
{
}

// return nullptr if taskName is not found
ITask *TaskFactory::CreateTask(const string& taskName)
{
    ITask *task = nullptr;

    auto iter = m_factoryMap.find(taskName);

    if (iter == m_factoryMap.end())
        return nullptr;

    auto pfunc = iter->second;

    task = (*pfunc)();  // create the new task object

    return task;
}


void TaskFactory::Register(const string& taskName, CreateTaskFn pfunc)
{
    m_factoryMap[taskName] = pfunc;
}