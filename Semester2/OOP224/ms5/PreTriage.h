/* Citation and Sources...
Final Project Milestone 3
Module: PRETRIAGE
Filename: PRETRIAGE.cpp
Version 5.0
Author	SANGHWA SUH
Revision History
-----------------------------------------------------------
Date      2020/04/05
2020/?/?  Preliminary release
2020/3/24  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <iostream>
#include "IOAble.h"
#include "Ticket.h"
#include "Patient.h"
#include "Menu.h"
#ifndef SDDS_PRETRIAGE_H_
#define SDDS_PRETRIAGE_H_
namespace sdds
{
    const int maxNoOfPatients = 100;
    class PreTriage
    {
        Time
            m_averCovidWait,
            m_averTriageWait;
        Patient* m_lineup[maxNoOfPatients]{};
        char* m_dataFilename = nullptr;
        int m_lineupSize = 0;
        Menu
            m_appMenu,
            m_pMenu;
        void reg();
        void admit();
        const Time getWaitTime(const Patient& p)const;
        void setAverageWaitTime(const Patient& p);
        void removePatientFromLineup(int index);
        int indexOfFirstInLine(char type) const;
        void load();
    public:
        PreTriage(const char* dataFilename);
        ~PreTriage();
        void run(void);
    };
}
#endif // !SDDS_PRETRIAGE_H_