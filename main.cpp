#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Contact.h"

using namespace std;

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

   do
   {
      cout<<"Auswahl: " << endl;
      cout<<"1 = Eingabe Daten"<<endl;
      cout<<"2 = Ausgabe Daten"<<endl;
      cout<<"3 = Eingabe ändern"<<endl;
      cout<<"4 = Eingabe löschen"<<endl;
      cout<<"5 = Export to txt"<<endl;
      cout<<"6 = Import from txt"<<endl;
      cout<<"7 = Ende"<<endl;
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
               contact_directory.push_back(Contact(Person(inp_firstname, inp_surname), (Address(inp_street, inp_postcode, inp_country)), PhoneBook(inp_phone_privat, inp_phone_work, inp_phone_mobile))), 
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
            break;
         }
         case '2': //Output data
         {
            cout<<endl<<" ##### AUSGABE ##### "<<endl<<endl;
            for (int i=0; i<contact_directory.size(); i++)
            {
               cout<<"Vorname = "<<contact_directory.at(i).get_person().get_firstname()<<endl;
               cout<<"Nachname = "<<contact_directory.at(i).get_person().get_surname()<<endl;
         
               cout<<"Adresse = "<<contact_directory.at(i).get_address().get_street() + "   " 
                                       + contact_directory.at(i).get_address().get_postalcode() + " "
                                                   + contact_directory.at(i).get_address().get_country()<<endl;

               cout<<"Tel.Buch = "<<contact_directory.at(i).get_phonebook().get_num_work() + "   " 
                                       + contact_directory.at(i).get_phonebook().get_num_privat() + "   " 
                                                   + contact_directory.at(i).get_phonebook().get_num_mobile()<<endl;
            }
            break;
         }
         case '3': //Change data
         {
            // T.B.D

            cout<<endl<<" ##### AUSGABE ##### "<<endl<<endl;
            for (int i=0; i<contact_directory.size(); i++)
            {
               cout<<i<<":"<<endl;
               cout<<"Vorname = "<<contact_directory.at(i).get_person().get_firstname()<<endl;
               cout<<"Nachname = "<<contact_directory.at(i).get_person().get_surname()<<endl;
         
               cout<<"Adresse = "<<contact_directory.at(i).get_address().get_street() + "   " 
                                       + contact_directory.at(i).get_address().get_postalcode() + " "
                                                   + contact_directory.at(i).get_address().get_country()<<endl;

               cout<<"Tel.Buch = "<<contact_directory.at(i).get_phonebook().get_num_work() + "   " 
                                       + contact_directory.at(i).get_phonebook().get_num_privat() + "   " 
                                                   + contact_directory.at(i).get_phonebook().get_num_mobile()<<endl;
            }
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
               //Einträge zwischen speichern
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
                  cin.ignore();
                  getline(cin, inp_surname);
                  // contact_directory.insert(contact_directory.begin()+iInput, Person(inp_firstname, inp_phone_mobile));
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
                  // inp_firstname = contact_directory.at(iInput).get_Name();
                  // contact_directory.erase(contact_directory.begin()+iInput);
                  // contact_directory.insert(contact_directory.begin()+iInput, Person(inp_firstname, inp_phone_mobile));
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
                  // address_directory.erase(address_directory.begin()+iInput);
                  // address_directory.insert(address_directory.begin()+iInput, address(inp_street, inp_postcode, inp_country));
               }
               contact_directory.erase(contact_directory.begin()+iInput);
               contact_directory.insert(contact_directory.begin()+iInput, Contact(Person(inp_firstname, inp_surname), 
                                                                                    Address(inp_street, inp_postcode, inp_country), 
                                                                                       PhoneBook(inp_phone_privat, inp_phone_work, inp_phone_mobile)));
            }
            break;
         }
         case '4': //Delete data
         {
            // T.B.D

            // cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
            // cout<<"Einträge:"<<endl<<endl;
            // for (int i=0; i<contact_directory.size(); i++)
            // {
            //    cout<<i<<": "<<contact_directory.at(i).get_Name()<< "\t" <<contact_directory.at(i).get_Phone()<<endl;
            // }
            // int iInput = 0;
            // cout<<endl;
            // cout<<"Welcher Eintrag soll gelöscht werden?"<<endl;
            // cout<<endl<<"Nummer: ";
            // cin.clear();
            // cin>>iInput;
            // contact_directory.erase(contact_directory.begin()+iInput);
            break;
         }
         case '5': //Export to txt
         {
            // T.B.D

            // outputFile.open ("outputFile.txt");
            // for(int i=0; i<contact_directory.size(); i++)
            // {
            //    outputFile<<contact_directory.at(i).get_Name()<< "," <<contact_directory.at(i).get_Phone();
            //    outputFile<<endl;
            // }
            // outputFile.close();
            break;
         }
         case '6': //Import from txt
         {
            // T.B.D

            // string inp_Data;
            // // int iCntName = 0;
            // // int iCntPhone = 0;
            // // int iCntAddress = 0;
            // // int iLenght = 0;
            // ifstream inpFile ("outputFile.txt");
            // if (inpFile.is_open())
            // {
            //    while(getline(inpFile, inp_Data))
            //    {
                  // std::size_t found = inp_Data.find(',');
                  // std::size_t found2 = inp_Data.find('|');
                  // std::size_t found3 = inp_Data.find(';');
                  // std::size_t found4 = inp_Data.find('_');
                  // inp_firstname = inp_Data.substr(0,found);
                  // if(inp_firstname != "")
                  // {
                  //    iCntName++;
                  // }
                  // iLenght = found2 - found;
                  // inp_phone_mobile = inp_Data.substr(found + 1, iLenght-1);
                  // if(inp_firstname != "")
                  // {
                  //    iCntPhone++;
                  // }
                  // iLenght = found3 - found2;
                  // inp_street = inp_Data.substr(found2 + 1, iLenght-1);
                  // iLenght = found4 - found3;
                  // inp_postcode = inp_Data.substr(found3 + 1, iLenght-1);
                  // inp_country = inp_Data.substr(found4 + 1);
                  // if(inp_country != "")
                  // {
                  //    iCntAddress++;
                  // }
                  // contact_directory.push_back(Person(inp_firstname, inp_phone_mobile));
                  // std::sort(contact_directory.begin(), contact_directory.end(), bSort);
                  // address_directory.push_back(address(inp_street, inp_postcode, inp_country));
            //    }
            //    inpFile.close();
            //    cout<<"Es wurden "<<iCntName<<" Namen, "<<iCntPhone<<" Nummern "<<"und "<<iCntAddress<<" Adressen eingetragen."<<endl;
            // }
            // else cout<<"Datei kann nicht geöffnet werden.";
            break;
         }
         case '7': //End
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