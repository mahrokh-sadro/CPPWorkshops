#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Mark.h"
//#define SDDS_DEBUG
using namespace std;
namespace sdds {
	//   0< =m_value=<100
	void Mark::setEmpty() {

		m_value = 0;
	}

	Mark::Mark() {
		//m_value = 0;

		setEmpty();
	}

	Mark::Mark(int value) {

		if (value >= 0 && value <= 100) {
			setEmpty();
			m_value = value;
		}
	}

	//check if its in range
	Mark::operator bool() const	{//  (bool)obj
#ifdef  SDDS_DEBUG

		cout << "operator bool()" << endl;
#endif
		return m_value >= 0 && m_value <= 100;
	}

	Mark::operator int() const	{
#ifdef  SDDS_DEBUG

		cout << "operator int()" << endl;
#endif
		return (bool)*this ? this->m_value : 0;
	}

	Mark& Mark::operator+=(int value)	{
#ifdef  SDDS_DEBUG

		cout << "operator+=" << endl;
#endif
		if ((bool)*this)  this->m_value += value;
		//else this->m_value = 0;

		return *this;
	}

	Mark& Mark::operator=(int value)	{//doesnt it set to ????
#ifdef  SDDS_DEBUG

		cout << "operator=" << endl;
#endif
		//this->m_value = value >= 0 && value <= 100 ?  value :0;
		this->m_value = value;

		return *this;
	}

	Mark::operator double() const	{//switch /////////////////////////////////////////////////////////////////////////////
#ifdef  SDDS_DEBUG

		cout << "operator double()" << endl;
#endif
		double gpa = 0.0;
		   // if(!(bool)*this)         gpa = 0.0;
			if (0 <= m_value && m_value < 50)            gpa = 0.0;
			else if (50 <= m_value && m_value < 60)      gpa = 1.0;
			else if (60 <= m_value && m_value < 70)      gpa = 2.0;
			else if (70 <= m_value && m_value < 80)      gpa = 3.0;
			else if (80 <= m_value && m_value <= 100)    gpa = 4.0;
			else                                         gpa = 0.0;
			
	
		     return gpa;
		
	}



	Mark::operator char() const	{
#ifdef  SDDS_DEBUG

		cout << "operator char()" << endl;
#endif
		char gpa=0;
	   if(!(bool)*this)                              gpa = 'X';
	   else if (0 <= m_value && m_value < 50)        gpa = 'F';
		else if (50 <= m_value && m_value < 60)      gpa = 'D';
		else if (60 <= m_value && m_value < 70)      gpa = 'C';
		else if (70 <= m_value && m_value < 80)      gpa = 'B';
		else if (80 <= m_value && m_value <= 100)    gpa = 'A';
		//else                                        gpa = 'X';
	

		return gpa;
		
	}

	
    int operator+=(int& leftOper, const Mark& rightOper){

		return leftOper += (int)rightOper;
	}

}
