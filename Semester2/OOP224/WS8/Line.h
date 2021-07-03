/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_LINE_H
#define SDDS_LINE_H
#include<iostream>
#include "LblShape.h"
namespace sdds
{
    class Line :public LblShape
    {
    private:
        int m_length;

    public:
        //Constructors
        Line();
        Line(const char* Cstring, int);

        //Destructor
        //This class has no destructor implemented.

        //Overriding of the Shape's func
        void getSpecs(std::istream&);

        void draw(std::ostream&)const;
    };
}
#endif // !SDDS_LINE_H
