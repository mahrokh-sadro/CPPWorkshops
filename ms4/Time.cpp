/* Citation and Sources...
Final Project Milestone 3
Module: Time
Filename: Time.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/25  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#include <iostream>
#include <iomanip>
#include <cmath>
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds {
	Time& Time::setToNow() {

		*this = sdds::getTime();
		return *this;

	}
	Time::Time(unsigned int min) {
		m_min = min;
	}

	std::ostream& Time::write(std::ostream& ostr) const {
		ostr << setw(2) << setfill('0') << m_min / 60;
		ostr << ":" << setw(2) << setfill('0') << m_min % 60;
		return ostr;
	}
	std::istream& Time::read(std::istream& istr) {
		int hour(0);
		int min(0);
		char ch(0);

		istr >> hour;
		istr.get(ch);
		istr >> min;

		if (hour < 0 || min < 0 || ch != ':') istr.setstate(ios::failbit);
		else m_min = hour * 60 + min;
		return istr;
	}
	Time& Time::operator-=(const Time& D) {
		int n = ceil((double)D.m_min / (24 * 60));
		m_min = m_min >= D.m_min ? m_min - D.m_min : (m_min + 24 * 60 * n) - D.m_min;
		return *this;

	}
	Time Time::operator-(const Time& D) const {

		int n = ceil((double)D.m_min / (24 * 60));
		int ret = m_min >= D.m_min ? m_min - D.m_min : (m_min + 24 * 60 * n) - D.m_min;
		return Time(ret);
	}
	Time& Time::operator+=(const Time& D) {
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const {
		return Time(m_min + D.m_min);
	}
	Time& Time::operator=(unsigned int val) {
		m_min = val;
		return *this;
	}
	Time& Time::operator*=(unsigned int val) {
		m_min *= val;
		return *this;
	}
	Time& Time::operator/=(unsigned int val) {
		m_min /= val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const {
		return Time(m_min * val);
	}
	Time Time::operator/(unsigned int val) const {
		return Time(m_min / val);
	}
	Time::operator unsigned int() const {
		return (unsigned int)m_min;
	}
	Time::operator int() const {
		return (int)m_min;

	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D) {
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D) {
		return D.read(istr);
	}
}