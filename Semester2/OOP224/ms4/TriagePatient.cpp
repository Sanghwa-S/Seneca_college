/* 
Citation and Sources...
Final Project Milestone 3
Module: TriagePatient
Filename: TriagePatient.cpp
Version 4.0
Author	SANGHWA SUH
Revision History
-----------------------------------------------------------
Date      2020/03/30
2020/?/?  Preliminary release
2020/3/24  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include<cstring>
#include "TriagePatient.h"
#include "utils.h"
using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
   TriagePatient::TriagePatient() :Patient(nextTriageTicket, fileIO())
   {
       symptoms = nullptr;
       nextTriageTicket++;
   }

   TriagePatient::~TriagePatient()
   {
       delete[] symptoms;
       symptoms = nullptr;
   }

   char TriagePatient::type() const
   {
       return 'T';
   }

   ostream& TriagePatient::csvWrite(ostream& ostr)const
   {
       Patient::csvWrite(ostr);
       ostr << "," << symptoms;
       return ostr;
   }

   istream& TriagePatient::csvRead(istream& istr)
   {
       string name;
       delete[] symptoms;
       Patient::csvRead(istr);
       istr.ignore(600, ',');
       getline(istr, name, '\n');
       symptoms = nullptr;
       symptoms = new char[strlen(name.c_str()) + 1];
       strcpy(symptoms, name.c_str());
       nextTriageTicket = (Patient::number() + 1);
       return istr;
   }

   ostream& TriagePatient::write(ostream& ostr)const
   {
       if (fileIO())csvWrite(ostr);
       else {
           ostr << "TRIAGE" << endl;
           Patient::write(ostr) << endl;
           ostr << "Symptoms: " << symptoms << endl;
       }
       return ostr;
   }

   istream& TriagePatient::read(istream& istr)
   {
       if (fileIO())
       {
           csvRead(istr);
       }
       else 
       {
           delete[] symptoms;
           symptoms = nullptr;
           Patient::read(istr);
           symptoms = getcstr("Symptoms: ", istr, '\n');
       }
       return istr;
   }
}
