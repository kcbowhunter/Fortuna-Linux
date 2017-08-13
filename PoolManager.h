// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#include <vector>
#include <pthread.h>

using namespace std;

class Pool;
class Fortuna;

class PoolManager
{
   public:
      explicit PoolManager(Fortuna *, int numberOfPools);
     ~PoolManager();

    bool *GetShutdownFlag() const;


    int GetNumberOfPools() const { return m_numberOfPools;}

    // Main thread execute method
    void ThreadExecute();

   private:
      Fortuna *m_pFortuna;
      vector<Pool*> m_pools;
      int m_numberOfPools;
      vector<pthread_t> m_poolThreads;
   private:
      void JoinPoolThreads();

    public:
        // disallow the default constructor
        PoolManager()=delete;

        // disallow copying
        PoolManager& operator=(const PoolManager&)=delete;
        PoolManager(const PoolManager&)=delete;

        // disallow moving
        PoolManager& operator=(PoolManager&& )=delete;
        PoolManager(PoolManager&&)=delete;

};
