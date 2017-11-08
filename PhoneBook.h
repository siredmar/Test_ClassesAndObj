#include <string>

class PhoneBook
{
   public:
      PhoneBook();
      PhoneBook(std::string numprivat, std::string numwork, 
                  std::string nummobile);
      ~PhoneBook();
      void setNumPrivat(std::string numprivat);
      void setNumWork(std::string numwork);
      void setNumMobile(std::string nummobile);
      std::string getNumPrivat();
      std::string getNumWork();
      std::string getNumMobile();

   private: 
      std::string m_numberprivat;
      std::string m_numberwork;
      std::string m_numbermobile;
};