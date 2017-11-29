#pragma once
#include <string>
#include "Contact.h"
#include <vector>
#include "ImportExportData.h"

class ImportExport
{
   public:
      ImportExport();
      ~ImportExport();

      void set_export(std::vector<Contact> *contact , ImportExportData *data);

      void get_import(std::vector<Contact> *contact , std::string *filepath, ImportExportData *data);

   private:
      std::string m_outputformat;
};
