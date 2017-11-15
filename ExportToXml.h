#pragma once
#include "pugixml.hpp"
#include <string.h>
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

class ExportToCsv : public ExportData
{
   public:
      ExportToCsv();
      ~ExportToCsv();
       void write(const std::vector<Contact> &contact);
};















/*
class ExportData
{
   public:
      ExportData();
      ~ExportData();
      void write_xml(const std::vector<Contact> &contact);
      // virtual void add(const std::vector<Contact>& contact) = 0;
      // virtual void write(const std::string& path) = 0; 
};

class ExportToXml : public ExportData
{
   public:
      ExportToXml();
      ~ExportToXml();

      void set_export_xmlvar1();
      void set_export_xmlvar2();
};

// class CsvData : public Data
// {
//    public:
//       void add(const std::vector<Contact>& contact);
//       void write(const std::string& path);
   
//    private: 
//       int a; 
// };

// class XmlData : public Data
// {
//    public:
//       void add(const std::vector<Contact>& contact);
//       void write(const std::string& path); 
// };*/