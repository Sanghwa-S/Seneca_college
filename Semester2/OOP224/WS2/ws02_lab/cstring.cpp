/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS01_LAB
Date: 2021/01/20

----------------------------------------------
---------------------------------------------- */
#include<iostream>
#include "cstring.h"

using namespace std;
namespace sdds
{
	void strCpy(char* des, const char* src)
	{
		//Copy one character to dest and return until src is null byte 
		while ((*des++ = *src++) != '\0')
			/* nothing */;
		return;
	}
	
	void strnCpy(char* des, const char* src, int len)
	{
	
		
		while (len)
		{

			// Copy to dest until src is null byte
			// Subsequently, the src value (currently null byte) is copied to the dest as many count.
			// All remaining data is initialized as null byte as count.

			if ((*des = *src) != '\0')
			{
				src++;
				des++;
			}
			len--;
		}
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

	int strnCmp(const char* s1, const char* s2, int len)
	{
		int i, result;

		for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && i < len - 1; i++);

		if (s1[i] < s2[i]) 
		{
			result = -1;
		}
		else if (s1[i] > s2[i]) 
		{
			result = 1;
		}
		else 
		{
			result = 0;
		}
		return result;
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

	const char* strStr(const char* str1, const char* str2) //search = str2
	{
		
		int count = -1;  //If it was initialized to zero,When I found a, it became one.
		while (*str1)  //tring's value repeats until null character
		{
			if (*str1 != *str2) 
			{
				count = -1;  //Re-initialization
				  //Change search's address to first address as well
			}

			if (*str1 == *str2)
			{
				str2++;  //Increase the address of search
				count++;   
				if (*str2 == '\0') 
				{
					return str1 - count; //return the current address of the string minus the count
				}
			}
			str1++; // Increase the address of the string
			if (*str1 == '\0') 
			{
				return nullptr;  // if not found, retrun nullptr
			}
		}
		return 0;
	}

	void strCat(char* des, const char* src)
	{
		

		// Find the null byte location (end of string) of the dest string.
		//Copy on a string from at the end of the string dest src.
		//Copy up to the last null byte of the src string.
		//Exit the loop
		 
	
		int i = 0, j = 0;
		while (des[i] != '\0')
		{
			i++;
		}
		while (src[j] != '\0')
		{
			des[i++] = src[j++];
			des[i] = '\0';
		}
		return;
	}

}


/*

abcdefghijklmnopqrstuvwxyz
@@cdefghijklmnopqrstuvwxyz
@@@defghijklmnopqrstuvwxyz
@@@
1
0
1
0
26
jklmnopqrstuvwxyz
Not found
John Doe

*/