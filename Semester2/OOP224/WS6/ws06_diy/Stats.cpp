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
#include <fstream>
#include <iomanip>
#include <string>
#include "Stats.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
    Number::operator const double() const
    {

        return (const double)m_value;
    }
    Number& Number::operator=(const double value)
    {
        m_value = value;
        return *this;
    }

    Number::Number()
    {
        m_value = 0.0;
    }

    void Stats::setEmpty()
    {
        delete[] m_numbers;
        m_numbers = nullptr;
        delete[] m_filename;
        m_filename = nullptr;
        m_numCount = 0;
    }

    void Stats::setFilename(const char* fname, bool isCopy)
    {
        delete[] m_filename;
        if (!isCopy)
        {
            m_filename = new char[strLen(fname) + 1];
            strCpy(m_filename, fname);
            return;
        }
        m_filename = new char[strLen(fname) + 3];
        string copy_name = "C_";
        for (int i = 0; i < (int)strLen(fname); i++)
        {
            copy_name += fname[i];
        }
        strCpy(m_filename, copy_name.c_str());
    }

    void Stats::setNoOfnumCount()
    {
        int count = 0;
        char ch;
        std::ifstream in(m_filename);
      
        while (!in.eof()) {
            ch = in.get();
            if (ch == ',') {
                count++;
            }
        }
        m_numCount = count;
        if (m_numCount == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
        else {
            m_numCount += 1;
        }
    }

    void Stats::load()
    {
        int i = 0;
        string line_num;
        if (m_numCount > 0) 
        {
            delete[] m_numbers;
            m_numbers = new Number[m_numCount];
            std::ifstream fin(m_filename);

            while (getline(fin, line_num, ',')) 
            {
                m_numbers[i] = stod(line_num);
                i++;
            }
        }

        m_numCount = i;
    }

    void Stats::saveAs(const char* fileName)const
    {
        /*unsigned int i;
        if (fileName != nullptr)
        {
            ofstream out;
            out.open(fileName);
            if (out.is_open())
            {
                for (i = 0; i < size(); i++)
                {
                    if (i == size() - 1)
                    {
                        out << m_numbers[i];
                    }
                    else
                    {
                        out << m_numbers[i] << ",";
                    }
                }
            }
            out.close();
        }
        return;*/
        ofstream out(fileName);
        int precision;
        if (m_precision == 0)
        {
            precision = 4;
        }
        else
        {
            precision = m_precision;
        }
        for (int i = 0; unsigned(i) < size(); i++)
        {
            if(unsigned(i+1) < size())
                {
                    out << fixed << setprecision(4) << m_numbers[i] << ",";
                }
            else
            {
                out << setprecision(precision) << m_numbers[i];
            }
        }
        out.close();
    }

    Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
    {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        setEmpty();
    }

    Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision)
    {
        m_columnWidth = columnWidth;
        m_noOfColumns = noOfColumns;
        m_precision = precision;
        setEmpty();
        std::ifstream f(filename);
        if (f.good() && filename != nullptr) {
            setFilename(filename);
            setNoOfnumCount();
            load();
        }
    }

    Stats::Stats(const Stats& stat)
    {
        m_columnWidth = stat.m_columnWidth;
        m_noOfColumns = stat.m_noOfColumns;
        m_precision = stat.m_precision;
        setEmpty();
        if (stat) {
            setFilename(stat.name(), true);
            stat.saveAs(m_filename);
            setNoOfnumCount();
            load();
        }
    }

    Stats& Stats::operator=(const Stats& stat)
    {
        if (this != &stat) {
            if (stat && *this) 
            {
                m_columnWidth = stat.m_columnWidth;
                m_noOfColumns = stat.m_noOfColumns;
                m_precision = stat.m_precision;
                delete[] m_numbers;
                m_numbers = nullptr;
                stat.saveAs(m_filename);
                setNoOfnumCount();
                load();
            }
        }
        return *this;
    }

    const char* Stats::name()const
    {
        return m_filename;
    }

    unsigned Stats::size()const
    {
        return m_numCount;
    }

    std::ostream& Stats::view(std::ostream& ostr)const
    {
        unsigned i, count = 0;
        if (*this) {
            ostr << m_filename << endl;
            ostr.width(strLen(m_filename));
            ostr.fill('=');
            ostr << "=" << endl << endl;
            for (i = 0; i < m_numCount; i++) {
                ostr.fill(' ');
                ostr.width(m_columnWidth);
                ostr.setf(ios::fixed);
                ostr.precision(m_precision);
                ostr << m_numbers[i];
                count++;
                if (count == m_noOfColumns) {
                    ostr << endl;
                    count = 0;
                }
            }
            if (count % m_noOfColumns != 0) {
                ostr << endl;
            }
            ostr << "Total of " << m_numCount << " listed!" << endl;
        }
        return ostr;
    }

    std::istream& Stats::getFile(std::istream& istr)
    {
        string fname;
        istr >> fname;
        setFilename(fname.c_str());
        setNoOfnumCount();
        load();
        return istr;
    }

    double& Stats::operator[](unsigned idx)
    {
       
        if (*this) {
            if (idx > m_numCount - 1) {
                idx -= (m_numCount);
            }
            return m_numbers[idx].m_value;
        }
        else {
            dummy = 0.00;
            return dummy;
        }
    }

    double Stats::operator[](unsigned idx)const
    {
        double value;
    if (*this) {
        if (idx > m_numCount - 1) {
            idx -= (m_numCount);
        }
        return value = m_numbers[idx];
    }
    else {
        value = 0.00;
    }
    return value;
    }

    Stats::operator bool()const
    {
        return !(m_numCount == 0 || m_numbers == nullptr || m_filename == nullptr);
    }

    void Stats::sort(bool ascending)
    {
        unsigned int i, j;
        double temp;
        if (*this) 
        {
            if (ascending) 
            {
                for (i = m_numCount - 1; i > 0; i--) 
                {
                    for (j = 0; j < i; j++) {
                        if (m_numbers[j] > m_numbers[j + 1]) 
                        {
                            temp = m_numbers[j];
                            m_numbers[j] = m_numbers[j + 1];
                            m_numbers[j + 1] = temp;
                        }
                    }
                }
            }
            else 
            {
                for (i = 0; i < m_numCount; i++) 
                {
                    for (j = i + 1; j < m_numCount; j++) 
                    {
                        if (m_numbers[i] < m_numbers[j]) 
                        {
                            temp = m_numbers[i];
                            m_numbers[i] = m_numbers[j];
                            m_numbers[j] = temp;
                        }
                    }
                }
            }
        }
    }


    unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
    {
        unsigned int i, count = 0;
        double occurrence = 0.00;
        if (*this) 
        {
            ostr << endl;
            for (i = 0; i < m_numCount; i++) 
            {
                if (m_numbers[i] >= min && m_numbers[i] <= max) 
                {
                    ostr.width(m_columnWidth);
                    ostr.setf(ios::fixed);
                    ostr.precision(m_precision);
                    ostr << m_numbers[i];
                    count++;
                    occurrence++;
                    if (count == m_noOfColumns) 
                    {
                        ostr << endl;
                        count = 0;
                    }
                }
            }
            if (count % m_noOfColumns != 0) {
                ostr << endl;
            }
            ostr << "Total of " << occurrence << " numbers are between " << min << " and " << max << endl;
        }
        return occurrence;
    }
    Stats::~Stats()
    {
        delete[] m_numbers;
        delete[] m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const Stats& stat)
    {
        return stat.view(ostr);
    }

    std::istream& operator>>(std::istream& istr, Stats& stat)
    {
        return stat.getFile(istr);
    }

}
