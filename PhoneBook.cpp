#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook(std::string numPrivat, std::string numWork, std::string numMobile)
{
   NumberPrivat = numPrivat;
   NumberWork = numWork;
   NumberMobile = numMobile;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::setNumPrivat(std::string numPrivat)
{
   NumberPrivat = numPrivat;
}

void PhoneBook::setNumWork(std::string numWork)
{
   NumberWork = numWork;
}

void PhoneBook::setNumMobile(std::string numMobile)
{
   NumberMobile = numMobile;
}

std::string PhoneBook::getNumPrivat()
{
   return NumberPrivat;
}

std::string PhoneBook::getNumWork()
{
   return NumberWork;
}

std::string PhoneBook::getNumMobile()
{
   return NumberMobile;
}