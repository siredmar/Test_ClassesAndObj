#pragma once
#include <string>
#include <vector>
#include "Contact.h"
#include "ExportData.h"


class ExportToCsv : public ExportData
{
   public:
      ExportToCsv();
      ~ExportToCsv();
       void write(const std::vector<Contact> &contact);
};