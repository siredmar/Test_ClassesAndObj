#pragma once
#include <string>
#include "PhoneBook.h"
#include "Address.h"
#include "Person.h"

class Contact
{
public:
   Contact()
   {
   }

   Contact(const Person &p)
   { 
      set_person(p);
   }

   Contact(const Address &a)
   {
      set_address(a);
   }

   Contact(const PhoneBook &ph)
   { 
      set_phonebook(ph);
   }

   Contact(const Person &p, const Address &a, const PhoneBook &ph)
   {
      set_person(p);
      set_address(a);
      set_phonebook(ph);
   }

   ~Contact()
   {  
   }

   void set_person(const Person &person)
   {
      this->m_person = person;
   }

   void set_address(const Address &address)
   {
      this->m_address = address;
   }
   
   void set_phonebook(const PhoneBook &phonebook)
   {
      this->m_phonebook = phonebook;
   }

   Person get_person()
   {
      return m_person;
   }

   Address get_address()
   {
      return m_address;
   }

   PhoneBook get_phonebook()
   {
      return m_phonebook;
   }

private:
   PhoneBook m_phonebook;
   Person m_person;
   Address m_address;

};