//mahrokh was here


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

   std::istream& TriagePatient::read(std::istream& is)
   {
    
       if (fileIO() == true) csvRead(is);
       else
       {
           delete[] m_symptoms;
           Patient::read(is);
          std:: cout << "Symptoms: ";
           m_symptoms = getcstr();

       }
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


    std::istream& TriagePatient::csvRead(std::istream& istr)
    {
       delete[] m_symptoms;
       Patient::csvRead(istr);
       istr.ignore();
       std::string str;
       std::getline(istr,str);
       m_symptoms = new char[str.length() + 1];
       strcpy(m_symptoms, str.c_str());
       nextTriageTicket = Patient::number() + 1;
       return istr;
    }
 
   std::ostream& TriagePatient::csvWrite(std::ostream& os) const
   {
      Patient::csvWrite(os);
      return os << ',' << m_symptoms;
   }
}
