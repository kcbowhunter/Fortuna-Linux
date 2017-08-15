// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#ifndef FORTUNA_LINUX_INTEGERSOURCE_H
#define FORTUNA_LINUX_INTEGERSOURCE_H

#include "Source.h"

class SourceManager;

class IntegerSource : public Source
{
public:
    IntegerSource(SourceManager *sourceManager, int sourceNumber);

    // Main thread execute method
    virtual void ThreadExecute();

private:



};


#endif //FORTUNA_LINUX_INTEGERSOURCE_H
