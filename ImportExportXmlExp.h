#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "ImportExportData.h"


class ImportExportXmlExp : public ImportExportData
{
   public:
      ImportExportXmlExp();
      ~ImportExportXmlExp();
       void write(std::vector<Contact> *contact);
       void read(std::vector<Contact> *contact, std::string &filepath);
};