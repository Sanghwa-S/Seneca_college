/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Menu.H
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
#ifndef SDDS_MENU_H
#define SDDS_MENU_H
#include <iostream>
#include <cstring>
namespace sdds
{
    class Menu
    {
        char* m_text; // holds the menu content dynamically
        int m_noOfSel;  // holds the number of options displayed in menu content
        void display()const;
    public:
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        int& operator>>(int& Selection);
        // add safe copying logic
        Menu(const Menu&);
    };
}

#endif // !SDDS_TIME_H #pragma once
