#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include <iomanip>

#include "MotorVehicle.h"

using namespace std;

namespace sdds {



	MotorVehicle& MotorVehicle::setAddress(const char* address)	{
		int len = strlen(address)>63?63:len;
		strncpy(m_address, address, len);
		m_address[len] = 0;

	}

	MotorVehicle::MotorVehicle(const char* plateNum, int year, const char* address){
		strncpy(m_plateNum, plateNum, 8);
		m_plateNum[8] = 0;
		
		setAddress(address);
		m_year = year;
	}



	void MotorVehicle::moveTo(const char* address)
	{
		if (strcmp(m_address, address) != 0) {
			
			cout << "|" << setw(8) << right << m_plateNum << "|";
			cout << setw(20) << right << m_address << "---> ";
			setAddress(address);
			cout << setw(20) << left << address << "|" << endl;////////
			//cout << *this;

		}
	}

	

	std::ostream& MotorVehicle::write(std::ostream& os) const	{
		os << " " << m_year <<" | " <<m_plateNum<<" | " <<m_address;
		return os;
	
	}

	std::istream& MotorVehicle::read(std::istream& is)	{
		bool done = false;
		//year
		unsigned year;
		cout<<"Built year: ";		
		while (!done) {
			is >> year;
			if (is.fail()) {
				is.clear();
				is.ignore(3000, '\n');
			}
			else done = true;
		}
		//platenum 9chars
		char plateNum[9];
		cout << "License plate: ";
		is.getline(plateNum, 9);
		if (is.fail()) {
			is.clear();
			is.ignore(3000, '\n');
		}
		//address 64 chars
		char address[64];
		cout << "Current location: ";
		is.getline(address, 64);
		if (is.fail()) {
			is.clear();
			is.ignore(3000, '\n');
		}
		return is;
	}

	
	istream& operator>>(istream& left, MotorVehicle& obj) {
		return obj.read(left);
	}

	ostream& operator<<(ostream& left, const MotorVehicle& obj) {
		return obj.write(left);
	}

}