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
#ifndef IOAble_hpp
#define IOAble_hpp

#include <stdio.h>
#include<fstream>
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds
{
    // IOAble class

    class IOAble
    {

        // All Required pure virtual functions

    public:
        virtual ostream& csvWrite(ostream&) const = 0;

        virtual istream& csvRead(istream&) = 0;

        virtual ostream& write(ostream&) const = 0;

        virtual istream& read(istream&) = 0;

        virtual ~IOAble() = 0;
    };

    // Overloading extraction & insertion operator

    istream& operator>>(istream& in, IOAble& obj);

    ostream& operator<<(ostream& out, IOAble& obj);
}

#endif