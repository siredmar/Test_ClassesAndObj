#pragma once
#include <vector>
#include "Contact.h"

class ExportData
{
   public:
      virtual void write(const std::vector<Contact> &contact){}; // = 0;
      std::vector<Contact> m_contactdir;

   private:
};