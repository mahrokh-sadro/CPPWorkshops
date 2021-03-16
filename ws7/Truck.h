#ifndef SDDS_TRUCK_H_
#define SDDS_TRUCK_H_
#include <iostream>  
#include "MotorVehicle.h"
 
namespace sdds {

	class Truck :public MotorVehicle {
		double m_capacity;
		double m_volume;

	public:
		Truck(const char* theplateNum,unsigned theyear,
			double thecapacity,const char* currentAddress);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os/* = std::cout*/)const;
		std::istream& read(std::istream& is /*= std::cin*/);


	};
	istream& operator>>(istream& left, Truck& obj);
	ostream& operator<<(ostream& left, const Truck& obj);
}

#endif
