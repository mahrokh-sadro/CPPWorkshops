
#include <iostream>
#include "Truck.h"
using namespace std;


namespace sdds
{
	
	Truck::Truck(const char* theplateNum, int theyear, double thecapacity, const char* currentAddress)
		:MotorVehicle(theplateNum, theyear) {
		m_volume = 0.000000000;
		
		m_capacity = thecapacity;
		moveTo(currentAddress);
	}
	

	bool Truck::addCargo(double cargo) {
		bool ret = true;
		if (m_volume == m_capacity) ret = false;     //the only situation that m_volume doesnt change

		else if  (m_volume + cargo <= m_capacity) m_volume += cargo;
		else m_volume = m_capacity;
		return ret;
  	}
			
		





	bool Truck::unloadCargo() {
		bool ret = true;
		if (m_volume != 0) m_volume = 0;
		else ret = false;
		return ret;
	}


	
	std::ostream& Truck::write(std::ostream& os) const	{

		MotorVehicle::write(os);
		os << " | " << m_volume << "/" << m_capacity;
		return os;
	}




	std::istream& Truck::read(std::istream& is)	{

		MotorVehicle::read(is);
		double capacity;
		cout << "Capacity: ";
		is >> capacity;
		m_capacity = capacity;



		double  volume;
		
		cout << "Cargo: ";
		is >> volume;
		m_volume = volume;
		
		return is;
	}
	istream& operator>>(istream& left, Truck& obj)	{
		return obj.read(left);
	}
	ostream& operator<<(ostream& left, const Truck& obj)	{
		return obj.write(left);
	}
}