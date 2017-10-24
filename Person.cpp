#include "Person.h"
#include <iostream>

Person::Person(std::string _Name, std::string _Phone)
{
   Name = _Name;
   Phone = _Phone;
}

Person::~Person()
{
}

void Person::set_Name(std::string _Name)
{
   Name = _Name;
}

void Person::set_Phone(std::string _Phone)
{
   Phone = _Phone;
}

std::string Person::get_Name()
{
   return Name;
}

std::string Person::get_Phone()
{
   return Phone;
}