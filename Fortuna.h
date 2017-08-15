// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

class PoolManager;
class SourceManager;


class Fortuna
{
   public:
      Fortuna();
     ~Fortuna();

    // disallow copying
    Fortuna& operator=(const Fortuna&)=delete;
    Fortuna(const Fortuna&)=delete;

    // disallow moving
    Fortuna& operator=(Fortuna&& )=delete;
    Fortuna(Fortuna&&)=delete;


    bool DumpCtor() const { return m_dumpCtor; }

    bool *GetShutdownFlag() { return &m_shutDown;}

    PoolManager *GetPoolManager() { return m_poolManager;}
    SourceManager *GetSourceManager() { return m_sourceManager; }

   private:
      PoolManager *m_poolManager;
      SourceManager *m_sourceManager;
      bool m_dumpCtor; // dump ctor and dtor calls

      bool m_shutDown;  // shutdown flag
};
