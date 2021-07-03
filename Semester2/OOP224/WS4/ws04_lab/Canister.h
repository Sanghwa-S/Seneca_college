/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS04_LAB
Date: 2021/02/10

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
   class Canister {
      char* m_contentName; // points to a dynamically allocated Cstring.
      double m_diameter; // in centimeters 
      double m_height;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable; // a flag to identify if the Canister is usable or unusable

   private:
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
   
   public:
       double capacity()const;
       double volume()const;
       Canister& setContent(const char* contentName);
       std::ostream& display()const;
       Canister& pour(double quantity);
       Canister& pour(Canister&);

       Canister();
       Canister(const char* contentName);
       Canister(double hieght, double diameter, const char* contentName = nullptr);

       ~Canister();
       void clear();
   };
}

#endif // !SDDS_BOX_H
