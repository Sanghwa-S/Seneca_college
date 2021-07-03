/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS05_LAB
Date: 2021/02/18

----------------------------------------------
---------------------------------------------- */
#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number;
      double m_balance; 
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;

      // type conversion operators
      operator bool() const;
      operator int() const;
      operator double() const;

      //Unary operator
      bool operator~() const;

      //Binary operators
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      Account& operator=(int Right_account);
      Account& operator=(Account& Right_account);
      Account& operator<<(Account& Right_account);
      Account& operator>>(Account& Right_account);
   };
   //For helper func
   double operator+(const Account& first, const Account& second);
   double operator+=(double& balance, const Account& Right_account);
   
}
#endif // SDDS_ACCOUNT_H_