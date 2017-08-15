// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


/// Base class for all sources
/// Each source runs on their own thread

class SourceManager;
class Pool;

#include <vector>
using namespace std;

/// Base Class for all Sources
/// Derived Classes must
class Source
{
   public:
      Source(SourceManager *sourceManager, int sourceNumber);
     ~Source();

    // Main thread execute method
    virtual void ThreadExecute() = 0;

    int SourceNumber() const { return m_sourceNumber;}

private:
        SourceManager *m_sourceManager;
        int m_sourceNumber;
        vector<Pool*> m_pools;

public:
    // disallow the default constructor
    Source()=delete;

    // disallow copying
    Source& operator=(const Source&)=delete;
    Source(const Source&)=delete;

    // disallow moving
    Source& operator=(Source&& )=delete;
    Source(Source&&)=delete;

};
