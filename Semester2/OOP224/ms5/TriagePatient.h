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
#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H
#include <iostream>
#include "IOAble.h"
#include "Patient.h"

namespace sdds {
    class TriagePatient : public Patient
    {
        char* symptoms;
    public:
        TriagePatient();
        ~TriagePatient();
        virtual char type() const;
        virtual ostream& csvWrite(ostream&) const;
        virtual istream& csvRead(istream&);
        virtual ostream& write(ostream&) const;
        virtual istream& read(istream&);
    };
}
#endif // !SDDS_TRIAGEPATIENT_H


