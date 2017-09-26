// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


/// Base class for all sources
/// Each source runs on their own thread

class SourceManager;
class Pool;

#include <vector>
using namespace std;

class ISourceBytes;

/// Base Class for all Sources
/// Derived Classes must
class Source
{
   public:
      Source(SourceManager *sourceManager, int sourceNumber, ISourceBytes *pSourceBytes);
      Source(ISourceBytes *pSourceBytes);

     ~Source();

    // Main thread execute method
    virtual void ThreadExecute();

    int SourceNumber() const { return m_sourceNumber;}

private:
        SourceManager *m_sourceManager;
        int m_sourceNumber;
        vector<Pool*> m_pools;

        // Abstract Base Class for source bytes
        ISourceBytes *m_pSourceBytes;

        bool *m_shutdownFlag;

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
