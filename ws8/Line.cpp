//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

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
		is.ignore(1000, '\n');
		return is;
	}

	ostream& Line::draw(ostream& os) const
	{
		if (m_length > 0 && label())
		{
			os << label()<< endl;
			for (unsigned i = 0; i < m_length; i++) os << '=';

		}
		return os;
	}




}

