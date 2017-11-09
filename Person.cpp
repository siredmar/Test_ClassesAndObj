#include "Person.h"
#include <iostream>

Person::Person()
{
}

Person::Person(std::string firstname, std::string surname)
{
   m_firstname = firstname;
   m_surname = surname;
}

Person::~Person()
{ 
}

void Person::set_firstname(std::string firstname)
{
   m_firstname = firstname;
}

void Person::set_surname(std::string surname)
{
   m_surname = surname;
}

std::string Person::get_firstname()
{
   return m_firstname;
}

std::string Person::get_surname()
{
   return m_surname;
}