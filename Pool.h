
#include <vector>
using namespace std;

class Pool
{
   public:
      Pool();
     ~Pool();

      void AddByte(const unsigned char uc);

   private:
      vector<unsigned char> m_data;
};
