

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