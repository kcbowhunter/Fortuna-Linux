// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <pthread.h>
#include <vector>
using namespace std;

class PoolManager;

class Pool
{
   public:
      explicit Pool(PoolManager* poolManager, int poolNumber);
     ~Pool();

      // Add a single byte to the pool
      void AddByte(unsigned char);

      // Main thread execute method
      void ThreadExecute();

   private:
        // Owner
        PoolManager *m_poolManager;

        // Pool Number
        int m_poolNumber;
        // pool data
        vector<unsigned char> m_data;

        bool *m_shutdownFlag;
        pthread_mutex_t m_poolMutex;

   public:
        // disallow the default constructor
        Pool()=delete;

        // disallow copying
        Pool& operator=(const Pool&)=delete;
        Pool(const Pool&)=delete;

        // disallow moving
        Pool& operator=(Pool&& )=delete;
        Pool(Pool&&)=delete;

};
