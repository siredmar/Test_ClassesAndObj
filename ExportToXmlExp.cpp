#include <string>
#include <vector>
#include <iostream>
#include "pugixml.hpp"
#include "ExportToXmlExp.h"


ExportToXmlExp::ExportToXmlExp()
{
}

ExportToXmlExp::~ExportToXmlExp()
{
}

void ExportToXmlExp::write(const std::vector<Contact> &contact)
{
   this->m_contactdir = contact;

   pugi::xml_document doc;

   //Customize declaration
   pugi::xml_node declaration = doc.prepend_child(pugi::node_declaration);
   declaration.append_attribute("version") = "2.0";
   declaration.append_attribute("encoding") = "UTF-8";

   auto root = doc.append_child("Contactlist");

   //Variante 2
   for(int i = 0; i<m_contactdir.size(); i++)
   {
      pugi::xml_node nodeParent = root.append_child("Contact");

      pugi::xml_node Name = nodeParent.append_child("Name");
      Name.append_child("Firstname").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_person().get_firstname().c_str());
      Name.append_child("Surname").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_person().get_surname().c_str());

      pugi::xml_node Address = nodeParent.append_child("Address");
      Address.append_child("Strasse").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_address().get_street().c_str());
      Address.append_child("PostalCode").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_address().get_postalcode().c_str());
      Address.append_child("Country").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_address().get_country().c_str());

      pugi::xml_node Phone = nodeParent.append_child("Phone");
      Phone.append_child("Private").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_phonebook().get_num_privat().c_str());
      Phone.append_child("Work").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_phonebook().get_num_work().c_str());
      Phone.append_child("Mobile").append_child(pugi::node_pcdata).set_value(m_contactdir.at(i).get_phonebook().get_num_mobile().c_str());
   }

   std::cout << "Saving result: " << doc.save_file("output_file.xml") << std::endl;
}