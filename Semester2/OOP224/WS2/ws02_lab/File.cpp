/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS02_LAB
Date: 2021/01/27

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }
   //TODO: read functions go here    
   bool read(char* m_name)
   {
       bool result;
       if (fscanf(fptr, "%[^\n]\n", m_name) == 1)
       {
           result = true;
       }
       else
       {
           result = false;
       }
       return result;
   }
   bool read(int& m_empNo)
   {
       bool result;
       if (fscanf(fptr, "%d,", &m_empNo) == 1)
       {
           result = true;
       }
       else
       {
           result = false;
       }
       return result;
   }
   bool read(double& m_salary)
   {
       bool result;
       if (fscanf(fptr, "%lf,", &m_salary) == 1)
       {
           result = true;
       }
       else
       {
           result = false;
       }
       return result;
   }
   
}