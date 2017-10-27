#include <string>

class Person
{
   private:
      std::string Name;
      std::string Phone;
      unsigned int ID;
      
   public:
      Person(std::string _Name, std::string _Phone, unsigned int _iID);
      ~Person();
      void set_Name(std::string _Name);
      void set_Phone(std::string _Phone);
      void set_ID(unsigned int _iID);
      std::string get_Name();
      std::string get_Phone();
      unsigned int get_ID();
};