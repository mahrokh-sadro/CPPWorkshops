//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.18.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

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
      if (*this) {                       //if the account is valid???????difffrence between *this n calling operator bool f?
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
      else if(~*this) {                           //If the account is new
         cout << "  NEW  |         0.00 ";
      }
      else {
         cout << "  BAD  |    ACCOUNT   ";
      }
      return cout;
   }

   
   Account::operator bool() const  {
       return m_balance >= 0.0 && this->m_number>=10000 && this->m_number<=99999;                   
   }
   

   Account::operator int() const   {
       return (int)m_number;
   }

 
   Account::operator double() const {
       return (double)m_balance;
   }

   bool Account::operator~() const  {
       return m_number==0 ;
   }


   //Binary member operators

   Account& Account::operator=(int number)   {
     
         if(number<10000 || number>99999)     (*this).setEmpty();
         else if (!m_number) {                                   //account is new
           this->m_number = number;                              //(int)*this?
       }
       return *this;
   }

   //A = B;
   Account& Account::operator=(Account& rightOper)  {
       if ( !this->m_number && (bool)rightOper) {
           this->m_number = rightOper.m_number;
           this->m_balance = rightOper.m_balance;
           rightOper.m_balance=0.0;
           rightOper.m_number=0;
       }
       return *this;
   }

   // A += 200.0;
   Account& Account::operator+=(double balance)   {
       if ((bool)*this && balance >= 0) {
           this->m_balance += balance;
       }
       return *this;
   }

   //A -= 150.0;
   Account& Account::operator-=(double balance)  {
       if ((bool)*this && balance >= 0.0 && this->m_balance >= balance) {
           this->m_balance -= balance;
       }
       return *this;
   }
   //A << B;
   Account& Account::operator<<(Account& rightOper)  {
       if ((bool)*this && this != &rightOper) {
           this->m_balance += rightOper.m_balance;
           rightOper.m_balance=0;
       }
       return *this;
   }
   // A >> B; 
   Account& Account::operator>>(Account& rightOper)  {
       if ((bool)*this && this != &rightOper) {
           rightOper.m_balance += this->m_balance;
           this->m_balance=0;
       }
       return *this;
   }
  

//Binary helper operators

   double operator+(const Account& leftOper, const Account& rightOper)  {

                                                                         //return leftOper && rightOper?(double)leftOper + (double)rightOper:0;
       double sum = 0.0;
       if ((bool)leftOper && (bool)rightOper) {  
           sum = (double)leftOper + (double)rightOper;        
       }
       else sum = 0.0;
       return sum;
   }

   double operator+=(double& leftOper, const Account& rightOper)  {
       return leftOper+=(double)rightOper;
   }

   //int numDigitsOfAcc(int number) {//how to check the first digit is not 0???
   //    int noOfDigits = 0;
   //   
   //    int i(0);
   //    for (i = 0; number > 0; i++) {
   //        number = number / 10;
   //        noOfDigits++;
   //    }
   //    return noOfDigits;
   //   
   //}
}