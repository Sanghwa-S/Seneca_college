/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS03_LAB
Date: 2021/01/3

----------------------------------------------
---------------------------------------------- */
#include <iostream>
#include "cstring.h"
#include "Bill.h"
using namespace std;
namespace sdds {
	
	void Bill::setEmpty()
	{
		m_title[0] = '\0';
		m_items = nullptr;
	}

	bool Bill::isValid()const
	{
		bool valid = true;
		int i;
		if (m_title[0] != '\0' && m_items != nullptr) 
		{
			for (i = 0; i < m_noOfItems && valid == true; i++) 
			{
				if (!m_items[i].isValid()) 
				{
					valid = false;
				}
				else valid = true;
			}
		}
		return valid;
	}

	double Bill::totalTax()const //Adds all the taxes of the items using a loop and returns the sum.
	{
		double sum = 0.0;
		int i;
		for (i = 0; i < m_noOfItems; i++)
		{
			sum += m_items[i].tax();
		}
		return sum;
	}
	double Bill::totalPrice()const //Adds all the prices of the items using a loop and returns the sum;
	{
		double sum = 0.0;
		int i;
		for (i = 0; i < m_noOfItems; i++)
		{
			sum += m_items[i].price();
		}
		return sum;
	}
	void Bill::Title()const
	{
		cout << "+--------------------------------------+" << endl;

		if (isValid())  //If the Bill is valid
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(36);
			cout << m_title;
			cout << " |";
			cout << endl;
		}
		else //If the Bill is invalid
		{
			cout << "| Invalid Bill                         |" << endl;
		}
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
	}

	void Bill::footer()const
	{
		cout << "+----------------------+---------+-----+" << endl;
		if (isValid())   // If the Bill is valid
		{
			cout << "|                Total Tax: ";
			cout.width(10);
			cout.unsetf(ios::left);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax();
			cout << " |";
			cout << endl;

			cout << "|              Total Price: ";
			cout.width(10);
			cout.unsetf(ios::left);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalPrice();
			cout << " |";
			cout << endl;

			cout << "|          Total After Tax: ";
			cout.width(10);
			cout.unsetf(ios::left);
			cout.setf(ios::fixed);
			cout.precision(2);
			cout << totalTax() + totalPrice();
			cout << " |";
			cout << endl;

			

		}
		else  //If the Bill is invalid
		{
			cout << "| Invalid Bill                         |" << endl;
		}

		cout << "+--------------------------------------+" << endl;
	}

	void Bill::init(const char* title, int noOfItems)
	{
		int i;
		if (title[0] == '\0' || noOfItems < 1)
		{
			setEmpty();
		}
		else
		{
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title, 36);
			m_items = new Item[m_noOfItems];
			for (i = 0; i < m_noOfItems; i++)
			{
				m_items[i].setEmpty();
			}
		}
	}

	bool Bill::add(const char* item_name, double price, bool taxed)
	{
		if (m_itemsAdded < m_noOfItems) 
		{
			m_items[m_itemsAdded].set(item_name, price, taxed);
			m_itemsAdded += 1;
			return true;
		}
		return false;
	}

	void Bill::display()const  //This function will first print the title(), then it will loop through the m_items elements, printing every one of them, 
							   //and finally prints the footer(). This function can not modify the Bill.
	{
		int i;
	
			Title();
			for (i = 0; i < m_noOfItems; i++)
			{
				m_items[i].display();
			}
			footer();
	}

	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;
	}
}