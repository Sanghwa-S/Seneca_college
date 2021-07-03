/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_LBLSHAPE_H
#define SDDS_LBLSHAPE_H
#include "Shape.h"
#include <string>
namespace sdds
{
    class LblShape :public Shape
    {
    private:
        char* m_label = nullptr;

    protected:
        const char* label()const;

    public:
        //constructors
        LblShape();
        LblShape(const char* Cstring);

        //destructor
        virtual ~LblShape();

        //copy constructor =delete
        LblShape(const LblShape&) = delete;

        //copy assignment operator =delete
        LblShape& operator=(const LblShape&) = delete;

        //Overriding of the Shape's func
        void getSpecs(std::istream&);
    };
}
#endif // !SDDS_LBLSHAPE_H