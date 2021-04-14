
/* Citation and Sources...
Final Project Milestone 5
Module: TriagePatient
Filename: TriagePatient.h
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


