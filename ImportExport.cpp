#include "ImportExport.h"
#include "ExportToXml.h"
#include "Contact.h"
#include <string.h>
#include <iostream>
#include "ExportData.h"

ImportExport::ImportExport()
{
}
ImportExport::~ImportExport()
{
}

void ImportExport::set_export(std::vector<Contact> *contact, ExportData *data)
{ 
   // m_outputformat = xchangeformat;  //XML1 = XML Variante 1, XML2 = XML Variante 2, CSV
   data->write(*contact);
}

std::string ImportExport::get_import()
{
}