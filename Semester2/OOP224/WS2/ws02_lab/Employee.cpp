/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS02_LAB
Date: 2021/01/27

----------------------------------------------
---------------------------------------------- */
#include <iostream>
#include "cstring.h"// implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"

using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // TODO: Finish the implementation of the 1 arg load function which
   // reads one employee record from the file and loads it into the employee reference
   // argument
   bool load(Employee& employees) 
   {
      bool ok = false;
      char name[128];

      if (read(employees.m_empNo))
      {
          if (read(employees.m_salary))
          {
              if (read(name))
              {
                  employees.m_name = new char[strLen(name) + 1];
                  strCpy(employees.m_name, name);
                  ok = true;
              }
          }
      }
      return ok;
   }
   // TODO: Finish the implementation of the 0 arg load function 
   bool load() 
   {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) 
      {

          //Set the noOfEmployees to the number of recoreds in the file.
          noOfEmployees = noOfRecords();
          
           
          //dyanamically allocated an array of employees into the global
          //Employee pointer; "employees" to the size of the noOfEmployees.
          employees = new Employee[noOfEmployees];
          //In a loop load the employee records from the file into 
          //the dynamic array
          for (i = 0; i < noOfEmployees; i++) 
          {
                  load(employees[i]);
          }
          //If the number of the records does not match the number of reads
            // print the message
            //"Error: incorrect number of records read; the data is possibly corrupted"
          //Otherwise
             //set the ok flag to true
          //End if

          //close the file
          if (i != noOfEmployees) 
          {
              cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
          }
          else {
              ok = true;
          }
          closeFile();
      }
      
      else 
      {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      return ok;
   }

   // TODO: Implementation for the display functions go here
   void display(const Employee& employees)
   {
       cout << employees.m_empNo << ": " << employees.m_name << ", " << employees.m_salary << endl;
   }

   void display()
   {
       cout << "Employee Salary report, sorted by employee number" << endl;
       cout << "no- Empno, Name, Salary" << endl;
       cout << "------------------------------------------------" << endl;
       sort();
       for (int i = 0; i < noOfEmployees; i++) 
       {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   // TODO: Implementation for the deallocateMemory function goes here
   void deallocateMemory()
   {
       for (int i = 0; i < noOfEmployees; i++)
       {
           delete[] employees[i].m_name;
       }
       delete[] employees;
       employees = nullptr;
   }

}


