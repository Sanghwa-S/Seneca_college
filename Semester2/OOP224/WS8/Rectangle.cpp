/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS08_LAB
Date: 2021/03/22

----------------------------------------------
---------------------------------------------- */
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds
{

    //Constructors
    Rectangle::Rectangle() :LblShape()
    {
        m_width = 0;
        m_height = 0;
    }
    Rectangle::Rectangle(const char* Cstring, int width, int height) : LblShape(Cstring)
    {
        m_width = width;
        m_height = height;

        int length = strlen(label());

        if (m_height < 3 || m_width < length + 2)
        {
            m_width = 0;
            m_height = 0;
        }
    }

    // Overriding of the Shape's func
    void Rectangle::getSpecs(std::istream& in)
    {
        LblShape::getSpecs(in);
        in >> m_width;
        in.ignore(100, ',');
        in >> m_height;
        in.ignore(100, '\n');
    }

    void Rectangle::draw(std::ostream& out)const
    {
        if (m_height != 0 || m_width != 0)
        {
            int length = strlen(label());
            out << "+";
            for (int i = 0; i < m_width - 2; i++)
            {
                out << "-";
            }
            out << "+" << endl;

            out << "|";
            out << left << label();
            for (int i = 0; i < (m_width - 2) - length; i++)
            {
                out << " ";
            }

            out << "|" << endl;

            for (int i = 0; i < m_height - 3; i++)
            {
                out << "|";
                for (int j = 0; j < m_width - 2; j++)
                {
                    out << " ";
                }
                out << "|" << endl;
            }

            out << "+";
            for (int i = 0; i < m_width - 2; i++)
            {
                out << "-";
            }
            out << "+";

        }
        else
        {

        }
    }

}