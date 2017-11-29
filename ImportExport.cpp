#include "ImportExport.h"
#include "ImportExportXml.h"
#include "Contact.h"
#include <string.h>
#include <iostream>
#include "ImportExportData.h"

ImportExport::ImportExport()
{
}
ImportExport::~ImportExport()
{
}

void ImportExport::set_export(std::vector<Contact> *contact, ImportExportData *data)
{
   // m_outputformat = xchangeformat;  //XML1 = XML Variante 1, XML2 = XML Variante 2, CSV
   data->write(contact);
}

void ImportExport::get_import(std::vector<Contact> *contact, std::string *filepath, ImportExportData *data)
{
   data->read(contact, *filepath);
}
