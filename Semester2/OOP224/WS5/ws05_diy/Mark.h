/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS05_DIY
Date: 2021/02/18

----------------------------------------------
---------------------------------------------- */#pragma once
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>

namespace sdds
{
	class Mark
	{
		int m_mark;
		void setEmpty();
		
	public:
		Mark();
		Mark(int mark);
		
		operator int() const;
		operator double() const;
		operator char() const;
		operator bool() const;
		
		Mark& operator+=(const int& Right_mark);
		Mark& operator=(const int& Right_mark);
	};
	int operator+=(int& mark, const Mark& Right_mark);
}
#endif // SDDS_MARK_H_