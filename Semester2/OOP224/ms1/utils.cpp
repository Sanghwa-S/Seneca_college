/* Citation and Sources...
Final Project Milestone 1
Module: UTILS
Filename: UTILS.cpp
Version 1.0
Author	SANGHWA SUH
Revision History
-----------------------------------------------------------
Date      2020/03/17
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
using namespace std;
namespace sdds {
   bool debug = false;  // made global in utils.h
   int getTime() {  
      int mins = -1;
      if (debug) {
         Time t(0);
         cout << "Enter current time: ";
         do {
            cin.clear();
            cin >> t;   // needs extraction operator overloaded for Time
            if (!cin) {
               cout << "Invlid time, try agian (HH:MM): ";
               cin.clear();
            }
            else {
               mins = int(t);
            }
            cin.ignore(1000, '\n');
         } while (mins < 0);
      }
      else {
         time_t t = time(NULL);
         tm lt = *localtime(&t);
         mins = lt.tm_hour * 60 + lt.tm_min;
      }
      return mins;
   }
   
   int getInt(const char* prompt)
   {
       int value;
       bool badEntry;
       char nextChar;
       if (prompt != nullptr)
       {   
           cout << prompt;
       }
       do
       {
           badEntry = false;
           cin >> value;
           if (cin.fail())
           {
               cout << "Bad integer value, try again: ";
               cin.clear();
               cin.ignore(3000, '\n');
               badEntry = true;
           }

           else
           {
               nextChar = cin.get();
               if (nextChar != '\n')
               {
                   cout << "Enter only an integer, try again: ";
                   cin.ignore(3000, '\n');
                   badEntry = true;
               }
           }
       } while (badEntry);
       return value;
   }

   int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)
   {
       int value;
       value = getInt(prompt);
       if (value < min || value > max)
       {
           if (errorMessage != nullptr)
           {
               cout << errorMessage;
               if (showRangeAtError)
               {
                   cout << "[" << min << " <= value <= " << max << "]: ";
                   
               }
               value = getInt();
           }
       }
       return value;
   }


   char* getcstr(const char* prompt, istream& istr, char delimiter)
   {
       string temp;
       char* str = nullptr;
       if (prompt != nullptr)
       {
           cout << prompt;
           getline(istr, temp);
           str = new char[temp.length() + 2];
           strcpy(str, temp.c_str());
           str[temp.length()] = '\0' ;
           str[temp.length() + 1] = delimiter ;       }

       return str;
   }
}