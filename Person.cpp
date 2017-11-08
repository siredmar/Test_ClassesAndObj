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

void Person::setFirstname(std::string firstname)
{
   m_firstname = firstname;
}

void Person::setSurname(std::string surname)
{
   m_surname = surname;
}

std::string Person::getFirstname()
{
   return m_firstname;
}

std::string Person::getSurname()
{
   return m_surname;
}