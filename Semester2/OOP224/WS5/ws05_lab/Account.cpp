/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS05_LAB
Date: 2021/02/18

----------------------------------------------
---------------------------------------------- */
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Account.h"

using namespace std;
namespace sdds {
   void Account::setEmpty() {
      m_number = -1;
      m_balance = 0.0;
   }
   // New account
   Account::Account() {  
      m_number = 0;
      m_balance = 0.0;
   }
   Account::Account(int number, double balance ) {
      setEmpty();
      if (number >= 10000 && number <= 99999
         && balance > 0) {
         m_number = number;
         m_balance = balance;
      }
   }
   std::ostream& Account::display() const{
      if (*this) {  
         cout << " ";
         cout << m_number;
         cout << " | ";
         cout.width(12);
         cout.precision(2);
         cout.setf(ios::right);
         cout.setf(ios::fixed);
         cout << m_balance;
         cout.unsetf(ios::right);
         cout << " ";
      }
      else if(~*this) {
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }
   Account::operator bool() const
   {
       bool valid = false;
       if (m_number >= 10000 && m_number < 100000 && m_balance >= 0)
       {
           valid = true;
       }
       return valid;
   }
   Account::operator int() const
   {
       return m_number;
   }
   Account::operator double() const
   {
       return m_balance;
   }

   bool Account::operator ~() const
   {
       /*
       bool valid = false;
       if (m_number == 0)
       {
           valid = true;
       }
       return valid;
       */
       return !m_number;
   }

   Account& Account::operator=(int Right_account)
   {
       if (Right_account < 10000 || Right_account > 99999)
       {
           setEmpty();
       }
       else if (m_number == 0)
       {
           m_number = Right_account;
       }
       return *this;
   }

   Account& Account::operator=(Account& Right_account)
   {
       if (m_number == 0 && &Right_account != this )
       {
           m_number = Right_account.m_number;
           m_balance = Right_account.m_balance;
           Right_account.m_balance = 0;
           Right_account.m_number = 0;
       }
       return *this;
   }


   Account& Account::operator+=(double balance)
   {
       if (balance >= 0)
       {
           m_balance += balance;
       }
       return *this;
   }

   Account& Account::operator-=(double balance)
   {
       if (balance >= 0 && m_balance >= balance)
       {
           m_balance -= balance;
       }
       return *this;
   }

   Account& Account::operator<<(Account& Right_account)
   {
       if (Right_account.m_balance >= 0 && &Right_account != this)
       {
           m_balance += Right_account.m_balance;
           Right_account.m_balance = 0;
       }
       return *this;
   }

   Account& Account::operator>>(Account& Right_account)
   {
       if ( Right_account)
       {
           Right_account.m_balance = Right_account.m_balance + m_balance;
           m_balance = 0;
       }
       return *this;
   }

   double operator+(const Account& first, const Account& second)
   {
       double sum = 0.0;
       if (first && second)
       {
           sum = double(first) + double(second);
       }
       return sum;
   }

   double operator+=(double& balance, const Account& Right_account)
   {
       double sum = 0.0;
       if (balance >= 0 && Right_account)
       {
           sum = balance += double(Right_account);
       }
       return sum;
   }
}