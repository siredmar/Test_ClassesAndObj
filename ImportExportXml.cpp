#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include "ImportExportXml.h"


ImportExportXml::ImportExportXml()
{
}

ImportExportXml::~ImportExportXml()
{
}

void ImportExportXml::write(std::vector<Contact> *contact)
{
   m_contactdir = contact;

   pugi::xml_document doc;

   pugi::xml_node declaration = doc.prepend_child(pugi::node_declaration);
   declaration.append_attribute("version") = "1.0";
   declaration.append_attribute("encoding") = "UTF-8";

   auto root = doc.append_child("Contactlist");

   //Variante 1
   for(int i = 0; i < m_contactdir->size(); i++)
   {
      pugi::xml_node nodeparent = root.append_child("Contact");
      pugi::xml_node nodeChild = nodeparent.append_child("Name");
      nodeChild.append_attribute("Firstname") = m_contactdir->at(i).get_person().get_firstname().c_str();
      nodeChild.append_attribute("Surname") = m_contactdir->at(i).get_person().get_surname().c_str();

      nodeChild = nodeparent.append_child("Adress");
      nodeChild.append_attribute("Street") = m_contactdir->at(i).get_address().get_street().c_str();
      nodeChild.append_attribute("PostalCode") = m_contactdir->at(i).get_address().get_postalcode().c_str();
      nodeChild.append_attribute("Country") = m_contactdir->at(i).get_address().get_country().c_str();

      nodeChild = nodeparent.append_child("Phone");
      nodeChild.append_attribute("Private") = m_contactdir->at(i).get_phonebook().get_num_privat().c_str();
      nodeChild.append_attribute("Work") = m_contactdir->at(i).get_phonebook().get_num_work().c_str();
      nodeChild.append_attribute("Mobile") = m_contactdir->at(i).get_phonebook().get_num_mobile().c_str();
   }
   std::cout << "Saving result: " << doc.save_file("export_variant1.xml") << std::endl;
}

void ImportExportXml::read(std::vector<Contact> *contact, std::string &filepath)
{
   m_contactdir = contact;
   this->m_filepath = filepath;
   std::ifstream xmlfile (m_filepath);
   std::string firstline;
   if (xmlfile.is_open())
   {
      getline(xmlfile, firstline);
      std::size_t found = firstline.find('"');
      firstline = firstline.substr(found+1, 3);
      if (firstline != "1.0")
      {
         std::cout<<"Falsches XML-Format";
      }
   }
   xmlfile.close();

   pugi::xml_document doc;

   pugi::xml_parse_result result = doc.load_file(m_filepath.c_str());

   pugi::xml_node contacts = doc.child("Contactlist");

   std::cout<<contacts.name()<<std::endl;

   for (pugi::xml_node contact = contacts.first_child(); contact; contact = contact.next_sibling())   //Find each <Contact>
   {
      std::cout<<"New "<<contact.name()<<std::endl;
      for (pugi::xml_node contactattr = contact.first_child(); contactattr; contactattr = contactattr.next_sibling()) //Should find Name, Address, Phone
      {
         for (pugi::xml_attribute childattr = contactattr.first_attribute(); childattr; childattr = childattr.next_attribute())  //Should find each value of each child
         {
            std::cout<<childattr.name()<<" = "<<childattr.value()<<std::endl;
            if(std::string(childattr.name()) == "Firstname")
            {
               m_firstname = childattr.value();
            }
            if(std::string(childattr.name()) == "Surname")
            {
               m_surname = childattr.value();
            }
            if(std::string(childattr.name()) == "Street")
            {
               m_street = childattr.value();
            }
            if(std::string(childattr.name())== "PostalCode")
            {
               m_postcode = childattr.value();
            }
            if(std::string(childattr.name()) == "Country")
            {
               m_country = childattr.value();
            }
            if(std::string(childattr.name()) == "Private")
            {
               m_phone_private = childattr.value();
            }
            if(std::string(childattr.name()) == "Work")
            {
               m_phone_work = childattr.value();
            }
            if(std::string(childattr.name()) == "Mobile")
            {
               m_phone_mobile = childattr.value();
            }
         }
      }

      m_contactdir->push_back(Contact(Person(m_firstname, m_surname),
                                          Address(m_street, m_postcode, m_country),
                                                PhoneBook(m_phone_private, m_phone_work, m_phone_mobile)));

   }
}

bool check_filetype_xml(std::string filepath)
{
    std::ifstream xmlfile (filepath);
    std::string firstline;
    if (xmlfile.is_open())
    {
       getline(xmlfile, firstline);
       xmlfile.close();
       std::size_t found = firstline.find('"');
       firstline = firstline.substr(found+1, 3);
       if (firstline != "1.0")
       {
          return false;
       }
       else
       {
           return true;
       }
    }
}
