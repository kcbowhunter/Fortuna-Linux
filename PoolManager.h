
#include <vector>

using namespace std;

class Pool;
class Fortuna;

class PoolManager
{
   public:
      PoolManager(Fortuna *);
     ~PoolManager();

    bool *GetShutdownFlag() const;

    // Main thread execute method
    void ThreadExecute();

   private:
      Fortuna *m_pFortuna;
      vector<Pool*> m_pools;

};
