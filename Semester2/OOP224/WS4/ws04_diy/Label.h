/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS04_DIY
Date: 2021/02/10

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_LABEL_H
#define SDDS_LABEL_H
#include <iostream>
using namespace std;

namespace sdds
{
    class Label
    {
    private:

        char m_frameArg[9];
        char* m_content;
     

    public:
        void setToDefault();
        void setFrame(const char* Cstr);
        void setLabel(const char* Cstr);
        void flushkeys();

        Label();
        Label(const char* frameArg);
        Label(const char* frameArg, const char* content);
        
        ~Label(); 
        void readLabel();
        std::ostream& printLabel()const;
    };
}
#endif //SDDS_LABEL_H
