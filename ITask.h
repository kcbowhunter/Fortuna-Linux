//
// Created by ron on 16/09/17.
//

#ifndef FORTUNA_LINUX_ITASK_H
#define FORTUNA_LINUX_ITASK_H

// Base Class for All Fortuna Executions
// This class is used for testing and production, to test and run Fortuna
class ITask
{
public:
    virtual bool RunTask() = 0;

    virtual ~ITask() {}

};

#endif //FORTUNA_LINUX_ITASK_H
