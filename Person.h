#include <string>

class Person
{
   private:
      std::string Name;
      std::string Phone;
      
   public:
      Person(std::string _Name, std::string _Phone);
      ~Person();
      void set_Name(std::string _Name);
      void set_Phone(std::string _Phone);
      std::string get_Name();
      std::string get_Phone();
};