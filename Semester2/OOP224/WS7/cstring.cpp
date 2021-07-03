/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS07_LAB
Date: 2021/03/17

----------------------------------------------
---------------------------------------------- */
#include "cstring.h"
namespace sdds
{
    void strCpy(char* des, const char* src)
    {
        int i = 0;

        for (i = 0; src[i] != '\0'; i++) {
            des[i] = src[i];
        }
        des[i] = '\0';
    }

    int strCmp(const char* s1, const char* s2)
    {
        int i, result;

        for (i = 0; s1[i] == s2[i] && s1[i] != '\0'; i++); // calculate at which index s1 and s2 are different.

        if (s1[i] < s2[i]) {
            result = -1;
        }
        else if (s1[i] > s2[i]) {
            result = 1;
        }
        else {
            result = 0;
        }
        return result;
    }
}

