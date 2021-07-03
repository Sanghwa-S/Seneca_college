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
#define _CRT_SECURE_NO_WARNINGS
#include "PreTriage.h"
#include "CovidPatient.h"
#include "TriagePatient.h"
#include "utils.h"
#include "Time.h"
#include <iostream>
#include <cstring>
#include <fstream>
using namespace std;
namespace sdds
{

    PreTriage::PreTriage(const char* dataFilename) :m_averCovidWait(15), m_averTriageWait(5), m_appMenu("General Hospital Pre-Triage Application\n1- Register\n2- Admit", 2), m_pMenu("Select Type of Admittance:\n1- Covid Test\n2- Triage", 2)
    {
        m_dataFilename = new char[strlen(dataFilename) + 1];
        strcpy(m_dataFilename, dataFilename);
        load();
    }

    PreTriage::~PreTriage()
    {
        ofstream fout;
        int i;
        fout.open(m_dataFilename);
        if (fout.is_open()) 
        {
            fout << m_averCovidWait << "," << m_averTriageWait << endl;
            cout << "Saving Average Wait Times," << endl;
            cout << "   COVID Test: " << m_averCovidWait << endl;
            cout << "   Triage: " << m_averTriageWait << endl;
            cout << "Saving m_lineup..." << endl;

            for (i = 0; i < m_lineupSize; i++)
            {
                m_lineup[i]->csvWrite(fout) << endl;
                cout << i + 1 << "- ";
                m_lineup[i]->csvWrite(cout) << endl;
                delete m_lineup[i];
            }

            delete[] m_dataFilename;
            cout << "done!" << endl;
        }
    }

    const Time PreTriage::getWaitTime(const Patient& p) const
    {
        int count = 0;
        for (int i = 0; i < m_lineupSize; i++) {
            if (m_lineup[i]->type() == p.type()) count++;
        }
        return Time(p) *= count;
    }

    void PreTriage::setAverageWaitTime(const Patient& p)
    {
        Time CT;
        unsigned int ticketNum = p.number();
        CT.setToNow();
        if (p.type() == 'C') {
            m_averCovidWait = ((CT - p.operator Time()) + (m_averCovidWait * (ticketNum - 1))) / ticketNum;
        }
        else if (p.type() == 'T') {
            m_averTriageWait = ((CT - p.operator Time()) + (m_averTriageWait * (ticketNum - 1))) / ticketNum;
        }
    }

    void PreTriage::removePatientFromLineup(int index)
    {
        removeDynamicElement<Patient>(m_lineup, index, m_lineupSize);
    }

    int PreTriage::indexOfFirstInLine(char type) const
    {
        int i;
        for (i = 0; i < maxNoOfPatients; i++) {
            if (m_lineup[i]->type() == type)
            {
                return i;
            }
               
        }
        return -1;
    }

    void PreTriage::load()
    {
        char ch;
        int i;
        ifstream fin;

        fin.open(m_dataFilename);
        cout << "Loading data..." << endl;

        if (fin)
        {
            fin >> m_averCovidWait;
            fin.ignore(200, ',');
            fin >> m_averTriageWait;
            fin.ignore(200, '\n');
            Patient* p = nullptr;
            for (i = 0; i < maxNoOfPatients && fin; i++)
            {
                ch = 'x';
                fin >> ch;
                fin.ignore(100, ',');
                if (ch  == 'C')
                {
                    p = new CovidPatient();
                }
                else if (ch == 'T')
                {
                    p = new TriagePatient();
                }
                if (p != nullptr)
                {
                    p->fileIO(true);
                    p->csvRead(fin);
                    p->fileIO(false);
                    m_lineup[i] = p;
                    m_lineupSize++;
                    p = nullptr;
                }
            }
        }
        if (fin)
        {
            cout << "Warning: number of records exceeded " << maxNoOfPatients << endl;
            cout << m_lineupSize << " Records imported...\n\n";
        }
        else if (m_lineupSize == 0)
        {
            cout << "No data or bad data file!\n\n";
        }
        else
        {
            cout << m_lineupSize << " Records imported...\n\n";
        }
    }

    void PreTriage::reg()
    {

        if (m_lineupSize == maxNoOfPatients) {
            cout << "Line up full!" << endl;
        }
        else {
            int choice;
            m_pMenu >> choice;
            switch (choice) {
            case 0:
                break;
            case 1:
                m_lineup[m_lineupSize] = new CovidPatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                m_lineup[m_lineupSize]->fileIO(false);
                cout << "Please enter patient information: " << endl;
                cin >> *m_lineup[m_lineupSize];
                cout << endl;
                cout << "******************************************" << endl;
                cout << *m_lineup[m_lineupSize];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl << endl;
                m_lineupSize++;
                break;
            case 2:
                m_lineup[m_lineupSize] = new TriagePatient();
                m_lineup[m_lineupSize]->setArrivalTime();
                m_lineup[m_lineupSize]->fileIO(false);
                cout << "Please enter patient information: " << endl;
                cin >> *m_lineup[m_lineupSize];
                cout << endl;
                cout << "******************************************" << endl;
                cout << *m_lineup[m_lineupSize];
                cout << "Estimated Wait Time: " << getWaitTime(*m_lineup[m_lineupSize]) << endl;
                cout << "******************************************" << endl << endl;
                m_lineupSize++;
                break;
            }
        }
    }

    void PreTriage::admit()
    {
        int choice, index = 0;
        char ptype = '\0';
        m_pMenu >> choice;
        switch (choice) {
        case 1:
            ptype = 'C';
            if (indexOfFirstInLine(ptype) == -1)
            {
                return;
            }
            else {
                index = indexOfFirstInLine(ptype);
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[index]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[indexOfFirstInLine(ptype)];
                cout << "******************************************" << endl << endl;
                setAverageWaitTime(*m_lineup[index]);
                removePatientFromLineup(index);
            }
            break;
        case 2:
            ptype = 'T';
            if (indexOfFirstInLine(ptype) == -1)
            {
                return;
            }
            else {
                index = indexOfFirstInLine(ptype);
                cout << endl;
                cout << "******************************************" << endl;
                m_lineup[index]->fileIO(false);
                cout << "Calling for ";
                cout << *m_lineup[indexOfFirstInLine(ptype)];
                cout << "******************************************" << endl << endl;
                setAverageWaitTime(*m_lineup[index]);
                removePatientFromLineup(index);
            }
            break;
        case 0:
            break;
        }
    }

    void PreTriage::run(void)
    {
        int selection;
        while (m_appMenu >> selection) {
            switch (selection) {
            case 1:
                reg();
                break;
            case 2:
                admit();
                break;
            default:
                break;
            }
        }
    }
}