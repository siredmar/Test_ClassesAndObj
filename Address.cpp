#include <Address.h>
#include <iostream>

address::address(std::string _street, std::string _postalcode, std::string _country)
{
   street = _street;
   postalcode = _postalcode;
   country = _country;
}

address::~address()
{
}

void address::set_street(std::string _street)
{
   street = _street;
}

void address::set_postalcode(std::string _postalcode)
{
   postalcode = _postalcode;
}

void address::set_country(std::string _country)
{
   country = _country;
}

std::string address::get_street()
{
   return street;
}

std::string address::get_postalcode()
{
   return postalcode;
}

std::string address::get_country()
{
   return country;
}