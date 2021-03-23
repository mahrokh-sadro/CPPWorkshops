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
		//no destructor impl
		std::istream& getSpecs(std::istream&);
		std::ostream& draw(std::ostream&) const;

	};


}
#endif