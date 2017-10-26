#include <string>

class address
{
   private:
      std::string street;
      std::string postalcode;
      std::string country;

   public:
      address(std::string _street, std::string _postalcode, std::string _country );
      void set_street(std::string _street);
      void set_postalcode(std::string _postalcode);
      void set_country(std::string _country)
      std::string get_street();
      std::string get_postalcode();
      std::string get_country();
}