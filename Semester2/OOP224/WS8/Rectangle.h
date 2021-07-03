/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_RECTANGLE_H
#define SDDS_RECTANGLE_H
#include "LblShape.h"
namespace sdds
{
    class Rectangle :public LblShape
    {
    private:
        int m_width;
        int m_height;

    public:
        //Constructors
        Rectangle();
        Rectangle(const char*, int, int);

        //Destructor


        // Overriding of the Shape's func
        void getSpecs(std::istream&);

        void draw(std::ostream&)const;


    };
}
#endif // !SDDS_RECTANGLE_H