#include <string>

class PhoneBook
{
   public:
      PhoneBook();
      PhoneBook(std::string numprivat, std::string numwork, 
                  std::string nummobile);
      ~PhoneBook();
      void set_num_privat(std::string numprivat);
      void set_num_work(std::string numwork);
      void set_num_mobile(std::string nummobile);
      std::string get_num_privat();
      std::string get_num_work();
      std::string get_num_mobile();

   private: 
      std::string m_numberprivat;
      std::string m_numberwork;
      std::string m_numbermobile;
};