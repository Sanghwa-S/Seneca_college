/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_SHAPE_H
#define SDDS_SHAPE_H
#include <iomanip>
#include <iostream>
#include <string.h>
#include <iostream>
namespace sdds
{
    class Shape
    {
    public:
        //pure virtual functions
        virtual void draw(std::ostream&)const = 0;
        virtual void getSpecs(std::istream&) = 0;

        //Virtual destructor
        virtual ~Shape();
    };
    // Operator overloadings
    std::ostream& operator<<(std::ostream&, Shape&);
    std::istream& operator>>(std::istream&, Shape&);
}
#endif // !SDDS_SHAPE_H
