#include <string>
#include "PhoneBook.h"
#include "Address.h"
#include "Person.h"

class Contact
{
public:
   Contact();
   ~Contact();

   void setPerson(const Person& person)
   {
      this->person = person;
   }

   void setAddress(const Address& address)
   {
      this->address = address;
   }
   
   void setPhoneBook(const PhoneBook& phonebook)
   {
      this->phonebook = phonebook;
   }

   Person getPerson()
   {
      return person;
   }

   Address getAddress()
   {
      return address;
   }

   PhoneBook getPhoneBook()
   {
      return phonebook;
   }

private:
   PhoneBook phonebook;
   Person person;
   Address address;

};