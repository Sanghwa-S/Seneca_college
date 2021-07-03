/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iomanip>
#include <iostream>
#include <string.h>
#include "Line.h"
using namespace std;
namespace sdds
{
    //Constructors
    Line::Line()
    {
        m_length = 0;
    }
    Line::Line(const char* Cstring, int length) : LblShape(Cstring)
    {
        m_length = length;

    }

    //Destructor
    //This class has no destructor implemented.

    //Overriding of the Shape's func
    void Line::getSpecs(std::istream& in)
    {
        LblShape::getSpecs(in);
        in >> m_length;
        in.ignore(100, '\n');
    }
    void Line::draw(std::ostream& o)const
    {
        if (m_length > 0 && label() != nullptr)
        {
            o << label() << endl;
            for (int i = 0; i < m_length; i++)
            {
                o << "=";
            }
        }
        else
        {

        }
    }
}