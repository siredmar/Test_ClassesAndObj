#include "Person.h"
#include <iostream>

Person::Person(std::string _Name, std::string _Phone, unsigned int _iID)
{
   Name = _Name;
   Phone = _Phone;
   ID = _iID;
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

void Person::set_ID(unsigned int _iID)
{
   ID = _iID;
}

std::string Person::get_Name()
{
   return Name;
}

std::string Person::get_Phone()
{
   return Phone;
}

unsigned int Person::get_ID()
{
   return ID;
}