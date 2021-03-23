//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"
namespace sdds {
	class Rectangle :public LblShape {

		unsigned m_width;
		unsigned m_height;
		void setEmpty();
		bool isEmpty() const;
	public:
		Rectangle();
		Rectangle(const char* thelabel, unsigned width, unsigned height);
		std::istream& getSpecs(std::istream&);
		std::ostream& draw(std::ostream&) const;

	};


}
#endif