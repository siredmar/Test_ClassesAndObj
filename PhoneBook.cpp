#include "PhoneBook.h"
#include <iostream>

PhoneBook::PhoneBook()
{
}

PhoneBook::PhoneBook(std::string numprivat, std::string numwork, std::string nummobile)
{
   m_numberprivat = numprivat;
   m_numberwork = numwork;
   m_numbermobile = nummobile;
}

PhoneBook::~PhoneBook()
{
}

void PhoneBook::setNumPrivat(std::string numprivat)
{
   m_numberprivat = numprivat;
}

void PhoneBook::setNumWork(std::string numwork)
{
   m_numberwork = numwork;
}

void PhoneBook::setNumMobile(std::string nummobile)
{
   m_numbermobile = nummobile;
}

std::string PhoneBook::getNumPrivat()
{
   return m_numberprivat;
}

std::string PhoneBook::getNumWork()
{
   return m_numberwork;
}

std::string PhoneBook::getNumMobile()
{
   return m_numbermobile;
}