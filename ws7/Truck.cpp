#include <iostream>
using namespace std;
#include "Truck.h"
namespace sdds {




	// Set the current cargo to 0 and move the truck to the address specified in the last parameter.

	Truck::Truck(const char* theplateNum, int theyear, double thecapacity, const char* currentAddress)
		:MotorVehicle(theplateNum, theyear, currentAddress) {
		m_volume = 0.000000000;
		m_capacity = thecapacity;
	}

	bool Truck::addCargo(double cargo)	{
		bool ret = true;
		if (m_volume += cargo <= m_capacity) m_volume += cargo;
		else ret = false;
		return ret;

	}

	bool Truck::unloadCargo()	{
		bool ret =true;
		if (m_volume != 0) m_volume = 0;
		else ret = false;
		return ret;
	}



	std::ostream& Truck::write(std::ostream& os) const	{
		MotorVehicle::write(os);
		os << " | " << m_volume<<"/" << m_capacity;
		return os;
	}

	//std::istream& Truck::read(std::istream& is)	{
	//	MotorVehicle::read(is);
	//	bool done = false;

	//	double volume;
	//	cout << "Capacity: ";
	//	while (!done) {
	//		is >> volume;
	//		if (is.fail()) {
	//			is.clear();
	//			is.ignore(3000, '\n');
	//		}
	//		else done = true;
	//	}

	//	cout << "Cargo: ";
	//	double capacity;
	//	while (!done) {
	//		is >> capacity;
	//		if (is.fail()) {
	//			is.clear();
	//			is.ignore(3000, '\n');
	//		}
	//		else done = true;
	//	}
	//	return is;
	//}
	//	
	
	istream& operator>>(istream& left, Truck& obj)	{
		return obj.read(left);
	}

	ostream& operator<<(ostream& left, const Truck& obj)	{
		return obj.write(left);
	}

}
