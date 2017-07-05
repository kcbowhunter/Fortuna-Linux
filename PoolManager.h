
#include <vector>

using namespace std;

class Pool;
class Fortuna;

class PoolManager
{
   public:
      PoolManager(Fortuna *);
     ~PoolManager();

   private:
      Fortuna *m_pFortuna;
      vector<Pool*> m_pools;

};
