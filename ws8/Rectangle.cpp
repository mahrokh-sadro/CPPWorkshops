
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
		/*m_width = width;
		m_height = height;*/
		if (m_height<3 || m_width<((strlen(LblShape::label()) + 2)))
		{
			setEmpty();
		}
		
	}

	/*Reads comma - separated specs of the Rectangle from istream.
		This function overrides the getSpecs function of the base class as follows.
		First, it will call the getSpecs function of the base class,
		then it will read two comma - separated values from istream
		for m_width and m_length and then ignores the rest of the
			characters up toand including the newline character('\n').*/



	istream& Rectangle::getSpecs(istream& is)
	{
		unsigned width(0);
		unsigned height(0);
		LblShape::getSpecs(is);
		//is.ignore();//?????
		
		is >> width;
		m_width = width;
		is.ignore();

		
		is >> height;//length or height?????
		m_height = height;              //////////////////////////////////////////////////////////????????

		is.ignore(1000, '\n');
		return is;

	}

	

	/*This function overrides the draw function of the base class.
		If the Rectangle is not in an empty state, this function will draw a rectangle
		with a label inside as follows, otherwise, it will do nothing :

		First line :
	prints '+', then prints the '-' character(m_width - 2) times and then prints 
		'+' and goes to newline.

		Second line :
	prints '|', then in(m_width - 2) spaces it prints the label() left justifiedand 
		then prints '|' and goes to new line.

		In next(m_height - 3) lines :
		prints '|', (m_width - 2) spaces then prints '|' and goes to new line.

		Last line : exactly like first line.*/
	ostream& Rectangle::draw(ostream& os) const
	{
		if (!isEmpty()) {

			//os << endl;
			//os << '+';
			//prints '+', then prints the '-' character(m_width - 2) times and then prints '+' and goes to newline.
			os << '+';
			for (unsigned i = 0; i < m_width - 2; i++) os << '-';
			os << '+'<< endl;
			os << '|' << setw(m_width - 2) << setfill(' ') << left << label() << '|' << endl;///

			for (unsigned i = 0; i < (m_height - 3); i++)
			{
				os << setw(m_width - 1) << setfill(' ') << '|' <<  '|' << endl;
			}
			os << setw(m_width - 1) << setfill('-') << '+' << '+'/* << endl*/;

		}
		return os;
	}







}