#pragma once
#include <vector>
#include "Contact.h"

class ImportExportData
{
   public:
      virtual void write(std::vector<Contact> *contact){}; // = 0;

      virtual void read(std::vector<Contact> *contact, std::string &filepath){};
      std::vector<Contact> *m_contactdir;

      std::string m_filepath;

      std::string m_firstname;
      std::string m_surname;
      std::string m_street;
      std::string m_postcode;
      std::string m_country;
      std::string m_phone_private;
      std::string m_phone_work;
      std::string m_phone_mobile;

   private:
};
