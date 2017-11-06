#include <string>

class PhoneBook
{
   public:
      PhoneBook(std::string numPrivat, std::string numWork, std::string numMobile);
      ~PhoneBook();
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