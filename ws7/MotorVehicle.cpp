

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>







#include <iomanip>
#include <string>



#include "MotorVehicle.h"
#include "cstring.h"
using namespace std;
namespace sdds
{
	void MotorVehicle::setPlateNumber(const char* platenum)	{
		int len = strlen(platenum) > 8 ? 8 : strlen(platenum);
		strncpy(m_plateNum, platenum, len);
		m_plateNum[len] = 0;
	}


	void MotorVehicle::setAddress(const char* address)	{
		int len = strlen(address) > 63 ? 63 : strlen(address);
		strncpy(m_address, address, len);
		m_address[len] = 0;
	}



	MotorVehicle::MotorVehicle(const char* plateNum, int year, const char* address)	{
		setPlateNumber(plateNum);
		setAddress(address);
		m_year = year;

	}
	void MotorVehicle::moveTo(const char* address)	{
		if (strcmp(m_address, address) != 0)
		{
			cout << "|" << setw(8) << right << m_plateNum << "| |";
			cout << setw(20) << right << m_address << " ---> ";
			setAddress(address);
			cout << setw(20) << left << address << "|" << endl;
			//cout << *this;
		}
	}
	std::ostream& MotorVehicle::write(std::ostream& os) const	{
		os << "| " << m_year << " | " << m_plateNum << " | " << m_address;
		return os;
	}
	std::istream& MotorVehicle::read(std::istream& is)	{
		int year;
		string platenum, address;
		cout << "Built year: ";
		is >> year;
		m_year = year;

		cout << "License plate: ";
		is.ignore();
		getline(is, platenum);
		setPlateNumber(platenum.c_str());


		//address 64 chars
		cout << "Current location: ";
		//is.ignore();   it removes the forst ltter of location!!!!!!!!!!!!!!!1
		getline(is, address);
		setAddress(address.c_str());


		return is;
	}
	//where do I go wrong??????????????????


	//std::istream& MotorVehicle::read(std::istream& is) {
	//	bool done = false;
	//	//year
	//	unsigned year;
	//	cout << "Built year: ";
	//	while (!done) {
	//		is >> year;
	//		if (is.fail()) {
	//			is.clear();
	//			is.ignore(3000, '\n');
	//		}
	//		else done = true;
	//		m_year = year;
	//	}
	//	//platenum 9chars
	//	char plateNum[9];
	//	cout << "License plate: ";
	//	is.getline(plateNum, 8);
	//	if (is.fail()) {
	//		is.clear();
	//		is.ignore(3000, '\n');
	//	}
	//	setPlateNumber(plateNum);
	//	//address 64 chars
	//	char address[64];
	//	cout << "Current location: ";
	//	is.getline(address, 63);
	//	if (is.fail()) {
	//		is.clear();
	//		is.ignore(3000, '\n');
	//	}
	//	setAddress(address);
	//	return is;
	//}




	std::istream& operator>>(std::istream& left, MotorVehicle& obj)	{
		return obj.read(left);
	}
	std::ostream& operator<<(std::ostream& left, const MotorVehicle& obj)	{
		return obj.write(left);
	}
}
