/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS07_LAB
Date: 2021/03/18

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include <iomanip>
#include "MotorVehicle.h"
using namespace std;
namespace sdds
{
	MotorVehicle::MotorVehicle(const char* plate, const int year)
	{
		strCpy(m_plate, plate);
		strCpy(m_address, "Factory");
		m_yearManufacture = year;
	}
	void MotorVehicle::moveTo(const char* address)
	{
		if (strCmp(m_address, address) != 0)
		{
			cout << "|";
			cout.setf(ios::right);
			cout.width(8);
			cout << m_plate << "| |";
			cout.width(20);
			cout << m_address << " ---> ";
			cout.unsetf(ios::right);
			cout.setf(ios::left);
			cout.width(20);
			cout << address << "|" << endl;
			cout.unsetf(ios::left);
			strCpy(m_address, address);
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const
	{
		os << "| " << m_yearManufacture << " | " << m_plate << " | " << m_address;
		return os;
	}
	istream& MotorVehicle::read(istream& is)
	{
		cout << "Built year: ";
		is >> m_yearManufacture;
		cout << "License plate: ";
		is >> m_plate;
		cout << "Current location: ";
		is >> m_address;
		return is;
	}
	std::ostream& operator<<(std::ostream& os, const MotorVehicle& V)
	{
		return V.write(os);
	}
	std::istream& operator>>(std::istream& istr, MotorVehicle& V)
	{
		return V.read(istr);
	}
}