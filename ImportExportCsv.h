#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "ImportExportData.h"


class ImportExportCsv : public ImportExportData
{
   public:
      ImportExportCsv();
      ~ImportExportCsv();
       void write(std::vector<Contact> *contact);
};