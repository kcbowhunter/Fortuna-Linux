// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include "SourceManager.h"
#include "Source.h"
#include "Fortuna.h"

void *StartSourceThread(void *arg)
{
    Source *source = (Source*)arg;
    source->ThreadExecute();
    return nullptr;
}


SourceManager::SourceManager(Fortuna *fortuna)
    :
    m_pFortuna(fortuna)
{

}

SourceManager::~SourceManager()
{
    for(Source *s : m_sources)
    {
        delete s;
    }

    m_sources.clear();
}