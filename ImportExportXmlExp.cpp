#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include "ImportExportXmlExp.h"


ImportExportXmlExp::ImportExportXmlExp()
{
}

ImportExportXmlExp::~ImportExportXmlExp()
{
}

void ImportExportXmlExp::write(std::vector<Contact> *contact)
{
   m_contactdir = contact;

   pugi::xml_document doc;

   //Customize declaration
   pugi::xml_node declaration = doc.prepend_child(pugi::node_declaration);
   declaration.append_attribute("version") = "2.0";
   declaration.append_attribute("encoding") = "UTF-8";

   auto root = doc.append_child("Contactlist");

   //Variante 2
   for(int i = 0; i<m_contactdir->size(); i++)
   {
      pugi::xml_node nodeParent = root.append_child("Contact");

      pugi::xml_node Name = nodeParent.append_child("Name");
      Name.append_child("Firstname").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_person().get_firstname().c_str());
      Name.append_child("Surname").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_person().get_surname().c_str());

      pugi::xml_node Address = nodeParent.append_child("Address");
      Address.append_child("Street").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_address().get_street().c_str());
      Address.append_child("PostalCode").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_address().get_postalcode().c_str());
      Address.append_child("Country").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_address().get_country().c_str());

      pugi::xml_node Phone = nodeParent.append_child("Phone");
      Phone.append_child("Private").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_phonebook().get_num_privat().c_str());
      Phone.append_child("Work").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_phonebook().get_num_work().c_str());
      Phone.append_child("Mobile").append_child(pugi::node_pcdata).set_value(m_contactdir->at(i).get_phonebook().get_num_mobile().c_str());
   }

   std::cout << "Saving result: " << doc.save_file("export_variant2.xml") << std::endl;
}

void ImportExportXmlExp::read(std::vector<Contact> *contact, std::string &filepath)
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
      if (firstline != "2.0")
      {
         std::cout<<"Falsches XML-Format";
      }
   }
   xmlfile.close();

   pugi::xml_document doc;

   pugi::xml_parse_result result = doc.load_file(m_filepath.c_str());

   pugi::xml_node contacts = doc.child("Contactlist");

   std::cout<<contacts.name()<<std::endl;

   for(pugi::xml_node contactnode = contacts.first_child(); contactnode; contactnode = contactnode.next_sibling())   //Find each <Contact>
   {
      std::cout<<"New "<<contactnode.name()<<std::endl;
      for(pugi::xml_node contactattr = contactnode.first_child(); contactattr; contactattr = contactattr.next_sibling()) //Should find Name, Address, Phone
      {
         for(pugi::xml_node childattr = contactattr.first_child(); childattr; childattr = childattr.next_sibling())  //Should find each value of each child
         {
            std::cout<<childattr.name()<<" = "<<childattr.child_value()<<std::endl;

            if(std::string(childattr.name()) == "Firstname")
            {
               m_firstname = childattr.child_value();
            }
            if(std::string(childattr.name()) == "Surname")
            {
               m_surname = childattr.child_value();
            }
            if(std::string(childattr.name()) == "Street")
            {
               m_street = childattr.child_value();
            }
            if(std::string(childattr.name())== "PostalCode")
            {
               m_postcode = childattr.child_value();
            }
            if(std::string(childattr.name()) == "Country")
            {
               m_country = childattr.child_value();
            }
            if(std::string(childattr.name()) == "Private")
            {
               m_phone_private = childattr.child_value();
            }
            if(std::string(childattr.name()) == "Work")
            {
               m_phone_work = childattr.child_value();
            }
            if(std::string(childattr.name()) == "Mobile")
            {
               m_phone_mobile = childattr.child_value();
            }
         }
      }
      
      m_contactdir->push_back(Contact(Person(m_firstname, m_surname), 
                                          Address(m_street, m_postcode, m_country), 
                                                PhoneBook(m_phone_private, m_phone_work, m_phone_mobile)));
   }
}