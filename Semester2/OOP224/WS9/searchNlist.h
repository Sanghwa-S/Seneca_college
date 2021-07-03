/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS09_LAB
Date: 2021/03/30

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_SEARCHNLIST_H
#define SDDS_SEARCHNLIST_H
#include "Collection.h"
#include <iostream>
#include <cstring>
using namespace std;
namespace sdds
{
    template<typename M, typename T>
    bool search(Collection<M>& collection, M* array, int size, T key)
    {
        bool found = false;
        for (int i = 0; i < size; i++)
            if (array[i] == key) // == operator for types  T and M must be overloaded 
            { 
                found = true;
                collection.add(array[i]);
            }
        return found;
    }


    template<typename M>
    void listArrayElements(const char* title, const M* array, int size)
    {
        std::cout << title << endl;
        for (int i = 0; i < size; i++) 
        {
            cout << i + 1 << ": " << array[i] << endl; // << must be overloaded for type M
        }
           
    }
}
#endif //SDDS_SEARCHNLIST_H


