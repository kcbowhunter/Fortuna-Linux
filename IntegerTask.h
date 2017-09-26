//
// Created by ron on 16/09/17.
//

#ifndef FORTUNA_LINUX_INTEGERTASK_H
#define FORTUNA_LINUX_INTEGERTASK_H

#include "ITask.h"

// Create Fortuna with All Integer Sources
// This class is used for testing, to determine how the sources are mixed together
// when the source bytes are copied to the Pools when each source is a fixed integer
// This class is used to determine how much 'mixing' there is of the source data
// being sent to each Pool because the Sources and Pools are all on separate threads
class IntegerTask : public ITask
{
public:
     IntegerTask();
    ~IntegerTask();


    virtual bool RunTask();

private:

};


#endif //FORTUNA_LINUX_INTEGERTASK_H
