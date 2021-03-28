/* Citation and Sources...
Final Project Milestone 3
Module: IOAble
Filename: IOAble.cpp
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

#ifndef SDDS_IOABLE_H_
#define SDDS_IOABLE_H_

#include <iostream>
namespace sdds {

	class IOAble {
	public:
		virtual std::ostream& csvWrite(std::ostream& os=std::cout) const = 0;
		virtual std::istream& csvRead(std::istream& is = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual ~IOAble() {};

	};
	std::istream& operator>>(std::istream& is, IOAble& obj);
	std::ostream& operator<<(std::ostream& os, const IOAble& obj);
}
#endif