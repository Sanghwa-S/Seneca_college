/* Citation and Sources...
Final Project Milestone 1
Module: IOAble
Filename: IOAble.cpp
Version 2.0
Author	SANGHWA SUH
Revision History
-----------------------------------------------------------
Date      2020/03/18
2020/?/?  Preliminary release
2020/?/?  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#include <iostream>
#include <stdio.h>
#include<fstream>
#include <cstring>
#include "IOAble.h"
using namespace std;
namespace sdds
{

    std::ostream& IOAble::csvWrite(std::ostream& a) const
    {
        return a;
    }

    std::istream& IOAble::csvRead(std::istream& b)
    {
        return b;
    }

    std::ostream& IOAble::write(std::ostream& c) const
    {
        return c;
    }

    std::istream& IOAble::read(std::istream& d)
    {
        return d;
    }

    IOAble::~IOAble()
    {

    }

    istream& operator>>(istream& in, IOAble& obj)
    {
        return obj.read(in);
    }

    ostream& operator<<(ostream& out, IOAble& obj)
    {
        return obj.write(out);
    }

}