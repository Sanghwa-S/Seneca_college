/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS02_DIY
Date: 2021/01/31

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_POPULATION_H_
#define SDDS_POPULATION_H_

#define DATAFILE "PCpopulationsComplete.csv"

namespace sdds 
{
    struct Canada
    {
        char* postalcode;
        int population;
    };
    void sort();
    
    bool load(Canada& Canadian);
    bool load(const char file[]);
    
    void display(const Canada& Canadian);
    void display();
    
    void deallocateMemory();


}
#endif // SDDS_POPULATION_H_