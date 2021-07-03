/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#include<iostream>
#include "Shape.h"
namespace sdds
{
    //Virtual destructor
    Shape::~Shape()
    {

    }

    // Operator overloadings
    std::ostream& operator<<(std::ostream& output, Shape& S)
    {
        S.draw(output);
        return output;
    }
    std::istream& operator>>(std::istream& input, Shape& S)
    {
        S.getSpecs(input);
        return input;
    }

}