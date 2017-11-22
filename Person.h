#include <string>

class Person
{
   public:
      Person();
      Person(std::string firstname, std::string surname);
      ~Person();
      void set_firstname(std::string firstname);
      void set_surname(std::string surname);
      std::string get_firstname();
      std::string get_surname();

   private:
      std::string m_firstname;
      std::string m_surname;
};