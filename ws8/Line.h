//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_LINE_H_
#define SDDS_LINE_H_

#include <iostream>
#include "LblShape.h"
namespace sdds {

	class Line :public LblShape {
		unsigned m_length=0;
	public:
		Line();
		Line(const char* cstr,unsigned length);
		std::istream& getSpecs(std::istream&);
		std::ostream& draw(std::ostream&) const;

	};


}
#endif