#include <string>

class Address
{
   public:
      Address();
      Address(std::string street, std::string postalcode, 
                  std::string country);
      ~Address();
      void set_street(std::string street);
      void set_postalcode(std::string postalcode);
      void set_country(std::string country);
      std::string get_street();
      std::string get_postalcode();
      std::string get_country();

   private:
      std::string m_street;
      std::string m_postalcode;
      std::string m_country;
};