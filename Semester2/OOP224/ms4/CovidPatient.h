/* Citation and Sources...
Final Project Milestone 3
Module: CovidPatient
Filename: CovidPatient.cpp
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
#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"

namespace sdds {
    class CovidPatient : public Patient
    {
    public:
        CovidPatient();

        virtual char type() const;
        virtual istream& csvRead(istream&);
        virtual ostream& write(ostream&) const;
        virtual istream& read(istream&);
    };
}
#endif // !SDDS_COVIDPATIENT_H_



