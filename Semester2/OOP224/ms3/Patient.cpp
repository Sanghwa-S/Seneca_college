/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.cpp
Version 2.0
Author	SANGHWA SUH
Revision History
-----------------------------------------------------------
Date      2020/03/24
2020/?/?  Preliminary release
2020/3/24  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <string>
#include "Patient.h"
#include "utils.h"
using namespace std;
namespace sdds
{

    char Patient::type() const
    {
        char ch = 'W';
        return ch;
    }

    Patient::Patient(int ticketNumber, bool fileIO) :ticketObj(ticketNumber)
    {
        p_name = nullptr;
        p_num = 0;
        flag = fileIO;
    }

    Patient::~Patient()
    {
        delete[] p_name;
        p_name = nullptr;
    }

    bool Patient::fileIO() const
    {
        return flag;
    }

    void Patient::fileIO(bool val)
    {
        flag = val;
    }

    bool operator==(const Patient& P, const char ch)
    {
        return P.type() == ch;
    }

    bool operator==(const Patient& P1, const Patient& P2)
    {
        return P1.type() == P2.type();
    }

    Patient::operator Time()const
    {
        return Time(ticketObj);
    }

    void Patient::setArrivalTime()
    {
        ticketObj.resetTime();
    }

    int Patient::number() const
    {
        return ticketObj.number();
    }
    ostream& Patient::csvWrite(ostream& ostr)const
    {
        ostr << type() << "," << p_name << "," << p_num << ",";
        ticketObj.csvWrite(ostr);
        return ostr;
    }

    istream& Patient::csvRead(istream& istr)
    {
        string name;
        getline(istr, name, ',');
        delete[] p_name;
        p_name = nullptr;
        p_name = new char[strlen(name.c_str()) + 1];
        strcpy(p_name, name.c_str());
        istr >> p_num;
        istr.ignore(1000, ',');
        ticketObj.csvRead(istr);
        return istr;
    }

    ostream& Patient::write(ostream& ostr)const
    {
        int i = 0;
        ticketObj.write(ostr);
        ostr << endl;
        if (strlen(p_name) > 25)
        {
            for (i = 0; i < 25; i++)
            {
                ostr << p_name[i];
            }
        }
        else
        {
            ostr << p_name;
        }

        ostr << ", OHIP: " << p_num;
        return ostr;
    }

    istream& Patient::read(istream& istr)
    {
        string name;
        int num;
        cout << "Name: ";
        getline(istr, name, '\n');
        delete[] p_name;
        p_name = nullptr;
        p_name = new char[strlen(name.c_str()) + 1];
        strcpy(p_name, name.c_str());
        cout << "OHIP:";
        num = getInt(100000000, 999999999, nullptr, "Invalid OHIP Number, ", true);
        p_num = num;
        return istr;
    }

}