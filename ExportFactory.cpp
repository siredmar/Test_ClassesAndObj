#include "ExportFactory.h"
#include "ImportExportData.h"
#include "ImportExportCsv.h"
#include "ImportExportXml.h"
#include "ImportExportXmlExp.h"

ExportFactory::ExportFactory()
{

}

ExportFactory::~ExportFactory()
{

}


ImportExportData *ExportFactory::GenerateImportExportObject(std::string path)
{
    if(check_filetype_xml(path) == true)
        return new ImportExportXml;
    else if (check_filetype_xmlexp(path) == true)
        return new ImportExportXmlExp;
    else
        return new ImportExportCsv;

}
