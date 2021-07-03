/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS06_DIY
Date: 2021/03/10

----------------------------------------------
---------------------------------------------- */
#include <iostream>
namespace sdds
{
    class Number
    {
        double m_value;
        operator const double()const;
        Number();
        Number& operator=(const double);
        ~Number(){ };
        friend class Stats;
    };
    class Stats
    {
        Number* m_numbers = nullptr;
        char* m_filename = nullptr;
        unsigned m_columnWidth;
        unsigned m_noOfColumns;
        unsigned m_precision;
        unsigned m_numCount;    // counts how many values are in the .csv aka size
        double dummy;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfnumCount();
        void load();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:

        Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);

        Stats(const Stats&);
        Stats& operator=(const Stats&);

        double& operator[](unsigned idx);
        double operator[](unsigned idx)const;
 
        operator bool()const;

        void sort(bool ascending);
        unsigned size()const;
        const char* name()const;
        unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);

        ~Stats();
    };
    std::ostream& operator<<(std::ostream& ostr, const Stats& stat);
    std::istream& operator>>(std::istream& istr, Stats& stat);
}