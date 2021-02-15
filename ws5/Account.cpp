#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
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
      if (*this) {                       //if the account is valid???????difffrence between *this n calling operator bool f???????????????????????????????????????????
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

   int numDigitsOfAcc(int number) {//how to check the first digit is not 0???
       int noOfDigits = 0;
      
       int i(0);
       for (i = 0; number > 0; i++) {
           number = number / 10;
           noOfDigits++;
       }
       return noOfDigits;
      
   }

  
   //type conversion operators
  /* returns true if the account is valid and otherwise
       false.This operator can not modify the account 
       object.*/


   //An Account is considered valid if the account 
   //    number is a 5 digit integer with a zero or 
   //    positive balance.
   Account::operator bool() const  {//how to xheck its int???
       return m_balance >= 0.0 && (numDigitsOfAcc(this->m_number) == 5);     //how to check the first number is not 0
   }//how to check if its an int???????????????????????????????????????????????????????????????????????????????????????????????????????????????????????????
   //calling int is wrong



  /* returns the account number.This operator can not
       modify the account object.*/
   Account::operator int() const   {
       return (int)m_number;
   }

  /* returns the balance value.This operator can not
       modify the account object.*/
   Account::operator double() const {
       return (double)m_balance;
   }

   bool Account::operator~() const  {
       return m_number==0 ;
   }




   //Binary member operators


//Note: All the binary member operators will not 
//take any action if the account is in an invalid state.


   Account& Account::operator=(int number)   {//i changed the numOddigits f so it can be used for input
      // if (~*this)  (*this).setEmpty();           //or setEmpty()
         if(numDigitsOfAcc(number) !=5)     (*this).setEmpty();
         else if (!m_number) {     //account is new
           this->m_number = number;                   //(int)*this?????????????????????????????????????????????????????????????????????????????????????????????????????
       }
       return *this;
   }

   //A = B;
   Account& Account::operator=(Account& rightOper)  {//left operator is the current obj
       if (  /**this && */!this->m_number && (bool)rightOper) {
           this->m_number = rightOper.m_number;
           this->m_balance = rightOper.m_balance;
           rightOper.setEmpty();
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
       if ((bool)leftOper && (bool)rightOper) {  //correct for being valid?????????????????????????????????????????????????????????????????????????????
           sum = (double)leftOper + (double)rightOper;           //leftOper.m_balance + rightOper.m_balance;
       }
       else sum = 0.0;
       return sum;
   }

   double operator+=(double& leftOper, const Account& rightOper)  {
       return leftOper+=(double)rightOper;
   }

}
