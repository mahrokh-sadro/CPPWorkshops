
/* Citation and Sources...
Final Project Milestone 4
Module: CovidPatient
Filename: CovidPatient.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/28  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

#include <iostream>
#include "CovidPatient.h"
using namespace std;
namespace sdds {
	int nextCovidTicket = 1;

	CovidPatient::CovidPatient()
		: Patient(nextCovidTicket)
	{
		nextCovidTicket += 1;
	}

	char CovidPatient::type() const
	{
		return 'C';
	}

	std::istream& CovidPatient::csvRead(std::istream& is)
	{
		Patient::csvRead(is);
		nextCovidTicket = Patient::number() + 1;
		is.ignore();///
		return is;
	}

	std::ostream& CovidPatient::write(std::ostream& os) const
	{
		if (Patient::fileIO() == true)   Patient::csvWrite(os);
		else
		{
			os << "COVID TEST" << endl;
			Patient::write(os) << endl;
		}
		return os;
	}

	std::istream& CovidPatient::read(std::istream& is)
	{
		if (Patient::fileIO() == true)   csvRead(is);
		else Patient::read(is);
		return is;

	}

}