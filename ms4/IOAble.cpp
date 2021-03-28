/* Citation and Sources...
Final Project Milestone 3
Module: IOAble
Filename: IOAble.h
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/25  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#include <iostream>
#include "IOAble.h"
using namespace std;
namespace sdds {

	istream& operator>>(istream& is, IOAble& obj)
	{
		return obj.read(is);
	}

	ostream& operator<<(ostream& os, const IOAble& obj)
	{
		return obj.write(os);
	}

}