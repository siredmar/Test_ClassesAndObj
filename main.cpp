#include <stdio.h>
#include <string>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <fstream>
#include "Contact.h"
#include "pugixml.hpp"
#include "ImportExport.h"
#include "ImportExportXml.h"
#include "ImportExportXmlExp.h"
#include "ImportExportCsv.h"

using namespace std;

bool bSort(Contact a, Contact b);

void PrintOutDirectory(vector<Contact> cont_dir , char extension);


int main()
{  
   //Names for class Person
   string inp_firstname = ""; 
   string inp_surname = "";
   //Names for class PhoneBook
   string inp_phone_privat = "";
   string inp_phone_work = "";
   string inp_phone_mobile = "";
   //Names for class Address
   string inp_street = "";
   string inp_postcode = "";
   string inp_country = "";
   
   char selection = '0';
   bool entry = true;
   ofstream outputFile;

   vector<Contact> contact_directory;
   ImportExport dataExport;
   ImportExport dataImport;
   ImportExportXmlExp xml;

   do
   {
      cout<<"Auswahl: " << endl;
      cout<<"1 = Eingabe Daten"<<endl;
      cout<<"2 = Ausgabe Daten"<<endl;
      cout<<"3 = Eingabe ändern"<<endl;
      cout<<"4 = Eingabe löschen"<<endl;
      cout<<"5 = Import from txt"<<endl;
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
            dataExport.set_export(&contact_directory, &xml);
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
               
               dataExport.set_export(&contact_directory, &xml);
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

            dataExport.set_export(&contact_directory, &xml);

            break;
         }
         case '5': //Import from txt
         {
            string filep = "output_file.xml";

            dataImport.get_import(&contact_directory, &filep, &xml);

            std::sort(contact_directory.begin(), contact_directory.end(), bSort);
            // string inp_data;
            // int cnt_name = 0;
            // int cnt_phone = 0;
            // int cnt_address = 0;
            // int lenght = 0;
            // ifstream inp_file ("outputFile.txt");
            // if (inp_file.is_open())
            // {
            //    while(getline(inp_file, inp_data))
            //    {
            //       std::size_t found = inp_data.find('-');
            //       std::size_t found2 = inp_data.find('|');
            //       std::size_t found3 = inp_data.find(',');
            //       std::size_t found4 = inp_data.find('_');
            //       inp_firstname = inp_data.substr(0,found);
            //       if(inp_firstname != "")
            //       {
            //          cnt_name++;
            //       }
            //       lenght = found2 - found;
            //       inp_surname = inp_data.substr(found + 1, lenght-1);
                  
            //       lenght = found3 - found2;
            //       inp_street = inp_data.substr(found2 + 1, lenght-1);
            //       lenght = found4 - found3;
            //       inp_postcode = inp_data.substr(found3 + 1, lenght-1);
            //       inp_country = inp_data.substr(found4 + 1);
            //       if(inp_country != "")
            //       {
            //          cnt_address++;
            //       }


            //       contact_directory.push_back(Contact(Person(inp_firstname, inp_surname), 
            //                                           Address(inp_street, inp_postcode, inp_country), 
            //                                                 PhoneBook(inp_phone_privat, inp_phone_work, inp_phone_mobile)));
            //    std::sort(contact_directory.begin(), contact_directory.end(), bSort);
            //    }
            //    inp_file.close();
            //    cout<<"Es wurden "<<cnt_name<<" Namen, "<<cnt_phone<<" Nummern "<<"und "<<cnt_address<<" Adressen eingetragen."<<endl;
            // }
            // else cout<<"Datei kann nicht geöffnet werden.";
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
                     <<"Only 1 - 7!"<<endl<<endl;
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
      for (int i=0; i<cont_dir.size(); i++)
      {
         cout<<"Vorname = "<<cont_dir.at(i).get_person().get_firstname()<<endl;
         cout<<"Nachname = "<<cont_dir.at(i).get_person().get_surname()<<endl;

         cout<<"Adresse = "<<cont_dir.at(i).get_address().get_street() + "   " 
                                 + cont_dir.at(i).get_address().get_postalcode() + " "
                                             + cont_dir.at(i).get_address().get_country()<<endl;

         cout<<"Tel.Buch = "<<cont_dir.at(i).get_phonebook().get_num_privat() + "   "
                                 + cont_dir.at(i).get_phonebook().get_num_mobile() + "   " 
                                             + cont_dir.at(i).get_phonebook().get_num_work()<<endl;
      }
   }
   if (extension == 'y')
   {
      for (int i=0; i<cont_dir.size(); i++)
      {
         cout<<i<<":"<<endl;
         cout<<"Vorname = "<<cont_dir.at(i).get_person().get_firstname()<<endl;
         cout<<"Nachname = "<<cont_dir.at(i).get_person().get_surname()<<endl;
   
         cout<<"Adresse = "<<cont_dir.at(i).get_address().get_street() + "   " 
                                 + cont_dir.at(i).get_address().get_postalcode() + " "
                                             + cont_dir.at(i).get_address().get_country()<<endl;

         cout<<"Tel.Buch = "<<cont_dir.at(i).get_phonebook().get_num_privat() + "   " 
                                 + cont_dir.at(i).get_phonebook().get_num_mobile() + "   " 
                                             + cont_dir.at(i).get_phonebook().get_num_work()<<endl;
      }
   }
}
























// #include <stdio.h>
// #include <string.h>
// #include <stdlib.h>
// #include <algorithm>
// #include <functional>
// #include <iostream>
// #include <vector>
// #include <iostream>
// #include <fstream>
// #include "Contact.h"

// using namespace std;

// bool bSort(Contact a, Contact b)
// {
//    bool sorted_return;
//    char firstletter_a = ' ';
//    char secondletter_a = ' '; 
//    char firstletter_b = ' ';
//    char secondletter_b = ' ';
//    firstletter_a = a.get_person().get_firstname().front();
//    firstletter_b = b.get_person().get_firstname().front();
//    secondletter_a = a.get_person().get_firstname().at(1);
//    secondletter_b = b.get_person().get_firstname().at(1);

//    for (unsigned int i=0; i<a.get_person().get_firstname().length(); i++)
//    {
//       if (firstletter_a <= firstletter_b)
//       {
//          sorted_return=true;

//          if (firstletter_a == firstletter_b)
//          {
//             if (secondletter_a <= secondletter_b)
//             {
//                sorted_return=true;      
//             }
//             else
//             {
//                sorted_return=false;
//             }
//          }
//       } 
//       else 
//       {
//          sorted_return=false;
//       }
//    }
//    return sorted_return; 
// }

// int main()
// {
//    // Person person1("Florian","Schimmer");
//    // Address address1("Südwestpark 92", "90449", "Nürnberg");
//    // PhoneBook phonebook1("0911 25 50 976","","");
//    // Contact contact; 
//    vector<Contact> contact_directory;

//    // contact.set_person(person1);
//    // contact.set_address(address1);
//    // contact.set_phonebook(phonebook1);
//    string vorname;
//    string nachname;
//    string adresse;
//    string telbuch;
//    int repeat = 0;

//    do
//    {
//       cout<<endl<<"Eingabe Vorname u. Nachname"<<endl<<endl;
//       cout<<"Vorname: ";
//       getline(cin,vorname);
//       cin.clear();
//       cout<<"Nachname: ";
//       cin.ignore(0);
//       getline(cin,nachname);
//       cin.clear();
//       //contact.set_person(person1);
//       //contact_directory.push_back(contact);
//       contact_directory.push_back(Contact(Person(vorname, nachname), Address("Südwestpark 92", "90449", "Nürnberg"), PhoneBook("0911 25 50 976","","")));
//       std::sort(contact_directory.begin(), contact_directory.end(), bSort);
//       cout<<endl<<"Weiter? 1=nein 0=ja"<<endl;
//       cin>>repeat;
//       cin.clear(); 
//       cin.ignore();
//    }while (repeat==0);
//    for (int i=0; i<contact_directory.size(); i++)
//    {
//       vorname = contact_directory.at(i).get_person().get_firstname();
//       nachname = contact_directory.at(i).get_person().get_surname();

//       adresse = contact_directory.at(i).get_address().get_street() + "\t" + contact_directory.at(i).get_address().get_postalcode() + "\t" + contact_directory.at(i).get_address().get_country();
//       telbuch = contact_directory.at(i).get_phonebook().get_num_work() + "\t" + contact_directory.at(i).get_phonebook().get_num_privat() + "\t" + contact_directory.at(i).get_phonebook().get_num_mobile();
   
//       cout<<"Vorname = "<<vorname<<endl;
//       cout<<"Nachname = "<<nachname<<endl;
//       cout<<"Adresse = "<<adresse<<endl;
//       cout<<"Tel.Buch = "<<telbuch<<endl<<endl;
//    }

// }