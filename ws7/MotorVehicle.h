#ifndef SDDS_VEHICLE_H_
#define SDDS_VEHICLE_H_
#include <iostream>   
namespace sdds {
	class MotorVehicle
	{
		char m_plateNum[9];
		char m_address[64];
		int m_year;
		MotorVehicle& setAddress(const char* address);
	public:
		MotorVehicle(const char* plateNum,int year, const char* address="Factory");
		void moveTo(const char* address);
		
		std::ostream& write(std::ostream& os = std::cout)const;
		std::istream& read(std::istream& is= std::cin);

	
	};
	
	istream& operator>>(istream& left, MotorVehicle& obj);
	ostream& operator<<(ostream& left, const MotorVehicle& obj);
}
#endif

