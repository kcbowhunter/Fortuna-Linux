
#ifndef TESTMANAGER_INCLUDE
#define TESTMANAGER_INCLUDE

#include <vector>
class TestBase;

class TestManager
{
public:
   TestManager();
  ~TestManager();

   bool AddTest(TestBase* test);

   bool RunTests();  // run all tests in series

private:
   std::vector<TestBase*> m_tests;
};


#endif
