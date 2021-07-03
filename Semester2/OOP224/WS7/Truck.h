/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS07_LAB
Date: 2021/03/18

----------------------------------------------
---------------------------------------------- */
#ifndef _SDDS_TRUCK_H_
#define _SDDS_TRUCK_H_
#include "MotorVehicle.h"
namespace sdds
{
	class Truck :public MotorVehicle
	{
		double m_capacity;
		double m_cargo;
	public:
		Truck(const char* plate, const int year, const double capacity, const char* address);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os)const;
		std::istream& read(std::istream& in);
	};
	std::ostream& operator<<(std::ostream& os, const Truck& T);
	std::istream& operator>>(std::istream& istr, Truck& T);
}
#endif // !_SDDS_TRUCK_H_
