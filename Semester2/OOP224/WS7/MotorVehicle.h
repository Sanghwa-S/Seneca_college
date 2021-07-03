/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS07_LAB
Date: 2021/03/18

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_MOTORVEHICLE_H
#define SDDS_MOTORVEHICLE_H
#include <iostream>

namespace sdds
{
    class MotorVehicle
    {
    private:
        char m_plate[9];
        char m_address[64];
        int m_yearManufacture;

    public:

        MotorVehicle(const char* plate, const int year);
        void moveTo(const char* address);
        virtual	std::ostream& write(std::ostream& os)const;
        virtual std::istream& read(std::istream& in);
    };
    std::ostream& operator<<(std::ostream& os, const MotorVehicle& V);
    std::istream& operator>>(std::istream& istr, MotorVehicle& V);
}
#endif // !_SDDS_MOTORVEHICLE_H