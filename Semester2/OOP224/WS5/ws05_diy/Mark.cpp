/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS05_DIY
Date: 2021/02/18

----------------------------------------------
---------------------------------------------- */		
#include "Mark.h"

namespace sdds
{
	void Mark::setEmpty()
	{
		m_mark = -1;
	}

	// New mark
	Mark::Mark()
	{
		m_mark = 0;
	}
	Mark::Mark(int mark)
	{
		setEmpty();
		if (mark >= 0 && mark <= 100)
		{
			m_mark = mark;
		}
		
	}
	Mark::operator int() const
	{
		int mark = 0;
		if (*this)
		{
			mark = m_mark;
		}
		return mark;
	}
	Mark::operator double() const
	{
		int mark = int(*this);

		if (mark >= 0 && mark < 50)
		{
			return 0.0;
		}
		else if (mark >= 50 && mark < 60)
		{
			return 1.0;
		}
		else if (mark >= 60 && mark < 70)
		{
			return 2.0;
		}
		else if (mark >= 70 && mark < 80)
		{
			return 3.0;
		}
		else if (mark >= 80 && mark <= 100)
		{
			return 4.0;
		}

		return 0.0;
	}
	Mark::operator char() const
	{

		int mark = int(*this);

		if (*this)
		{
			if (mark >= 0 && mark < 50)
			{
				return 'F';
			}
			else if (mark >= 50 && mark < 60)
			{
				return 'D';
			}
			else if (mark >= 60 && mark < 70)
			{
				return 'C';
			}
			else if (mark >= 70 && mark < 80)
			{
				return 'B';
			}
			else if (mark >= 80 && mark <= 100)
			{
				return 'A';
			}
		}
		return 'X';

	}
	Mark::operator bool() const
	{
		bool valid = false;
		if (m_mark >= 0 && m_mark <= 100)
		{
			valid = true;
		}
		return valid;
	}
	Mark& Mark::operator+=(const int& Right_mark)
	{
		if (*this)
		{
			m_mark += Right_mark;
			if (!*this)
			{
				setEmpty();
			}
		}
		return *this;
	}
	Mark& Mark::operator=(const int& Right_mark)
	{
		m_mark = Right_mark;
		if (!*this)
		{
			setEmpty();
		}
		return *this;
	}
	int operator+=(int& mark, const Mark& Right_mark)
	{
		if (Right_mark)
		{
			mark += int(Right_mark);
		}
		return mark;
	}
}