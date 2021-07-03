/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.cpp
Version 2.0
Author	SANGHWA SUH
Revision History
-----------------------------------------------------------
Date      2020/03/24
2020/?/?  Preliminary release
2020/3/24  Debugged DMA
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/
#define _CRT_SECURE_NO_WARNINGS
#include<iostream>
#include<iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds 
{
    Time& Time::setToNow()
    {
        m_min = sdds::getTime();
        return *this;
    }
    Time::Time(unsigned int min )
    {
        m_min = min;
    }
    std::ostream& Time::write(std::ostream& ostr) const
    {
        ostr.width(2);
        ostr.fill('0');
        ostr << m_min / 60 << ":";
        ostr.width(2);
        ostr.fill('0');
        ostr << m_min % 60;
        return ostr;
    }
    std::istream& Time::read(std::istream& istr)
    {
        int hour = 0, mins = 0;
        char col = '!';
        istr >> hour >> col >> mins;
        if (col != ':' || hour < 0 || mins < 0)
        {
            istr.setstate(ios::failbit);
        }
        else
        {
            m_min = hour * 60 + mins;
        }
        return istr;
    }

    Time& Time::operator-=(const Time& D)
    {
        while(m_min < D.m_min)
        {
            m_min += 24 * 60;
        }
        m_min -= D.m_min;
        return *this;
    }
    Time Time::operator-(const Time& D)const
    {
        Time tmp;
        tmp.m_min = m_min;
        while(tmp.m_min < D.m_min)
        {
            tmp.m_min += 24 * 60;
        }
        tmp.m_min -= D.m_min;
        return tmp;
    }
    Time& Time::operator+=(const Time& D)
    {
        m_min += D.m_min;
        return *this;
    }
    Time Time::operator+(const Time& D)const
    {
        Time tmp;
        tmp.m_min = m_min + D.m_min;
        return tmp;
    }

    Time& Time::operator=(unsigned int val)
    {
        m_min = val;
        return *this;
    }
    Time& Time::operator *= (unsigned int val)
    {
        m_min *= val;
        return *this;
    }
    Time Time::operator *(unsigned int val)const
    {
        Time tmp;
        tmp.m_min = m_min * val;
        return tmp;
    }
    Time& Time::operator /= (unsigned int val)
    {
        m_min /= val;
        return *this;
    }
    
    Time Time::operator /(unsigned int val)const
    {
        Time tmp;
        tmp.m_min = m_min / val;
        return tmp;
    }

    Time::operator unsigned int()const
    {
        return m_min;
    }
    Time::operator int()const
    {
        return (int)m_min;
    }
    std::istream& operator>>(std::istream& istr, Time& D)
    {
        return D.read(istr);
    }
    std::ostream& operator<<(std::ostream& ostr, const Time& D)
    {
        return D.write(ostr);
    }
    
}