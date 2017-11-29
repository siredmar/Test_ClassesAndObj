#pragma once
#include "ImportExportData.h"

class ExportFactory
{
public:
    ExportFactory();
    ~ExportFactory();
    ImportExportData *GenerateImportExportObject(std::string path);
};
