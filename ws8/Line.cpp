
#include <iostream>
#include <iomanip>
#include "Line.h"
using namespace std;
namespace sdds {

	Line::Line() :LblShape()
	{
		m_length = 0;
	}

	Line::Line(const char* cstr, unsigned length)
		:LblShape(cstr), m_length{ length }{}
	

	

	istream& Line::getSpecs(istream& is)
	{
		LblShape::getSpecs(is);
		unsigned length;
		is >> length;
		m_length = length;
		is.ignore(1000, '\n');//up to n \n?
		return is;
	}

	ostream& Line::draw(ostream& os) const
	{
		if (m_length > 0 && label())//?
		{
			os << label()<< endl;
			//os << setw(m_length) << setfill('=') << endl;
			for (unsigned i = 0; i < m_length; i++) os << '=';

		}
		return os;
	}




}

