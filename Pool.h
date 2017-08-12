// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <vector>
using namespace std;

class PoolManager;

class Pool
{
   public:
      explicit Pool(PoolManager* poolManager);
     ~Pool();

    public:
      // disallow the default constructor
      Pool()=delete;

      // disallow copying
      Pool& operator=(const Pool&)=delete;
      Pool(const Pool&)=delete;

      // disallow moving
      Pool& operator=(Pool&& )=delete;
      Pool(Pool&&)=delete;

      void AddByte(unsigned char);

    // Main thread execute method
    void ThreadExecute();

private:
      vector<unsigned char> m_data;
      PoolManager *m_poolManager;
      bool *m_shutdownFlag;
};
