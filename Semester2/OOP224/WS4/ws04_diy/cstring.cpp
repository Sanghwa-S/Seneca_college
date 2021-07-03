/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS04_DIY
Date: 2021/02/14

----------------------------------------------
---------------------------------------------- */
#include "cstring.h"
namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		//Copy one character to dest and return until src is null byte 
		while ((*des++ = *src++) != '\0')
			/* nothing */;
		return;
	}

	int strCmp(const char* s1, const char* s2)
	{
		int i = 0;

		// Perform a comparison until one string is finished
		while (s1[i] != '\0' || s2[i] != '\0')
		{

			// Continue to compare characters if they are characters
			if (s1[i] == s2[i])
			{
				i++;
			}

			// if the preceding character is larger, return 1
			else if (s1[i] > s2[i])
			{
				return 1;
			}

			// if the characters after are larger, return -1
			else if (s1[i] < s2[i])
			{
				return -1;
				i++;
			}

		}
		return 0;
	}

	int strLen(const char* s)
	{
		int i = 0;
		while (s[i] != '\0')
		{
			i++;
		}
		return i;
	}
}