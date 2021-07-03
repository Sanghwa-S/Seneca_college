/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS04_DIY
Date: 2021/02/14

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include "cstring.h"
#include <iostream>
#include <iomanip>
#include "Label.h"
using namespace std;

namespace sdds
{
    void Label::setToDefault()
    {
        m_frameArg[0] = '\0';
        m_content = nullptr;
    }

    void Label::setFrame(const char* Cstr)
    {
        if (Cstr != nullptr && strLen(Cstr) == 8)
        {
            strCpy(m_frameArg, Cstr);
        }
    }

    void Label::setLabel(const char* Cstr)
    {
        if (Cstr != nullptr)
        {
            delete[] m_content;
            m_content = new char[strLen(Cstr) + 1];
            strCpy(m_content, Cstr);

            if (strLen(Cstr) > 70)
            {
                m_content[0] = '\0';
            }
        }
    }

    void Label::flushkeys()
    {
        while (cin.get() != '\n');
    }

    Label::Label()
    {
        setToDefault();
        setFrame("+-+|+-+|");
    }

    Label::Label(const char* frameArg)
    {
        setToDefault();
        setFrame(frameArg);
    }

    Label::Label(const char* frameArg, const char* content)
    {
        setToDefault();
        setFrame(frameArg);
        setLabel(content);
    }

    Label::~Label() // Vector, String classes will deallocate the dynamic memory
    {
        delete[] m_content;
        m_content = nullptr;
    }

    void Label::readLabel()
    {
        //reads the label from console up to 70 characters and stores it in the Label as shown in the Execution sample
        char console[71] = { '\0' };
        cin.get(console, 71, '\n');
        setLabel(console);
        flushkeys();
    }
    std::ostream& Label::printLabel() const
    {
        if (m_frameArg[0] != '\0' && m_content != nullptr)
        {

            cout << m_frameArg[0];
            cout.width(strLen(m_content) + 2);
            cout.fill(m_frameArg[1]);
            cout << "" << m_frameArg[2] << endl;
            
            cout << m_frameArg[7];
            cout.width(strLen(m_content) + 2);
            cout.fill(' ');
            cout << "" << m_frameArg[3] << endl;
            
            cout << m_frameArg[7] << " " << m_content << " " << m_frameArg[3] << endl;

            cout << m_frameArg[7];
            cout.width(strLen(m_content) + 2);
            cout.fill(' ');
            cout << "" << m_frameArg[3] << endl;
            
            cout << m_frameArg[2];
            cout.width(strLen(m_content) + 2);
            cout.fill(m_frameArg[1]);
            cout << "" << m_frameArg[0];
            
        }
        return cout;
    }

}
