#include "Address.h"
#include <iostream>

Address::Address(std::string _street, std::string _postalcode, std::string _country)
{
   street = _street;
   postalcode = _postalcode;
   country = _country;
}

Address::~Address()
{
}

void Address::set_street(std::string _street)
{
   street = _street;
}

void Address::set_postalcode(std::string _postalcode)
{
   postalcode = _postalcode;
}

void Address::set_country(std::string _country)
{
   country = _country;
}


std::string Address::get_street()
{
   return street;
}

std::string Address::get_postalcode()
{
   return postalcode;
}

std::string Address::get_country()
{
   return country;
}