#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "ExportData.h"


class ExportToXmlExp : public ExportData
{
   public:
      ExportToXmlExp();
      ~ExportToXmlExp();
       void write(const std::vector<Contact> &contact);
};