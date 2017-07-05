
class PoolManager;


class Fortuna
{
   public:
      Fortuna();
     ~Fortuna();

      bool DumpCtor() const { return m_dumpCtor; }

   private:
      PoolManager *m_poolManager;
      bool m_dumpCtor; // dump ctor and dtor calls
};
