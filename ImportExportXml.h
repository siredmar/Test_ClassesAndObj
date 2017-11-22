#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "ImportExportData.h"


class ImportExportXml : public ImportExportData
{
   public:
      ImportExportXml();
      ~ImportExportXml();
       void write(std::vector<Contact> *contact);
       void read(std::vector<Contact> *contact, std::string &filepath);
};