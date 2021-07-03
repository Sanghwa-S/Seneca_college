/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS04_LAB
Date: 2021/02/10

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <istream>
#include <iomanip>
#include "cstring.h"  // using strLen, strCpy and strCmp 
#include "Canister.h"
using namespace std;
namespace sdds {

    const double PI = 3.14159265;
    
    void Canister::setToDefault()
    {
        m_contentName = nullptr;
        m_height = 13.0;
        m_diameter = 10.0;
        m_contentVolume = 0.0;
        m_usable = true;
    }
    bool Canister::isEmpty()const
    {
        bool flag = false;
        if (m_contentVolume < 0.00001)
        {
            flag = true;
        }
        return flag;
    }
    bool Canister::hasSameContent(const Canister& C)const
    {
        bool flag = false;
        if (m_contentName != nullptr && C.m_contentName != nullptr && strCmp(m_contentName, C.m_contentName) == 0)
        {
            flag = true;
        }
        return flag;
    }

    void Canister::setName(const char* Cstr)
    {
        
        if (Cstr != nullptr && m_usable == true)
        {
            clear();
            delete[] m_contentName;
            m_contentName = new char[strLen(Cstr) + 1];
            strCpy(m_contentName, Cstr);
            
        }
    }
    
    Canister::Canister()
    {
        setToDefault();
    }
    
    Canister::Canister(const char* contentName)
    {
        setToDefault();   
        setName(contentName);
    }
    
    Canister::Canister(double height, double diameter, const char* contentName)
    {
        setToDefault();
        m_contentName = nullptr;
        if (height >= 10.0 && diameter >= 10.0 && height <= 40 && diameter <= 30)
        {
            m_height = height;
            m_diameter = diameter;
            m_contentVolume = 0;
            setName(contentName);
        }
        else
        {
            m_usable = false;
        }
        //If any of the dimensions have invalid values, it will set the Canister unusable
    }
    Canister::~Canister()
    {
        delete[] m_contentName;
        m_contentName = nullptr;
    }
    void Canister::clear()
    {
        delete[] m_contentName;
        m_contentName = nullptr;
        m_contentVolume = 0.0;
        m_usable = true; //set the usable flag attribute to true
    }
    double Canister::capacity()const
    {
        double H = m_height;
        double D = m_diameter;
        double Capacity = PI * (H - 0.267) * (D / 2) * (D / 2);
        return Capacity;
    }
    double Canister::volume()const
    {
        return m_contentVolume;
    }
    Canister& Canister::setContent(const char* contentName)
    {
        if (contentName == nullptr)
        {
            m_usable = false;   //it will render the Canister unusable
        }
        else if(isEmpty())
        {
            setName(contentName);
        }
        else if(strCmp(contentName, m_contentName) != 0)
        {
            m_usable = false;
        }
        return *this;
    }
    Canister& Canister::pour(double quantity)
    {
        if (m_usable == true && quantity > 0 && (quantity + volume()) <= capacity())
        {
            m_contentVolume += quantity;
        }
        else
        {
            m_usable = false;//usable flag attribute to false.
        }
        return *this;
    }
    Canister& Canister::pour(Canister& C)
    {

        setContent(C.m_contentName);
        if(C.volume() > (capacity() - volume()))
        {
            C.m_contentVolume -= (capacity() - volume());
            m_contentVolume = capacity();
        }
        else
        {
            pour(C.m_contentVolume);
            C.m_contentVolume = 0.0;
        }
        return *this;
    }
    

    std::ostream& Canister::display()const
    {
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << setw(7) << capacity();
        cout << "cc (";
        cout << m_height;
        cout << "x";
        cout.setf(ios::fixed);
        cout.precision(1);
        cout << m_diameter;
        cout << ") Canister";

        if (m_usable == false)
        {
            cout << " of Unusable content, discard!";
        }
        else if (m_contentName != nullptr)
        {
            cout << " of ";
            cout.setf(ios::fixed);
            cout.precision(1);
            cout << setw(7) << m_contentVolume;
            cout << "cc   ";
            cout << m_contentName;
        }
        return cout;
    }
}