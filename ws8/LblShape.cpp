//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
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

	istream& LblShape::getSpecs(std::istream& is)
	{
		string str;
		if (getline(is, str, ',')) setLabel(str.c_str());
		return is;

	}

}
