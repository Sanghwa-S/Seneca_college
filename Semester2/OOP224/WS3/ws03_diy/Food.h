/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS03_DIY
Date: 2021/02/06

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds
{
    class Food
    {
        char m_foodName[31];
        int m_cals;
        int m_when;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, int cals, int when);
        int cals()const;
        void when(int num)const;
        bool isValid()const;
        void display()const;
    };
}

#endif // !SDDS_SUBJECT_H
