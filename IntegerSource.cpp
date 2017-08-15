//
// Created by ron on 14/08/17.
//

#include "IntegerSource.h"

IntegerSource::IntegerSource(SourceManager *sourceManager, int sourceNumber)
        :
        Source(sourceManager, sourceNumber)
{
}


// Main thread execute method
void IntegerSource::ThreadExecute()
{
    int sourceNumber = SourceNumber();


}
