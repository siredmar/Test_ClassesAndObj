#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <fstream>
#include <boost/program_options/cmdline.hpp>
#include <boost/program_options/config.hpp>
#include <boost/program_options/environment_iterator.hpp>
#include <boost/program_options/eof_iterator.hpp>
#include <boost/program_options/errors.hpp>
#include <boost/program_options/option.hpp>
#include <boost/program_options/options_description.hpp>
#include <boost/program_options/parsers.hpp>
#include <boost/program_options/positional_options.hpp>
#include <boost/program_options/value_semantic.hpp>
#include <boost/program_options/variables_map.hpp>
#include <boost/program_options/version.hpp>
#include "Contact.h"
#include "pugixml.hpp"
#include "ImportExport.h"
#include "ImportExportXml.h"
#include "ImportExportXmlExp.h"
#include "ImportExportCsv.h"
#include "ExportFactory.h"

using namespace std;
namespace po = boost::program_options;

bool bSort(Contact a, Contact b);
void PrintOutDirectory(vector<Contact> cont_dir , char extension);
void ExportXchange(vector<Contact> contact_dir, char xchangeformat);
void ImportXchange(vector<Contact> *contact_dir, string fpath);
void ArgumentParser (int argcount, char *argvalue[], vector<Contact> *contact_dir);

int main(int argc, char *argv[]) //Order of arguments: <exchangeformat> <filepath>
{
   string filepath;
   char exchangeformat;  //1=xml1, 2=xml2, 3=csv
   vector<Contact> contact_directory;
   ArgumentParser(argc, argv, &contact_directory);

   //Names for class Person
   string inp_firstname = "";
   string inp_surname = "";
   //Values for class PhoneBook
   string inp_phone_privat = "";
   string inp_phone_work = "";
   string inp_phone_mobile = "";
   //Values for class Address
   string inp_street = "";
   string inp_postcode = "";
   string inp_country = "";

   char selection = '0';
   bool entry = true;
   ofstream outputFile;

   
   ImportExport dataExport;
   ImportExport dataImport;

   do
   {
      cout<<"Auswahl: " << endl;
      cout<<"1 = Eingabe Daten"<<endl;
      cout<<"2 = Ausgabe Daten"<<endl;
      cout<<"3 = Eingabe ändern"<<endl;
      cout<<"4 = Eingabe löschen"<<endl;
      cout<<"5 = Import"<<endl;
      cout<<"6 = Ende"<<endl;
      cin>>selection;
      cin.clear();
      cin.ignore();
      switch (selection)
      {
         case '1':   //Input data
         {
            bool temp_state = false;
            char temp_select = ' ';
            do
            {
               cout<<endl<<"Eingabe Vorname u. Nachname"<<endl<<endl;
               cout<<"Vorname: ";
               getline(cin,inp_firstname);
               cin.clear();
               cout<<"Nachname: ";
               cin.ignore(0);
               getline(cin,inp_surname);
               cin.clear();
               cout<<endl<<"Telefon?  j/n    ";
               cin>>temp_select;
               cin.clear();
               if (temp_select != 'j')
               {
                  temp_state = true;
               }
               else
               {
                  cout<<endl<<"Privat: ";
                  cin.ignore();
                  getline(cin, inp_phone_privat);
                  cin.clear();
                  cout<<endl<<"Arbeit: ";
                  cin.ignore(0);
                  getline(cin, inp_phone_work);
                  cin.clear();
                  cout<<endl<<"Mobile: ";
                  cin.ignore(0);
                  getline(cin, inp_phone_mobile);
               }

               cout<<endl<<"Adresse?  j/n    ";
               cin>>temp_select;
               cin.clear();
               if (temp_select != 'j')
               {
                  temp_state = true;
               }
               else
               {
                  cout<<endl<<"Strasse: ";
                  cin.ignore();
                  getline(cin, inp_street);
                  cin.clear();
                  cout<<endl<<"PLZ: ";
                  cin.ignore(0);
                  getline(cin, inp_postcode);
                  cin.clear();
                  cout<<endl<<"Stadt: ";
                  cin.ignore(0);
                  getline(cin, inp_country);
               }
               contact_directory.push_back(Contact(Person(inp_firstname, inp_surname),
                                                      Address(inp_street, inp_postcode, inp_country),
                                                            PhoneBook(inp_phone_privat, inp_phone_work, inp_phone_mobile)));
               std::sort(contact_directory.begin(), contact_directory.end(), bSort);
               cin.clear();
               cout<<endl<<"Eingabe weiterer Daten?  j/n"<<endl;
               cin>>temp_select;
               if (temp_select != 'j')
               {
                  temp_state = true;
               }
               cin.clear();
               cin.ignore();
            }while(temp_state == false);

            //After input, write data to a .xml file
            //dataExport.set_export(&contact_directory, &xml);
            ExportXchange(contact_directory, exchangeformat);

            break;
         }
         case '2': //Output data
         {
            PrintOutDirectory(contact_directory, 'n');
            break;
         }
         case '3': //Change data
         {
            PrintOutDirectory(contact_directory, 'y');
            char chName = ' ';
            char chPhone = ' ';
            char firstletter_address = ' ';
            int iInput = 0;
            cout<<endl;
            cout<<"Welcher Eintrag soll geändert werden? 999 = Abbruch"<<endl<<endl;
            cin.clear();
            cin>>iInput;
            if (iInput != 999)   //No cancel, change data is requested
            {
               //Existing
               inp_firstname = contact_directory.at(iInput).get_person().get_firstname();
               inp_surname = contact_directory.at(iInput).get_person().get_surname();
               inp_street = contact_directory.at(iInput).get_address().get_street();
               inp_postcode = contact_directory.at(iInput).get_address().get_postalcode();
               inp_country = contact_directory.at(iInput).get_address().get_country();
               inp_phone_mobile = contact_directory.at(iInput).get_phonebook().get_num_mobile();
               inp_phone_privat = contact_directory.at(iInput).get_phonebook().get_num_privat();
               inp_phone_work = contact_directory.at(iInput).get_phonebook().get_num_work();

               cin.clear();
               cout<<"Name? j/n  =>  ";
               cin>>chName;
               cout<<endl<<"Telefon? j/n  =>  ";
               cin.clear();
               cin>>chPhone;
               cout<<endl<<"Adresse ? j/n => ";
               cin.clear();
               cin>>firstletter_address;
               if (chName == 'j')
               {
                  cout<<endl<<endl<<"Vorname: ";
                  cin.ignore();
                  getline(cin, inp_firstname);
                  cin.clear();
                  cout<<endl<<endl<<"Nachname: ";
                  cin.ignore(0);
                  getline(cin, inp_surname);
               }
               if (chPhone == 'j')
               {
                  cout<<endl<<endl<<"Arbeit: ";
                  if (chName == 'j')
                  {
                     cin.ignore(0);
                  }
                  else
                  {
                     cin.ignore();
                  }
                  getline(cin, inp_phone_work);

                  cout<<endl<<endl<<"Privat: ";
                  getline(cin, inp_phone_privat);

                  cout<<endl<<endl<<"Mobile: ";
                  getline(cin, inp_phone_mobile);
               }
               if (firstletter_address == 'j')
               {
                  cout<<endl<<endl<<"Strasse: ";
                  if (chName == 'j' || chPhone == 'j')
                  {
                     cin.ignore(0);
                  }
                  else
                  {
                     cin.ignore();
                  }
                  getline(cin,inp_street);
                  cout<<endl<<"PLZ: ";
                  cin.ignore(0);
                  getline(cin,inp_postcode);
                  cout<<endl<<"Stadt: ";
                  cin.ignore(0);
                  getline(cin,inp_country);
               }
               contact_directory.erase(contact_directory.begin()+iInput);
               contact_directory.insert(contact_directory.begin()+iInput, Contact(Person(inp_firstname, inp_surname),
                                                                                    Address(inp_street, inp_postcode, inp_country),
                                                                                       PhoneBook(inp_phone_privat, inp_phone_work, inp_phone_mobile)));
               ExportXchange(contact_directory, exchangeformat);
               // dataExport.set_export(&contact_directory, &xchange);
            }
            break;
         }
         case '4': //Delete data
         {
            PrintOutDirectory(contact_directory, 'y');
            int iInput = 0;
            cout<<endl;
            cout<<"Welcher Eintrag soll gelöscht werden?"<<endl;
            cout<<endl<<"Nummer: ";
            cin.clear();
            cin>>iInput;
            contact_directory.erase(contact_directory.begin()+iInput);

            ExportXchange(contact_directory, exchangeformat);
            // dataExport.set_export(&contact_directory, &xchange);

            break;
         }
         case '5': //Import
         {
            string filep = "output_file.xml";

            // dataImport.get_import(&contact_directory, &filep, &xchange);
            ImportXchange(&contact_directory, filep);
            std::sort(contact_directory.begin(), contact_directory.end(), bSort);

            break;
         }
         case '6': //End
         {
            entry = false;
            break;
         }
         default:
         {
            cout<<endl<<"W.T.F you put into???"<<endl
                     <<"Only 1 - 6!"<<endl<<endl;
            break;
         }
      }
   }while(entry == true);
}


bool bSort(Contact a, Contact b)
{
   bool sorted_return;
   char firstletter_a = ' ';
   char secondletter_a = ' ';
   char firstletter_b = ' ';
   char secondletter_b = ' ';
   firstletter_a = a.get_person().get_firstname().front();
   firstletter_b = b.get_person().get_firstname().front();
   secondletter_a = a.get_person().get_firstname().at(1);
   secondletter_b = b.get_person().get_firstname().at(1);

   for (unsigned int i=0; i<a.get_person().get_firstname().length(); i++)
   {
      if (firstletter_a <= firstletter_b)
      {
         sorted_return=true;

         if (firstletter_a == firstletter_b)
         {
            if (secondletter_a <= secondletter_b)
            {
               sorted_return=true;
            }
            else
            {
               sorted_return=false;
            }
         }
      }
      else
      {
         sorted_return=false;
      }
   }
   return sorted_return;
}

void PrintOutDirectory(vector<Contact> cont_dir , char extension)
{
   cout<<endl<<" ##### AUSGABE ##### "<<endl<<endl;
   if (extension == 'n')
   {
      for(auto element : cont_dir)  //OLDSCHOOL -> for (int i=0; i<cont_dir.size(); i++)
      {
         cout<<"Vorname = "<<element.get_person().get_firstname()<<endl;
         cout<<"Nachname = "<<element.get_person().get_surname()<<endl;

         cout<<"Adresse = "<<element.get_address().get_street() + "   "
                                 + element.get_address().get_postalcode() + " "
                                             + element.get_address().get_country()<<endl;

         cout<<"Tel.Buch = "<<element.get_phonebook().get_num_privat() + "   "
                                 + element.get_phonebook().get_num_work() + "   "
                                          +  element.get_phonebook().get_num_mobile()<<endl;
      }
   }
   if (extension == 'y')
   {
      int number = 0;
      for(auto element : cont_dir)  //OLDSCHOOL -> for (int i=0; i<cont_dir.size(); i++)
      {
         cout<< number++ << ":" << endl;
         cout<<"Vorname = "<<element.get_person().get_firstname()<<endl;
         cout<<"Nachname = "<<element.get_person().get_surname()<<endl;

         cout<<"Adresse = "<<element.get_address().get_street() + "   "
                                 + element.get_address().get_postalcode() + " "
                                       + element.get_address().get_country()<<endl;

         cout<<"Tel.Buch = "<<element.get_phonebook().get_num_privat() + "   "
                                 + element.get_phonebook().get_num_work() + "   "
                                       + element.get_phonebook().get_num_mobile()<<endl;
      }
   }
}

void ExportXchange(vector<Contact> contact_dir, char xchangeformat)
{
   ImportExport dataExport;
   ImportExport dataImport;

   switch (xchangeformat)
   {
      case '1':
      {
         ImportExportXml xml;
         dataImport.set_export(&contact_dir, &xml);
         break;
      }
      case '2':
      {
         ImportExportXmlExp xmlexp;
         dataImport.set_export(&contact_dir, &xmlexp);
         break;
      }
      case '3':
      {
         ImportExportCsv csv;
         dataImport.set_export(&contact_dir, &csv);
         break;
      }
   }
}

void ImportXchange(vector<Contact> *contact_dir, string fpath)
{
   ImportExport dataImport;
   ExportFactory factory;
   dataImport.get_import(contact_dir, &fpath, factory.GenerateImportExportObject(fpath));
}

void ArgumentParser (int argcount, char *argvalue[], vector<Contact> *contact_dir)
{
   char expformat = ' ';
   po::options_description desc("Allowed options");
   desc.add_options()
      ("help,h", "Dies ist ein Shit-Fucking Kontaktbuch.\n\n"
               "Damit kann man schubberdoll Namen, Adressen und Telefonnummern eintragen und in einem von drei Exportformaten exportieren.\n"
               "Ebenso kann es giga-galaktisch die exportierten Daten, importieren. Toll nicht?! \n\n\n"
               "Folgende Argumente können optional übergeben werden: [-o, --output] [-i, --input] \n\n\n"
               "-o, --output   :   1 = xml, 2 = xml expression, 3 = csv\n\n"
               "-i, --input    :   Pfadangabe jeder einzelnen Datei. Jede Dateiangabe muss mit -i oder --input beginnen; z.B. ~/Workspace/ExchangeData")
      ("input,i", po::value<vector<string>>(), "input data or path")
      ("output,o", po::value<char>(&expformat)-> default_value('1'), "output format");

   po::variables_map vm;
   po::store(po::parse_command_line(argcount, argvalue, desc),vm);
   po::notify(vm);
   // po::parsed_options()
   if (vm.count("help"))
   {
      cout<<desc<<endl;
      exit(-1);
   }

   if(argcount > 1)
   {
      if (vm.count("input"))
      {
         // for(int i = 0; i < vm["input"].as< vector<string> >().size(); i++)   OLDSCHOOL!!!
         // {
         //  cout<<"Ja wo ist es denn??? " << vm["input"].as< vector<string> >().at(i)<<endl;
         // }
         for (auto strelement : vm["input"].as< vector<string> >())
         {
            cout<<"Schleife ala C++11 => "<<strelement<<endl;
         }
         ImportXchange(contact_dir, vm["input"].as< vector<string> >().at(0));
         //cout<<"Ja wo ist es denn??? " << vm["input"].as< vector<string> >().at(0)<<endl;
      }

      if (vm.count("output"))
      {
            cout<<"Output => "<<expformat<<endl;
      }
   }
}
