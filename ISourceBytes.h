// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FORTUNA_LINUX_ISOURCEBYTES_H
#define FORTUNA_LINUX_ISOURCEBYTES_H

#include <vector>
using namespace std;

class ISourceBytes
{
public:
    virtual bool GetBytes(std::vector<unsigned char>& bytes) = 0;
};

#endif //FORTUNA_LINUX_ISOURCEBYTES_H
