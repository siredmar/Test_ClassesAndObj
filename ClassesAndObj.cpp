#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>
#include <iostream>
#include <fstream>
#include "Person.h"
#include "Address.h"
#include "PhoneBook.h"

using namespace std;

vector<Person> person_directory;
vector<address> address_directory;

bool bSort(Person a, Person b)
{
   bool sorted_return;
   char firstletter_a = ' '; 
   char firstletter_b = ' ';
   firstletter_a = a.get_Name().front();
   firstletter_b = b.get_Name().front();

   for (unsigned int i=0; i<a.get_Name().length(); i++)
   {
      if (firstletter_a <= firstletter_b) sorted_return=true;
      else sorted_return=false;
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
      if(selection == '1')   //Input data
      {
         bool temp_state = false;
         char temp_select = ' ';
         do
         {
            cout<<endl<<"Eingabe Name und Telefon"<<endl<<endl;
            cout<<"Name: ";
            cin.ignore();
            getline(cin,inp_name);
            cin.clear();
            cout<<"Telefon: ";
            cin.ignore(0);
            getline(cin,inp_phone_mobile);
            person_directory.push_back(Person(inp_name, inp_phone_mobile));
            std::sort(person_directory.begin(), person_directory.end(), bSort);
            
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

               address_directory.push_back(address(inp_street, inp_postcode, inp_country));
            }
            cin.clear();
            cout<<endl<<"Eingabe weiterer Daten?  j/n"<<endl;
            cin>>temp_select;
            if (temp_select != 'j')
            {
               temp_state = true;
            }
            
         }while(temp_state == false);
      }
      else if(selection == '2') //Output data
      {
         cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
         cout<<"Eintrag:"<<endl<<endl;
         for (int i=0; i<person_directory.size(); i++)
         {
            cout<<person_directory.at(i).get_Name()<<endl<<"Tel.: "<<person_directory.at(i).get_Phone()<<endl;
         }
         cout<<endl;
      }
      else if(selection == '3') //Change data
      {
         cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
         cout<<"Einträge:"<<endl<<endl;
         for (int i=0; i<person_directory.size(); i++)
         {
            cout<<i<<" : "<<person_directory.at(i).get_Name()<< "\t" <<person_directory.at(i).get_Phone()<<endl;
         }
         char chName = ' ';
         char chPhone = ' ';
         char firstletter_address = ' ';
         int iInput = 0;
         cout<<endl;
         cout<<"Welcher Eintrag soll geändert werden?"<<endl<<endl;
         cin.clear();
         cin>>iInput;
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
            cout<<endl<<endl<<"Name: ";
            cin.ignore();
            getline(cin, inp_name);
            inp_phone_mobile = person_directory.at(iInput).get_Phone();
            person_directory.erase(person_directory.begin()+iInput);
            person_directory.insert(person_directory.begin()+iInput, Person(inp_name, inp_phone_mobile));
         }
         if (chPhone == 'j')
         {
            cout<<endl<<endl<<"Phone: ";
            if (chName == 'j') 
            { 
               cin.ignore(0); 
            }
            else 
            { 
               cin.ignore(); 
            }
            getline(cin, inp_phone_mobile);
            inp_name = person_directory.at(iInput).get_Name();
            person_directory.erase(person_directory.begin()+iInput);
            person_directory.insert(person_directory.begin()+iInput, Person(inp_name, inp_phone_mobile));
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
            address_directory.erase(address_directory.begin()+iInput);
            address_directory.insert(address_directory.begin()+iInput, address(inp_street, inp_postcode, inp_country));
         }
      }
      else if(selection == '4') //Delete data
      {
         cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
         cout<<"Einträge:"<<endl<<endl;
         for (int i=0; i<person_directory.size(); i++)
         {
            cout<<i<<": "<<person_directory.at(i).get_Name()<< "\t" <<person_directory.at(i).get_Phone()<<endl;
         }
         int iInput = 0;
         cout<<endl;
         cout<<"Welcher Eintrag soll gelöscht werden?"<<endl;
         cout<<endl<<"Nummer: ";
         cin.clear();
         cin>>iInput;
         person_directory.erase(person_directory.begin()+iInput);
      }
      else if(selection == '5') //Export to txt
      {
         outputFile.open ("outputFile.txt");
         for(int i=0; i<person_directory.size(); i++)
         {
            outputFile<<person_directory.at(i).get_Name()<< "," <<person_directory.at(i).get_Phone();
            outputFile<<endl;
         }
         outputFile.close();
      }
      else if(selection == '6') //Import from txt
      {
         string inp_Data;
         int iCntName = 0;
         int iCntPhone = 0;
         int iCntAddress = 0;
         int iLenght = 0;
         ifstream inpFile ("outputFile.txt");
         if (inpFile.is_open())
         {
            while(getline(inpFile, inp_Data))
            {
               std::size_t found = inp_Data.find(',');
               std::size_t found2 = inp_Data.find('|');
               std::size_t found3 = inp_Data.find(';');
               std::size_t found4 = inp_Data.find('_');
               inp_name = inp_Data.substr(0,found);
               if(inp_name != "")
               {
                  iCntName++;
               }
               iLenght = found2 - found;
               inp_phone_mobile = inp_Data.substr(found + 1, iLenght-1);
               if(inp_name != "")
               {
                  iCntPhone++;
               }
               iLenght = found3 - found2;
               inp_street = inp_Data.substr(found2 + 1, iLenght-1);
               iLenght = found4 - found3;
               inp_postcode = inp_Data.substr(found3 + 1, iLenght-1);
               inp_country = inp_Data.substr(found4 + 1);
               if(inp_country != "")
               {
                  iCntAddress++;
               }
               person_directory.push_back(Person(inp_name, inp_phone_mobile));
               std::sort(person_directory.begin(), person_directory.end(), bSort);
               address_directory.push_back(address(inp_street, inp_postcode, inp_country));
            }
            inpFile.close();
            cout<<"Es wurden "<<iCntName<<" Namen, "<<iCntPhone<<" Nummern "<<"und "<<iCntAddress<<" Adressen eingetragen."<<endl;
         }
         else cout<<"Datei kann nicht geöffnet werden.";
      }
      else if(selection == '7') //End
      {
         entry = false;
      }
      else
      {
         cout<<endl<<"W.T.F you put into???"<<endl
                   <<"Only 1 - 7!"<<endl<<endl;
      }

   }while(entry == true);
}