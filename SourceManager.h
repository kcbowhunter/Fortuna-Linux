// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef FORTUNA_LINUX_SOURCEMANAGER_H
#define FORTUNA_LINUX_SOURCEMANAGER_H

class Fortuna;
class Source;
class Pool;
class PoolManager;

#include <vector>
using namespace std;

class SourceManager
{
public:
    explicit SourceManager(Fortuna *fortuna);
    ~SourceManager();

private:
    Fortuna *m_pFortuna;
    PoolManager *m_poolManager;
    vector<Source*> m_sources;
    vector<Pool*> m_pools;

public:
    // disallow the default constructor
    SourceManager()=delete;

    // disallow copying
    SourceManager& operator=(const SourceManager&)=delete;
    SourceManager(const SourceManager&)=delete;

    // disallow moving
    SourceManager& operator=(SourceManager&& )=delete;
    SourceManager(SourceManager&&)=delete;

};


#endif //FORTUNA_LINUX_SOURCEMANAGER_H
