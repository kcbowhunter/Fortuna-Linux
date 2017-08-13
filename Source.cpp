// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include "Source.h"
#include "SourceManager.h"

Source::Source(SourceManager *sourceManager, int sourceNumber)
:
    m_sourceManager(sourceManager),
    m_sourceNumber(sourceNumber)
{
}


Source::~Source()
{
}
