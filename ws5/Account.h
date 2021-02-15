#ifndef SDDS_ACCOUNT_H_
#define SDDS_ACCOUNT_H_
#include <iostream>

namespace sdds {
   class Account {
      int m_number; //account number
      double m_balance; //balance
      void setEmpty();
   public:
      Account();
      Account(int number, double balance);
      std::ostream& display()const;
      operator bool() const;
      operator int() const;
      operator double() const;
      bool operator ~() const;

      Account& operator=(int number);
      Account& operator=(Account& rightOper);
      Account& operator+=(double balance);
      Account& operator-=(double balance);
      Account& operator<<(Account& rightOper);
      Account& operator>>(Account& rightOper);
     // friend double operator+(const Account& leftOper, const Account& rightOper);
   };
   int numDigitsOfAcc(int number);    //mine
   double operator+(const Account& leftOper, const Account& rightOper);
   double operator+=(double& leftOper, const Account& rightOper);
}
#endif // SDDS_ACCOUNT_H_