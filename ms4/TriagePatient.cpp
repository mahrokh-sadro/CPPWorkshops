/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/28  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/



#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <cstring>
#include "TriagePatient.h"
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

   char TriagePatient::type() const
   {
	   return 'T';
   }

   std::ostream& TriagePatient::csvWrite(std::ostream& os) const
   {
	   Patient::csvWrite(os);
	   return os << "," << m_symptoms;
   }

 
   std::istream& TriagePatient::csvRead(std::istream& is)
   {
	   delete[] m_symptoms;
	   Patient::csvRead(is);
	   is.ignore();
	   m_symptoms = getcstr();
	   nextTriageTicket = number() + 1;
	   return is;
   }
  
   std::ostream& TriagePatient::write(std::ostream& os) const
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
 

   std::istream& TriagePatient::read(std::istream& is)
   {
	   if (fileIO() == true) csvRead(is);
	   else
	   {
		   delete[] m_symptoms;
		   Patient::read(is);
		   cout<< "Symptoms: ";
		   m_symptoms= getcstr();
		   
	   }
	   return is;
   }

   TriagePatient::~TriagePatient()
   {
	   delete[] m_symptoms;
	   m_symptoms = nullptr;
   }

}