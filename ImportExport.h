#pragma once
#include <string>
#include "Contact.h"
#include <vector>
#include "ExportData.h"

class ImportExport
{
   public:
      ImportExport();
      ~ImportExport();

      void set_export(std::vector<Contact> *contact , ExportData *data);

      std::string get_import();

   private:
      std::string m_outputformat;
};