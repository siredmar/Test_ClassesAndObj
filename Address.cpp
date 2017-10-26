#include <Address.h>
#include <iostream>

address::address(std::string street, std::string postalcode, std::string country)
{
   street = street;
   postalcode = postalcode;
   country = country;
}

address::~address()
{
}

void address::set_street(std::string street)
{
   street = street;
}

void address::set_postalcode(std::string postalcode)
{
   postalcode = postalcode;
}

void address::set_country(std::string country)
{
   country = country;
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