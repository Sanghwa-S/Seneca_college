/* Citation and Sources...
Final Project Milestone 1
Module: Time
Filename: Menu.cpp
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
#define _CRT_SECURE_NO_WARNINGS
#include "Menu.h"
#include "utils.h"
#include <cstring>
#include <iostream>
using namespace std;
namespace sdds
{
	Menu::Menu(const char* MenuContent, int NoOfSelections)
	{
		m_text = nullptr;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);
		m_noOfSel = NoOfSelections;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}
	Menu::Menu(const Menu& copy)
	{
		m_text = nullptr;
		m_text = new char[strlen(copy.m_text) + 1];
		strcpy(m_text, copy.m_text);
		m_noOfSel = copy.m_noOfSel;
	}
	void Menu::display()const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}
	int& Menu::operator>>(int& Selection)
	{
		int input;
		display();
		input = getInt(0, m_noOfSel, "> ", "Invalid option ");
		Selection = input;
		return Selection;
	}
}