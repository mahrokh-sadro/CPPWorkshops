//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_SHAPE_H_
#define SDDS_SHAPE_H_
#include <iostream>
namespace sdds {
	class Shape {
	public:
		virtual std::ostream& draw(std::ostream& os=std::cout) const = 0;
		virtual std::istream& getSpecs(std::istream& is=std::cin)=0;
		virtual ~Shape() {};

	};
	std::istream& operator>>(std::istream& is, Shape& obj);
	std::ostream& operator<<(std::ostream& os, const Shape& obj);
}
#endif