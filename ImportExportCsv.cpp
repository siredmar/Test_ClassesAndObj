#include <string>
#include <vector>
#include <iostream>
#include <fstream>
#include <boost/tokenizer.hpp>
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

   std::ofstream csvfile ("export_variant3.csv");
   std::string seperator = "|";
   if (csvfile.is_open())
   {
      csvfile<<"csv"<<std::endl;
      csvfile<<"Firstname"<<seperator<<"Surname"<<seperator<<"Street"<<seperator<<"PostalCode"<<seperator<<"Country"<<seperator<<"Phone_Private"<<seperator<<"Phone_Work"<<seperator<<"Phone_Mobile"<<std::endl;
      for (int i = 0; i < m_contactdir->size(); i++)
      {
         csvfile<<m_contactdir->at(i).get_person().get_firstname() + seperator + m_contactdir->at(i).get_person().get_surname() + seperator + 
                     m_contactdir->at(i).get_address().get_street() + seperator + m_contactdir->at(i).get_address().get_postalcode() + seperator + m_contactdir->at(i).get_address().get_country()+ seperator +
                        m_contactdir->at(i).get_phonebook().get_num_privat() + seperator + m_contactdir->at(i).get_phonebook().get_num_work() + seperator +  m_contactdir->at(i).get_phonebook().get_num_mobile()<<std::endl;
      }
   }
   else
   {
      std::cout<<"Unable to open csv.file"<<std::endl;
   }

}

void ImportExportCsv::read(std::vector<Contact> *contact, std::string &filepath)
{
   m_contactdir = contact;
   this->m_filepath = filepath;
   std::ifstream csvfile (m_filepath);
   std::string line;
   if (csvfile.is_open())
   {
      getline(csvfile, line); //Get line (first one)
      if (line != "csv")
      {
         std::cout<<"Falsches Dateiformat! Dateiformat entspricht nicht csv!"<<std::endl;
      }
      getline(csvfile, line); //Get next line - can be ignored, because it isn't important (shows only the column identifier)
      bool emptyline = false;
      while(!csvfile.eof())
      {
         getline(csvfile, line);
         if (line.empty()) //If step into line without any character
         {
            emptyline = true;
         }
         typedef boost::tokenizer<boost::char_separator<char>> tokenizer;
         boost::char_separator<char> sep{"|"};
         tokenizer tok {line, sep};
         int cnt = 0;
         
         for (const auto &strelement : tok)
         {
            std::cout<<strelement<<std::endl;
            switch (cnt)
            {
               case 0:
               {
                  m_firstname = strelement;
                  std::cout<<"Vorname : "<<m_firstname<<std::endl;
                  break;
               }
               case 1:
               {
                  m_surname = strelement;
                  std::cout<<"Nachname : "<<m_surname<<std::endl;
                  break;
               }
               case 2:
               {
                  m_street = strelement;
                  std::cout<<"Strasse : "<<m_street<<std::endl;
                  break;
               }
               case 3:
               {
                  m_postcode = strelement;
                  std::cout<<"PLZ : "<<m_postcode<<std::endl;
                  break;
               }
               case 4:
               {
                  m_country = strelement;
                  std::cout<<"Stadt : "<<m_country<<std::endl;
                  break;
               }
               case 5:
               {
                  m_phone_private = strelement;
                  std::cout<<"Ph - priv : "<<m_phone_private<<std::endl;
                  break;
               }
               case 6:
               {
                  m_phone_work = strelement;
                  std::cout<<"Ph - work : "<<m_phone_work<<std::endl;
                  break;
               }
               case 7:
               {
                  m_phone_mobile = strelement;
                  std::cout<<"Ph - mob : "<<m_phone_mobile<<std::endl;
                  break;
               }
            }
            cnt++;
         }
       
         if ( emptyline == false )
         {
            m_contactdir->push_back(Contact(Person(m_firstname, m_surname), 
                                       Address(m_street, m_postcode, m_country), 
                                             PhoneBook(m_phone_private, m_phone_work, m_phone_mobile)));
         }

      }
   }
}