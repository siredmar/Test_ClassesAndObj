#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "ExportData.h"


class ExportToXml : public ExportData
{
   public:
      ExportToXml();
      ~ExportToXml();
       void write(const std::vector<Contact> &contact);
};