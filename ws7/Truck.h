

#ifndef SDDS_TRUCK_H
#define SDDS_TRUCK_H

#include <iostream>
#include "MotorVehicle.h"


namespace sdds
{
	class Truck : public MotorVehicle
	{
		double m_capacity;
		double m_volume;
	public:
		Truck(const char* theplateNum, int theyear,
			double thecapacity, const char* currentAddress);
		bool addCargo(double cargo);
		bool unloadCargo();
		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);
	};
	std::istream& operator>>(std::istream& left, Truck& obj);
	std::ostream& operator<<(std::ostream& left, const Truck& obj);
}
#endif

