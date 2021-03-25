//author:Fardad Soleimanloo
#ifndef SDDS_TICKET_H_
#define SDDS_TICKET_H_
#include "Time.h"
#include "IOAble.h"
namespace sdds {
   class Ticket:public IOAble{
      Time m_time;//time that ticket was issued
      int m_number;//ticket number
   public:
      Ticket(int number);
      operator Time()const;//when ticket casted to time it will return m_time
      int number()const;//returns the number of ticket
      void resetTime();//sets the ticket time to the current time
      std::ostream& csvWrite(std::ostream& ostr)const;//Inserts comma-separated ticket number and time into ostream.
      std::istream& csvRead(std::istream& istr);//Extracts the ticket number and time in a comma-separated format from istream.
      std::ostream& write(std::ostream& ostr )const;//Inserts a ticket into the ostream to be displayed on the console.
      std::istream& read(std::istream& istr);//Extracts the ticket information from istream. This function works the same as csvRead.
   };
}
#endif // !SDDS_TICKET_H_
