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

void PhoneBook::set_num_privat(std::string numprivat)
{
   m_numberprivat = numprivat;
}

void PhoneBook::set_num_work(std::string numwork)
{
   m_numberwork = numwork;
}

void PhoneBook::set_num_mobile(std::string nummobile)
{
   m_numbermobile = nummobile;
}

std::string PhoneBook::get_num_privat()
{
   return m_numberprivat;
}

std::string PhoneBook::get_num_work()
{
   return m_numberwork;
}

std::string PhoneBook::get_num_mobile()
{
   return m_numbermobile;
}