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

    vector<Pool*> GetPools() { return m_pools;}

    void JoinPoolThreads();

   private:
      Fortuna *m_pFortuna;
      vector<Pool*> m_pools;  // Pool of data for the cs pseudo random number generator
      int m_numberOfPools;    // Number of pools of bytes
      vector<pthread_t> m_poolThreads;  // Thread id for each pool
      bool m_bPoolMgrIsShutdown;
   private:


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
