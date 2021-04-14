
/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Id 159436195
msadrolodabaee@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/4/10  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#define _CRT_SECURE_NO_WARNINGS
#include "TriagePatient.h"
#include <iostream>
#include <string>
#include <cstring>
#include "utils.h"

using namespace std;
namespace sdds {
   int nextTriageTicket = 1;
  
   TriagePatient::TriagePatient()
       : Patient(nextTriageTicket),
       m_symptoms{ nullptr }
   {
       nextTriageTicket += 1;
   }

   TriagePatient::~TriagePatient()
   {
      delete[] m_symptoms;
      m_symptoms = nullptr;

   }

   char TriagePatient::type() const
   {
      return 'T';
   }

   istream& TriagePatient::read(istream& is)
   {
    
       if (fileIO() == true) csvRead(is);
       else
       {
           delete[] m_symptoms;
           Patient::read(is);
           cout << "Symptoms: ";
           m_symptoms = getcstr("",is);
       }
       return is;
   }

   ostream& TriagePatient::write(ostream& os) const
   {
       if (fileIO() == true) csvWrite(os);
       else
       {
           os << "TRIAGE" << endl;
           Patient::write(os) << endl;
           return os << "Symptoms: " << m_symptoms << endl;
       }
       return os;
   }

    istream& TriagePatient::csvRead(istream& istr)
    {
       delete[] m_symptoms;
       Patient::csvRead(istr);
       istr.ignore();
       m_symptoms = getcstr("",istr);
       nextTriageTicket = Patient::number() + 1;
       return istr;
    }
 
   std::ostream& TriagePatient::csvWrite(std::ostream& os) const
   {
      Patient::csvWrite(os);
      return os << ',' << m_symptoms;
   }
}