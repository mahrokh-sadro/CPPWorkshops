#ifndef SDDS_RECTANGLE_H_
#define SDDS_RECTANGLE_H_

#include "LblShape.h"
namespace sdds {
	class Rectangle :public LblShape {

		unsigned m_width;
		unsigned m_height;
		void setEmpty();//mine
		bool isEmpty() const;//mine
	public:
		Rectangle();
		Rectangle(const char* thelabel, unsigned width, unsigned height);
		//no destructor impl
		std::istream& getSpecs(std::istream&);
		std::ostream& draw(std::ostream&) const;

	};






}
#endif