#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include "pugixml.hpp"
#include "ImportExportCsv.h"


ImportExportCsv::ImportExportCsv()
{

}

ImportExportCsv::~ImportExportCsv()
{
}

void ImportExportCsv::write(std::vector<Contact> *contact)
{
   m_contactdir = contact;

   std::ofstream csvfile ("export_varaint3.csv");

   if (csvfile.is_open())
   {
      csvfile<<"Firstname"<<","<<"Surname"<<","<<"Street"<<","<<"PostalCode"<<","<<"Country"<<","<<"Phone_Private"<<","<<"Phone_Work"<<","<<"Phone_Mobile"<<std::endl;
      for (int i = 0; i < m_contactdir->size(); i++)
      {
         csvfile<<m_contactdir->at(i).get_person().get_firstname() + "," + m_contactdir->at(i).get_person().get_surname() + "," + 
                     m_contactdir->at(i).get_address().get_street() + "," + m_contactdir->at(i).get_address().get_postalcode() + "," + m_contactdir->at(i).get_address().get_country()+ "," +
                        m_contactdir->at(i).get_phonebook().get_num_privat() + "," + m_contactdir->at(i).get_phonebook().get_num_work() + "," +  m_contactdir->at(i).get_phonebook().get_num_mobile()<<std::endl;
      }
   }
   else
   {
      std::cout<<"Unable to open csv.file"<<std::endl;
   }

}