
#include "TestManager.h"

TestManager::TestManager()
{
}

TestManager::~TestManager()
{
}

bool TestManager::AddTest(TestBase* testbase)
{
   m_tests.push_back(testbase);
}

bool TestManager::RunTests()
{


   return true;
}
