#include <string>

class Person
{
   public:
      Person();
      Person(std::string firstname, std::string surname);
      ~Person();
      void setFirstname(std::string firstname);
      void setSurname(std::string surname);
      std::string getFirstname();
      std::string getSurname();

   private:
      std::string m_firstname;
      std::string m_surname;
};