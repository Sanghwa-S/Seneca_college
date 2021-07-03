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
#include <string>
#include "LblShape.h"
using namespace std;
namespace sdds
{

    const char* LblShape::label()const
    {
        return m_label;
    }
    
    //constructors
    LblShape::LblShape()
    {
        m_label = nullptr;
    }

    LblShape::LblShape(const char* Cstring)
    {
        m_label = nullptr;
        m_label = new char[strlen(Cstring) + 1];
        strcpy(m_label, Cstring);
    }

    //destructor
    LblShape::~LblShape()
    {
        delete[] m_label;
        m_label = nullptr;
    }

    void LblShape::getSpecs(istream& in)
    {
        string cstr;
        std::getline(in, cstr , ',');
        delete[] m_label;
        m_label = nullptr;
        m_label = new char[strlen(cstr.c_str()) + 1];
        strcpy(m_label, cstr.c_str());
    }

}
