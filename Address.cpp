#include "Address.h"
#include <iostream>

Address::Address()
{
}

Address::Address(std::string street, std::string postalcode, std::string country)
{
   m_street = street;
   m_postalcode = postalcode;
   m_country = country;
}

Address::~Address()
{
}

void Address::set_street(std::string street)
{
   m_street = street;
}

void Address::set_postalcode(std::string postalcode)
{
   m_postalcode = postalcode;
}

void Address::set_country(std::string country)
{
   m_country = country;
}


std::string Address::get_street()
{
   return m_street;
}

std::string Address::get_postalcode()
{
   return m_postalcode;
}

std::string Address::get_country()
{
   return m_country;
}