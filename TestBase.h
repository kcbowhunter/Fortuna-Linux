
#ifndef TESTBASE_INCLUDE
#define TESTBASE_INCLUDE

class TestBase{
   public:
      TestBase();
     ~TestBase();

      virtual bool Execute() { return false; }
      bool Status() const { return m_status; }
      void SetStatus(const bool s) { m_status = s; }

   private:
      bool m_status;
};


#endif
