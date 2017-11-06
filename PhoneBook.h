#include <string>

class TelBuch
{
   public:
      TelBuch(std::string numPrivat, std::string numWork, std::string numMobile);
      ~TelBuch();
      void setNumPrivat(std::string numPrivat);
      void setNumWork(std::string numWork);
      void setNumMobile(std::string numMobile);
      std::string getNumPrivat();
      std::string getNumWork();
      std::string getNumMobile();

   private: 
      std::string NumberPrivat;
      std::string NumberWork;
      std::string NumberMobile;
}