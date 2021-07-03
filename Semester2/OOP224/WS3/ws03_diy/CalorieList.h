/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS03_DIY
Date: 2021/02/06

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_BILL_H_
#define SDDS_BILL_H_
#include "Food.h"
namespace sdds
{
    class CalorieList
    {
        //char m_title[40];
        Food* m_foods;
        int m_noOfFood;
        int m_foodAdded;
        void setEmpty();
        int totalCal()const;
        void Title()const;
        void footer()const;
        bool isValid()const;
    public:
        //void init(const char* title, int noOfFood);
        void init(int noOfFood);
        bool add(const char* item_name, int cals, int when);
        void display()const;
        void deallocate();
    };
}
#endif // !SDDS_TRANSCRIPT_H
