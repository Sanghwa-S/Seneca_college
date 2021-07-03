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
#include "Item.h"
using namespace std;
namespace sdds {


	void Item::setName(const char* name) //This function sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
	{
		strnCpy(m_itemName, name, 20);
	}

	void Item::setEmpty()
	{
		m_price = 0.0;
		m_itemName[0] = '\0';
	}

	void Item::set(const char* name, double price, bool taxed)
	{
		if (price < 0 || name == NULL) //If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state (safe empty state).
		{
			setEmpty();
		}
		else  //Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method 
			  //Sets the m_price and m_taxed attributes to the corresponding arguments.
		{
			setName(name);
			m_price = price;
			m_taxed = taxed;
		}
	}

	double Item::price()const //Returns the m_price attribute;
	{
		return m_price;
	}

	double Item::tax()const  //Returns the product of m_price and 0.13(define a constant double value for this tax rate). Or it returns 0.0 if the m_taxed is false.
	{

		if (m_taxed)
		{
			return m_price*0.13;
		}
		else
		{
			return 0.0;
		}
	}

	bool Item::isValid() const
	{
		bool valid = false;
		if (m_price > 0)
		{
			valid = true;
		}
		return valid;
	}
	void Item::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(20);
			cout.fill('.');
			cout << m_itemName;
			
			cout << " | ";
			cout.unsetf(ios::left);
			cout.width(7);
			cout.setf(ios::fixed);
			cout.fill(' ');
			cout.precision(2);
			cout << m_price;
			cout << " | ";
			

			if (m_taxed)
			{
				cout << "Yes";
			}
			else
			{
				cout << "No ";
			}
			cout << " |" << endl;
		}

		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		}
	}
}