//#ifndef SDDS_TRIAGEPATIENT_H
//#define SDDS_TRIAGEPATIENT_H
//#include "Patient.h"
//
//namespace sdds {
//    class TriagePatient : public Patient{
//        private:
//            char *m_symptoms;
//        public:
//            TriagePatient();
//            ~TriagePatient();
//            char type() const;
//            std::istream& read(std::istream& istr);
//            std::ostream& write(std::ostream& ostr) const;
//            std::istream& csvRead(std::istream& istr);
//            std::ostream& csvWrite(std::ostream& ostr) const;
//    };
//}
//#endif // !SDDS_TRIAGEPATIENT_H
//
//
/* Citation and Sources...
Final Project Milestone 4
Module: TriagePatient
Filename: TriagePatient.h
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


#ifndef SDDS_TRIAGEPATIENT_H
#define SDDS_TRIAGEPATIENT_H

#include <iostream>
#include "Patient.h"
namespace sdds {
	class TriagePatient :public Patient {
		char* m_symptoms;
	public:
		TriagePatient();
		char type() const;
		std::ostream& csvWrite(std::ostream& os = std::cout)const;
		std::istream& csvRead(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;
		std::istream& read(std::istream& is = std::cin);
		virtual ~TriagePatient();

	};
}
#endif // !SDDS_TRIAGEPATIENT_H


