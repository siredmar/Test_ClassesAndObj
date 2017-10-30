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

using namespace std;

vector<Person> vecPersDir;
vector<address> vecAddress;

bool bSort(Person a, Person b)
{
   bool bReturn;
   char chA, chB = ' ';
   chA = a.get_Name().front();
   chB = b.get_Name().front();

   for (unsigned int i=0; i<a.get_Name().length(); i++)
   {
      if (chA <= chB) bReturn=true;
      else bReturn=false;
   }

   return bReturn; 
}

int main()
{  
   string sInpName, sInpPhone, sInpStreet, sInpPostCode, sInpCountry = "";
   char chInput = '0';
   bool bEingabe = true;
   ofstream outputFile;
   unsigned int iID = 0;
   unsigned int iCntID = 0;
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
      cin>>chInput;
      if(chInput == '1')   //Input data
      {
         bool bTemp = false;
         char chTemp = ' ';
         do
         {
            if(vecPersDir.size() != 0) //Check if is anything in the vector
            {
               iCntID = vecPersDir.back().get_ID() + 1;
               cout<<"\t Check Couter - "<<iCntID<<endl;
            }
            cout<<endl<<"Eingabe Name und Telefon"<<endl<<endl;
            cout<<"Name: ";
            cin.ignore();
            getline(cin,sInpName);
            cin.clear();
            cout<<"Telefon: ";
            cin.ignore(0);
            getline(cin,sInpPhone);
            vecPersDir.push_back(Person(sInpName, sInpPhone, iCntID));
            std::sort(vecPersDir.begin(), vecPersDir.end(), bSort);
            
            cout<<endl<<"Adresse?  j/n    ";
            cin>>chTemp;
            cin.clear();
            if (chTemp != 'j')
            {
               bTemp = true;
            }
            else
            {
               cout<<endl<<"Strasse: ";
               cin.ignore();
               getline(cin, sInpStreet);
               cin.clear();
               cout<<endl<<"PLZ: ";
               cin.ignore(0);
               getline(cin, sInpPostCode);
               cin.clear();
               cout<<endl<<"Stadt: ";
               cin.ignore(0);
               getline(cin, sInpCountry);

               vecAddress.push_back(address(sInpStreet, sInpPostCode, sInpCountry, iCntID));
            }
            cin.clear();
            cout<<endl<<"Eingabe weiterer Daten?  j/n"<<endl;
            cin>>chTemp;
            if (chTemp != 'j')
            {
               bTemp = true;
            }
            
         }while(bTemp == false);
      }
      else if(chInput == '2') //Output data
      {
         cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
         cout<<"Eintrag:"<<endl<<endl;
         for (int i=0; i<vecPersDir.size(); i++)
         {
            iID = vecPersDir.at(i).get_ID();
            cout<<vecPersDir.at(i).get_Name()<<endl<<"Tel.: "<<vecPersDir.at(i).get_Phone()<<endl;
            for (int m=0; m<vecAddress.size(); m++)
            {
               if(iID == vecAddress.at(m).get_ID())
               {
                  cout<<"Adresse:"<<endl<<vecAddress.at(m).get_street()<<endl<<vecAddress.at(m).get_postalcode()<<" "<<vecAddress.at(m).get_country()<<endl<<endl;
               }
            }
         }
         cout<<endl;
      }
      else if(chInput == '3') //Change data
      {
         cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
         cout<<"Einträge:"<<endl<<endl;
         for (int i=0; i<vecPersDir.size(); i++)
         {
            iID = vecPersDir.at(i).get_ID();
            cout<<i<<" : "<<vecPersDir.at(i).get_Name()<< "\t" <<vecPersDir.at(i).get_Phone()<<endl;
            for (int m=0; m<vecAddress.size(); m++)
            {
               if(iID == vecAddress.at(m).get_ID())
               {
                  cout<<"Adresse:"<<endl<<vecAddress.at(m).get_street()<<endl<<vecAddress.at(m).get_postalcode()<<" "<<vecAddress.at(m).get_country()<<endl<<endl;
               }
            }
         }
         char chName = ' ';
         char chPhone = ' ';
         char chAddress = ' ';
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
         cin>>chAddress;
         if (chName == 'j')
         {
            cout<<endl<<endl<<"Name: ";
            cin.ignore();
            getline(cin, sInpName);
            sInpPhone = vecPersDir.at(iInput).get_Phone();
            iID = vecPersDir.at(iInput).get_ID();
            vecPersDir.erase(vecPersDir.begin()+iInput);
            vecPersDir.insert(vecPersDir.begin()+iInput, Person(sInpName, sInpPhone, iID));
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
            getline(cin, sInpPhone);
            sInpName = vecPersDir.at(iInput).get_Name();
            iID = vecPersDir.at(iInput).get_ID();
            vecPersDir.erase(vecPersDir.begin()+iInput);
            vecPersDir.insert(vecPersDir.begin()+iInput, Person(sInpName, sInpPhone, iID));
         }
         if (chAddress == 'j')
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
            getline(cin,sInpStreet);
            cout<<endl<<"PLZ: ";
            cin.ignore(0);
            getline(cin,sInpPostCode);
            cout<<endl<<"Stadt: ";
            cin.ignore(0);
            getline(cin,sInpCountry);
            iID = vecPersDir.at(iInput).get_ID();
            vecAddress.erase(vecAddress.begin()+iInput);
            vecAddress.insert(vecAddress.begin()+iInput, address(sInpStreet, sInpPostCode, sInpCountry, iID));
         }
      }
      else if(chInput == '4') //Delete data
      {
         cout<<"AUSGABE TELEFONBUCH"<<endl<<endl;
         cout<<"Einträge:"<<endl<<endl;
         for (int i=0; i<vecPersDir.size(); i++)
         {
            cout<<i<<": "<<vecPersDir.at(i).get_Name()<< "\t" <<vecPersDir.at(i).get_Phone()<<endl;
         }
         int iInput = 0;
         cout<<endl;
         cout<<"Welcher Eintrag soll gelöscht werden?"<<endl;
         cout<<endl<<"Nummer: ";
         cin.clear();
         cin>>iInput;
         vecPersDir.erase(vecPersDir.begin()+iInput);
         if(vecAddress.size() != 0) //Check if is anything in the vector
         {
            vecAddress.erase(vecAddress.begin()+iInput);
         }
      }
      else if(chInput == '5') //Export to txt
      {
         outputFile.open ("outputFile.txt");
         for(int i=0; i<vecPersDir.size(); i++)
         {
            iID = vecPersDir.at(i).get_ID();
            outputFile<<vecPersDir.at(i).get_Name()<< "," <<vecPersDir.at(i).get_Phone();
            for (int m=0; m<vecAddress.size(); m++)
            {
               if(iID == vecAddress.at(m).get_ID())
               {
                  outputFile<<"|"<<vecAddress.at(m).get_street()<<";"<<vecAddress.at(m).get_postalcode()<<"_"<<vecAddress.at(m).get_country();
               }
            }
            outputFile<<endl;
         }
         outputFile.close();
      }
      else if(chInput == '6') //Import from txt
      {
         string sInpData;
         int iCntName = 0;
         int iCntPhone = 0;
         int iCntAddress = 0;
         int iLenght = 0;
         ifstream inpFile ("outputFile.txt");
         if (inpFile.is_open())
         {
            while(getline(inpFile, sInpData))
            {
               std::size_t found = sInpData.find(',');
               std::size_t found2 = sInpData.find('|');
               std::size_t found3 = sInpData.find(';');
               std::size_t found4 = sInpData.find('_');
               sInpName = sInpData.substr(0,found);
               if(sInpName != "")
               {
                  iCntName++;
               }
               iLenght = found2 - found;
               sInpPhone = sInpData.substr(found + 1, iLenght-1);
               if(sInpName != "")
               {
                  iCntPhone++;
               }
               iLenght = found3 - found2;
               sInpStreet = sInpData.substr(found2 + 1, iLenght-1);
               iLenght = found4 - found3;
               sInpPostCode = sInpData.substr(found3 + 1, iLenght-1);
               sInpCountry = sInpData.substr(found4 + 1);
               if(sInpCountry != "")
               {
                  iCntAddress++;
               }
               if(vecPersDir.size() != 0) //Check if is anything in the vector
               {
                  iCntID = vecPersDir.back().get_ID() + 1;
               }
               vecPersDir.push_back(Person(sInpName, sInpPhone, iCntID));
               std::sort(vecPersDir.begin(), vecPersDir.end(), bSort);
               vecAddress.push_back(address(sInpStreet, sInpPostCode, sInpCountry, iCntID));
            }
            inpFile.close();
            cout<<"Es wurden "<<iCntName<<" Namen, "<<iCntPhone<<" Nummern "<<"und "<<iCntAddress<<" Adressen eingetragen."<<endl;
         }
         else cout<<"Datei kann nicht geöffnet werden.";
      }
      else if(chInput == '7') //End
      {
         bEingabe = false;
      }
      else
      {
         cout<<endl<<"W.T.F you put into???"<<endl
                   <<"Only 1 - 7!"<<endl<<endl;
      }

   }while(bEingabe == true);
}