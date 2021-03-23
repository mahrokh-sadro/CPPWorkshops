#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <string>
#include <cstring>

#include "LblShape.h"

using namespace std;
namespace sdds {






	void LblShape::setLabel(const char* label)
	{
		delete[] m_label;
		m_label = nullptr;
		if (label)
		{
			m_label = new char[strlen(label) + 1];
			strcpy(m_label, label);
		}

	}

	const char* LblShape::label() const
	{
		return (const char*)m_label;
	}

	LblShape::LblShape():m_label{nullptr}
	{
	}

	LblShape::LblShape(const char* label):m_label{nullptr}
	{
		setLabel(label);

	}

	LblShape::~LblShape()
	{
		delete[] m_label;
	}
	/*Reads a comma - delimited Cstring form istream :
	Override the Shape::getSpecs pure virtual function
		to receive a Cstring(a label) from istream up to
		the ',' character(and then extract and ignore the comma).
		Afterward, follow the same logic as was done in the one 
		argument constructor; allocate memory large enough to 
		hold the Cstringand copy the Cstring into the newly allocated memory.*/


	istream& LblShape::getSpecs(std::istream& is)
	{
		string str;
	//	is.ignore();
	//	is.ignore();
		if (getline(is, str, ','))//???
		{
			
			setLabel(str.c_str());

		}
		return is;

	}

}
