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
#include<iomanip>
#include "cstring.h"
#include "CalorieList.h"


using namespace std;
namespace sdds
{

	void CalorieList::setEmpty()
	{
		//m_title[0] = '\0';
		m_foods = nullptr;
	}

	bool CalorieList::isValid()const
	{
		bool valid = true;
		int i;
		//if (m_title[0] != '\0' && m_foods != nullptr)
		if (m_foods != nullptr)
		{
			for (i = 0; i < m_noOfFood && valid == true; i++)
			{
				if (!m_foods[i].isValid())
				{
					valid = false;
				}
				else valid = true;
			}
		}
		return valid;
	}

	int CalorieList::totalCal()const //Adds all the taxes of the items using a loop and returns the sum.
	{
		int sum = 0;
		int i;
		for (i = 0; i < m_noOfFood; i++)
		{
			sum += m_foods[i].cals();
		}
		return sum;
	}

	void CalorieList::Title()const
	{
		cout << "+----------------------------------------------------+" << endl;

		if (isValid())  //If the CalorieList is valid
		{
			cout << "| ";
			cout.setf(ios::left);
			cout.width(40);
			//cout << m_title;
			cout << " Daily Calorie Consumption                         |";
			//cout << " |";
			cout << endl;
		}
		else //If the CalorieList is invalid
		{
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;
	}

	void CalorieList::footer()const
	{
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid())   // If the Calorie is valid
		{
			cout << "|    Total Calories for today: ";
			cout.width(8);
			cout.unsetf(ios::left);
			cout << totalCal();
			cout << " |            |";
			cout << endl;
			
		}
		else  //If the CalorieList is invalid
		{
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}

		cout << "+----------------------------------------------------+" << endl;
	}

	//void CalorieList::init(const char* title, int noOfFood)
	void CalorieList::init(int noOfFood)
	{
		int i;
		//if (title[0] == '\0' || noOfFood < 1)
		if (noOfFood < 1)
		{
			setEmpty();
		}
		else
		{
			m_noOfFood = noOfFood;
			m_foodAdded = 0;
			//strnCpy(m_title, title, 36);
			m_foods = new Food[m_noOfFood];
			for (i = 0; i < m_noOfFood; i++)
			{
				m_foods[i].setEmpty();
			}
		}
	}

	bool CalorieList::add(const char* item_name, int cals, int when)
	{
		if (m_foodAdded < m_noOfFood)
		{
			m_foods[m_foodAdded].set(item_name, cals, when);
			m_foodAdded += 1;
			return true;
		}
		return false;
	}

	void CalorieList::display()const  
	{
		int i;

		Title();
		for (i = 0; i < m_noOfFood; i++)
		{
			m_foods[i].display();
		}
		footer();
	}

	void CalorieList::deallocate()
	{
		delete[] m_foods;
		m_foods = nullptr;
	}
}