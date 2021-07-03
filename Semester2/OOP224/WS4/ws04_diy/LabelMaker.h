/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS04_DIY
Date: 2021/02/14

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include "cstring.h"

using namespace sdds;
namespace sdds
{
    class LabelMaker
    {
    private:

        Label* m_labels;
        int m_noOfLabels;
        void setEmpty();

    public:
        LabelMaker(int);

        void readLabels();

        void printLabels();

        ~LabelMaker(); //Deallocates the memory when LabelMaker goes out of scope.
    };
}
#endif //SDDS_LABELMAKER_H#pragma once
