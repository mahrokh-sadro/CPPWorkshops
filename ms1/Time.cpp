#include <iostream>
#include <iomanip>
#include "Time.h"
#include "utils.h"
using namespace std;
namespace sdds {
	Time& Time::setToNow()	{

		*this = sdds::getTime();
		return *this;

	}
	Time::Time(unsigned int min)	{
		m_min = min;
	}


	//Writes the time into a stream in HH : MM format padding 
	//	the spaces with zero if the numbers are single 
	//	digit(examples 03:02, 16 : 55 234 : 06)

	std::ostream& Time::write(std::ostream& ostr) const	{
		ostr << setw(2) << setfill('0') << m_min/60;
		ostr << ":" << setw(2)<<setfill('0')<<m_min%60;
		return ostr;
	}
	std::istream& Time::read(std::istream& istr)	{
		int hour;
		int min;
		char ch;
		bool done = false;
		istr >> hour;
		//while(!done)
		if(hour<0) istr.setstate(ios::failbit);
		istr.get(ch);
		if (ch != ':')  istr.setstate(ios::failbit);
		istr >> min;
		if (min < 0) istr.setstate(ios::failbit);
		return istr;
	}
	Time& Time::operator-=(const Time& D){
		int n = (D.m_min % 24) + 1;
		m_min > D.m_min ? m_min - D.m_min : m_min +24* n - D.m_min;
			return *this;

	}
	Time Time::operator-(const Time& D) const{
		int n = (D.m_min % 24) + 1;
		int ret=m_min > D.m_min ? m_min - D.m_min : m_min + 24 * n - D.m_min;
		return Time(ret);
	}
	Time& Time::operator+=(const Time& D){
		m_min += D.m_min;
		return *this;
	}
	Time Time::operator+(const Time& D) const{
		return Time(m_min + D.m_min);
	}
	Time& Time::operator=(unsigned int val)	{
		m_min = val;
		return *this;
	}
	Time& Time::operator*=(unsigned int val)	{
		m_min *= val;
		return *this;
	}
	Time& Time::operator/=(unsigned int val)	{
		m_min /= val;
		return *this;
	}
	Time Time::operator*(unsigned int val) const{
		return Time(m_min * val	);
	}
	Time Time::operator/(unsigned int val) const	{
		return Time(m_min / val	);
	}
	Time::operator unsigned int() const	{
		return (unsigned int)m_min;
	}
	Time::operator int() const	{
		return (int)m_min;

	}
	std::ostream& operator<<(std::ostream& ostr, const Time& D)	{
		return D.write(ostr);
	}
	std::istream& operator>>(std::istream& istr, Time& D){
		return D.read(istr);
	}
}