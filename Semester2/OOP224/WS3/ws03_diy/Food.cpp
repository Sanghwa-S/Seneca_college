/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS03_DIY
Date: 2021/02/06

----------------------------------------------
---------------------------------------------- */
#include <iostream>
#include "cstring.h"
#include "Food.h"
using namespace std;
namespace sdds
{


	void Food::setName(const char* name) //This function sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
	{
		strnCpy(m_foodName, name, 30);
	}

	void Food::setEmpty()
	{
		m_cals = 0;
		m_foodName[0] = '\0';
	}

	void Food::set(const char* name, int cals, int when)
	{
		if (cals < 0 || name == NULL || when == 0) //If price is less than 0 or name is null, then the Item is set to a recognizable invalid empty state (safe empty state).
		{
			setEmpty();
		}
		else  //Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName method 
			  //Sets the m_price and m_taxed attributes to the corresponding arguments.
		{
			setName(name);
			m_cals = cals;
			m_when = when;
		}
	}

	int Food::cals()const //Returns the m_price attribute;
	{
		return m_cals;
	}

	void Food::when(int num)const  //Returns the product of m_price and 0.13(define a constant double value for this tax rate). Or it returns 0.0 if the m_taxed is false.
	{
		switch (num)
		{
			case 1:
			{
				cout << "Breakfast ";
				break;
			}
			case 2:
			{
				cout << "Lunch     ";
				break;
			}
			
			case 3:
			{
				cout << "Dinner    ";
				break;
			}
			
			case 4:
			{
				cout << "Snack     ";
				break;
			}
		default:
			break;
		}
	}

	bool Food::isValid() const
	{
		bool valid = false;
		if (m_cals > 0)
		{
			valid = true;
		}
		return valid;
	}
	void Food::display()const
	{
		if (isValid())
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(30);
			cout.fill('.');
			cout << m_foodName;

			cout << " | ";
			cout.unsetf(ios::left);
			cout.width(4);
			cout.fill(' ');
			cout << m_cals;
			cout << " | ";


			if (m_when > 0)
			{
				when(m_when);
			}
			else
			{
				cout << "xxxxxxxxxx";
			}
			cout << " |" << endl;
		}

		else
		{
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}
}