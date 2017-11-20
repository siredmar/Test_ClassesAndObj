#include <string>
#include <vector>
#include <iostream>
#include "pugixml.hpp"
#include "ExportToXml.h"


ExportToXml::ExportToXml()
{
}

ExportToXml::~ExportToXml()
{
}

void ExportToXml::write(const std::vector<Contact> &contact)
{
   this->m_contactdir = contact;

   pugi::xml_document doc;

   pugi::xml_node declaration = doc.prepend_child(pugi::node_declaration);
   declaration.append_attribute("version") = "1.0";
   declaration.append_attribute("encoding") = "UTF-8";

   auto root = doc.append_child("Contactlist");
   
   //Variante 1
   for(int i = 0; i<m_contactdir.size(); i++)
   {
      pugi::xml_node nodeparent = root.append_child("Contact");
      pugi::xml_node nodeChild = nodeparent.append_child("Name");
      nodeChild.append_attribute("Firstname") = m_contactdir.at(i).get_person().get_firstname().c_str();
      nodeChild.append_attribute("Surname") = m_contactdir.at(i).get_person().get_surname().c_str();

      nodeChild = nodeparent.append_child("Adress");
      nodeChild.append_attribute("Street") = m_contactdir.at(i).get_address().get_street().c_str();
      nodeChild.append_attribute("PostalCode") = m_contactdir.at(i).get_address().get_postalcode().c_str();
      nodeChild.append_attribute("Country") = m_contactdir.at(i).get_address().get_country().c_str();

      nodeChild = nodeparent.append_child("Phone");
      nodeChild.append_attribute("Private") = m_contactdir.at(i).get_phonebook().get_num_privat().c_str();
      nodeChild.append_attribute("Work") = m_contactdir.at(i).get_phonebook().get_num_work().c_str();
      nodeChild.append_attribute("Mobile") = m_contactdir.at(i).get_phonebook().get_num_mobile().c_str();   
   }
   std::cout << "Saving result: " << doc.save_file("output_file.xml") << std::endl;
}