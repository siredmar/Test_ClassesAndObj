#include "Person.h"
#include <iostream>

Person::Person(std::string firstname, std::string surname)
{
   Firstname = firstname;
   Surname = surname;
}

Person::~Person()
{ 
}

void Person::setFirstname(std::string firstname)
{
   Firstname = firstname;
}

void Person::setSurname(std::string surname)
{
   Surname = surname;
}

std::string Person::getFirstname()
{
   return Firstname;
}

std::string Person::getSurname()
{
   return Surname;
}