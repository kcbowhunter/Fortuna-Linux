// Copyright (c) 2017 Ronald Bondy
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.


#include <vector>
using namespace std;

class PoolManager;

class Pool
{
   public:
      Pool(PoolManager* poolManager);
     ~Pool();

      void AddByte(unsigned char uc);

   private:
      vector<unsigned char> m_data;
      PoolManager *m_poolManager;
      bool *m_shutdownFlag;
};
