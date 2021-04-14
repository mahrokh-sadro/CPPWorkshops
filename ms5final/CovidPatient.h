
/* Citation and Sources...
Final Project Milestone 5
Module: CovidPatient
Filename: CovidPatient.h
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

#ifndef SDDS_COVIDPATIENT_H_
#define SDDS_COVIDPATIENT_H_
#include "Patient.h"
#include <iostream>
namespace sdds {

	class CovidPatient :public Patient {

	public:
		CovidPatient();
		char type()const;
		std::istream& csvRead(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout)const;
		std::istream& read(std::istream& is = std::cin);

	};
}
#endif // !SDDS_COVIDPATIENT_H_



