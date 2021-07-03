/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS03_DIY
Date: 2021/02/06

----------------------------------------------
---------------------------------------------- */
#include "cstring.h"
namespace sdds
{

    void strnCpy(char* des, const char* src, int len)
    {
        int i, count = 0, k;

        for (i = 0; src[i] != '\0'; i++)
        {
            count = i + 1;
        }
        if (count < len)
        {
            for (k = 0; src[k] != '\0'; k++)
            {
                des[k] = src[k];
            }
        }
        else
        {
            for (k = 0; k < len; k++)
            {
                des[k] = src[k];
            }
        }
        des[k] = '\0';
    }
}