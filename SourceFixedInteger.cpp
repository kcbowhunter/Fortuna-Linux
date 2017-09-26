//
// Created by ron on 22/08/17.
//

#include "SourceFixedInteger.h"


SourceFixedInteger::SourceFixedInteger(int value)
        :
        m_value(value)
{}

SourceFixedInteger::~SourceFixedInteger()
{}


bool SourceFixedInteger::GetBytes(std::vector<unsigned char>& bytes)
{
    // assume m_value is in the range 0 <= value <= 255 because this
    // source is used to test how well the data from each source is distributed among the pools
    // due to multi threading and generally there are only 16 pools
    unsigned char c = (unsigned char) m_value;
    bytes.push_back(c);
    return true;
}