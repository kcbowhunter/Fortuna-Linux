
#include <vector>

using namespace std;

class Pool;
class Fortuna;

class PoolManager
{
   public:
      explicit PoolManager(Fortuna *);
     ~PoolManager();

    bool *GetShutdownFlag() const;

    // disallow the default constructor
    PoolManager()=delete;

    // disallow copying
    PoolManager& operator=(const PoolManager&)=delete;
    PoolManager(const PoolManager&)=delete;

    // disallow moving
    PoolManager& operator=(PoolManager&& )=delete;
    PoolManager(PoolManager&&)=delete;

    // Main thread execute method
    void ThreadExecute();

   private:
      Fortuna *m_pFortuna;
      vector<Pool*> m_pools;

};
