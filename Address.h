#include <string>

class Address
{
   public:
      Address();
      Address(std::string _street, std::string _postalcode, 
                  std::string _country);
      ~Address();
      void set_street(std::string _street);
      void set_postalcode(std::string _postalcode);
      void set_country(std::string _country);
      std::string get_street();
      std::string get_postalcode();
      std::string get_country();

   private:
      std::string street;
      std::string postalcode;
      std::string country;
};