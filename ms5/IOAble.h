//#ifndef SDDS_IOABLE_H
//#define SDDS_IOABLE_H
//#include <iostream>
//namespace sdds {
//    class IOAble{
//        public:
//            virtual std::ostream& csvWrite(std::ostream&) const = 0;
//            virtual std::istream& csvRead(std::istream&) = 0;
//            virtual std::ostream& write(std::ostream&) const = 0;
//            virtual std::istream& read(std::istream&) = 0;
//            virtual ~IOAble() {};
//    };
//    std::ostream& operator<<(std::ostream &left, const IOAble &obj);
//    std::istream& operator>>(std::istream &left, IOAble &obj);
//}
//#endif
/* Citation and Sources...
Final Project Milestone 4
Module: IOAble
Filename: IOAble.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/28  Preliminary release

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
		virtual std::ostream& csvWrite(std::ostream& os = std::cout) const = 0;
		virtual std::istream& csvRead(std::istream& is = std::cin) = 0;
		virtual std::ostream& write(std::ostream& os = std::cout) const = 0;
		virtual std::istream& read(std::istream& is = std::cin) = 0;
		virtual ~IOAble() {};

	};
	std::istream& operator>>(std::istream& is, IOAble& obj);
	std::ostream& operator<<(std::ostream& os, const IOAble& obj);
}
#endif