//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <cstring>
#include "Rectangle.h"
using namespace std;
namespace sdds {


	void Rectangle::setEmpty()
	{
		m_width = 0;
		m_height = 0;
	}

	bool Rectangle::isEmpty() const
	{
		return  (m_height < 3 || m_width < ((strlen(LblShape::label()) + 2)));
	}

	Rectangle::Rectangle()
	{
		m_width = 0;
		m_height = 0;
	}

	Rectangle::Rectangle(const char* thelabel, unsigned width, unsigned height)
		: LblShape(thelabel), m_width{ width }, m_height{ height }
	{
	
		if (m_height<3 || m_width<((strlen(LblShape::label()) + 2)))
		{
			setEmpty();
		}
		
	}


	istream& Rectangle::getSpecs(istream& is)
	{
		unsigned width(0);
		unsigned height(0);
		LblShape::getSpecs(is);		
		is >> width;
		m_width = width;
		is.ignore();		
		is >> height;
		m_height = height;
		is.ignore(1000, '\n');
		return is;

	}

	
	ostream& Rectangle::draw(ostream& os) const
	{
		if (!isEmpty()) {

			os << '+';
			for (unsigned i = 0; i < m_width - 2; i++) os << '-';
			os << '+'<< endl;
			os << '|' << setw(m_width - 2) << setfill(' ') << left << label() << '|' << endl;

			for (unsigned i = 0; i < (m_height - 3); i++)
			{
				os << setw(m_width - 1) << setfill(' ') << '|' <<  '|' << endl;
			}
			os << setw(m_width - 1) << setfill('-') << '+' << '+';

		}
		return os;
	}


}