//
// Created by ron on 22/08/17.
//

#ifndef FORTUNA_LINUX_SOURCEFIXEDINTEGER_H
#define FORTUNA_LINUX_SOURCEFIXEDINTEGER_H


#include "ISourceBytes.h"

class SourceFixedInteger : public ISourceBytes
{
public:
    SourceFixedInteger(int value);

    ~SourceFixedInteger();

    virtual bool GetBytes(std::vector<unsigned char>& bytes);

private:
    int m_value;
};


#endif //FORTUNA_LINUX_SOURCEFIXEDINTEGER_H
