/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS07_LAB
Date: 2021/03/18

----------------------------------------------
---------------------------------------------- */
#include "Truck.h"
using namespace std;
namespace sdds
{
	Truck::Truck(const char* plate, const int year, const double capacity, const char* address) :MotorVehicle(plate, year)
	{
		m_capacity = capacity;
		m_cargo = 0;
		MotorVehicle::moveTo(address);
	}

	bool Truck::addCargo(double cargo)
	{
		bool change = false;
		double original_cargo = m_cargo;
		m_cargo += cargo;
		if (m_cargo > m_capacity) 
		{
			m_cargo = m_capacity;
		}
		if (original_cargo != m_cargo)
		{
			change = true;
		}
		return change;
	}

	bool Truck::unloadCargo()
	{
		bool change = false;
		double original_cargo = m_cargo;
		m_cargo = 0;
		if (original_cargo != m_cargo)
		{
			change = true;
		}
		return change;
	}

	std::ostream& Truck::write(std::ostream& os) const
	{
		MotorVehicle::write(os);
		os << " | " << m_cargo << "/" << m_capacity;
		return os;
	}

	std::istream& Truck::read(std::istream& in)
	{
		MotorVehicle::read(in);
		cout << "Capacity: ";
		in >> m_capacity;
		cout << "Cargo: ";
		in >> m_cargo;
		return in;
	}

	std::ostream& operator<<(std::ostream& os, const Truck& T)
	{
		return T.write(os);
	}

	std::istream& operator>>(std::istream& istr, Truck& T)
	{
		return T.read(istr);
	}
}