/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS02_DIY
Date: 2021/01/31

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
#include <cstring>


using namespace std;
namespace sdds 
{

    int noOfCanadian;
    Canada* Canadian;


    void sort()
    {
        int i, j;
        Canada temp;
        for (i = noOfCanadian - 1; i > 0; i--) 
        {
            for (j = 0; j < i; j++) 
            {
                if (Canadian[j].population > Canadian[j + 1].population) 
                {
                    temp = Canadian[j];
                    Canadian[j] = Canadian[j + 1];
                    Canadian[j + 1] = temp;
                }
            }
        }
    }

 bool load(Canada& Canadian)
    {
        bool ok = false;
        char name[10];

            if (read(name))
            {
                if (read(Canadian.population))
                {
                    Canadian.postalcode = new char[strlen(name) + 1];
                    strcpy(Canadian.postalcode, name);
                    ok = true;
                }
            }
        return ok;
    }

 
    bool load(const char file[])
    {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE))
        {

            noOfCanadian = noOfRecords();

            Canadian = new Canada[noOfCanadian];

            for (i = 0; i < noOfCanadian; i++)
            {
                load(Canadian[i]);
            }
           
            if (i != noOfCanadian)
            {
                cout << "Error: incorrect number of records read; the data is possibly corrupted!<ENDL>" << endl;
            }
            else {
                ok = true;
            }
            closeFile();
        }

        else
        {
            cout << "Could not open data file: FILENAME<ENDL>" << DATAFILE << endl;
        }
        return ok;
    }

    void display(const Canada& Canadian)
    {
        cout << Canadian.postalcode << ":  " << Canadian.population << endl;
    }

    void display()
    {
        int total = 0;

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        sort();
        for (int i = 0; i < noOfCanadian; i++)
        {
            cout << i + 1 << "- ";
            display(Canadian[i]);
            total += Canadian[i].population;
        }
        cout << "-------------------------" << endl;
        cout << "Population of Canada: " << total << endl;
        
    }
    
    void deallocateMemory()
    {
        for (int i = 0; i < noOfCanadian; i++)
        {
            delete[] Canadian[i].postalcode;
        }
        delete[] Canadian;
    }
}