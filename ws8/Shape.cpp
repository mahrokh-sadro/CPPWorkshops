//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////


#include <iostream>
#include "Shape.h"
using namespace std;
namespace sdds {

	ostream& operator<<(ostream& os, const Shape& obj)
	{
		return obj.draw(os);
		
	}

	istream& operator>>(istream& is, Shape& obj)
	{
		return obj.getSpecs(is);
	}

}