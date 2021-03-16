//#ifndef SDDS_VEHICLE_H
//#define SDDS_VEHICLE_H
//#include <iostream>
//
//namespace sdds
//{
//	class MotorVehicle
//	{
//		char m_plateNum[9];
//		char m_address[64];
//		int m_year;
//		void setNumberPlate(const char* platenum);
//		void setAddress(const char* address);
//	public:
//		MotorVehicle(const char* plateNum, int year, const char* address = "Factory");
//		void moveTo(const char* address);
//		std::ostream& write(std::ostream& os /*= std::cout*/) const;
//		std::istream& read(std::istream& in /*= std::cin*/);
//	};
//	std::istream& operator>>(std::istream& left, MotorVehicle& obj);
//	std::ostream& operator<<(std::ostream& left, const MotorVehicle& obj);
//}
//#endif
//


//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstring>
//#include <iomanip>
//#include <string>
//#include "MotorVehicle.h"
//using namespace std;
//namespace sdds
//{
//	void MotorVehicle::setNumberPlate(const char* platenum)
//	{
//		int len = strlen(platenum) > 8 ? 8 : strlen(platenum);
//		strncpy(m_plateNum, platenum, len);
//		m_plateNum[len] = '\0';
//	}
//	void MotorVehicle::setAddress(const char* address)
//	{
//		int len = strlen(address) > 63 ? 63 : strlen(address);
//		strncpy(m_address, address, len);
//		m_address[len] = '\0';
//	}
//	MotorVehicle::MotorVehicle(const char* plateNum, int year, const char* address)
//	{
//		strncpy(m_plateNum, plateNum, 8);
//		m_plateNum[8] = '\0';
//		setAddress(address);
//		m_year = year;
//
//	}
//	void MotorVehicle::moveTo(const char* address)
//	{
//		if (strcmp(m_address, address) != 0)
//		{
//			cout << "|" << setw(8) << right << m_plateNum << "| |";
//			cout << setw(20) << right << m_address << " ---> ";
//			setAddress(address);
//			cout << setw(20) << left << address << "|" << endl;
//			//cout << *this;
//		}
//	}
//	std::ostream& MotorVehicle::write(std::ostream& os) const
//	{
//		os << "| " << m_year << " | " << m_plateNum << " | " << m_address;
//		return os;
//	}
//	std::istream& MotorVehicle::read(std::istream& is)
//	{
//		int year;
//		string platenum, address;
//		cout << "Built year: ";
//		is >> year;
//		cout << "License plate: ";
//		is.ignore();
//		getline(is, platenum);
//		//address 64 chars
//		cout << "Current location: ";
//		getline(is, address);
//		m_year = year;
//		setNumberPlate(platenum.c_str());
//		setAddress(address.c_str());
//		return is;
//	}
//	std::istream& operator>>(std::istream& left, MotorVehicle& obj)
//	{
//		return obj.read(left);
//	}
//	std::ostream& operator<<(std::ostream& left, const MotorVehicle& obj)
//	{
//		return obj.write(left);
//	}
//}


//
//#ifndef SDDS_TRUCK_H
//#define SDDS_TRUCK_H
//#include "MotorVehicle.h"
//#include <iostream>
//
//namespace sdds
//{
//	class Truck : public MotorVehicle
//	{
//		double m_capacity;
//		double m_volume;
//	public:
//		Truck(const char* plateNum, int year,
//			double capacity, const char* currentAddress);
//		bool addCargo(double cargo);
//		bool unloadCargo();
//		std::ostream& write(std::ostream& os /*= std::cout*/) const;
//		std::istream& read(std::istream& is /*= std::cin*/);
//	};
//	std::istream& operator>>(std::istream& left, Truck& obj);
//	std::ostream& operator<<(std::ostream& left, const Truck& obj);
//}
//#endif
//

//
//#include <iostream>
//using namespace std;
//#include "Truck.h"
//
//namespace sdds
//{
//	// Set the current cargo to 0 and move the truck to the address specified in the last parameter.
//	Truck::Truck(const char* plateNum, int year, double capacity, const char* currentAddress) : MotorVehicle(plateNum, year, currentAddress)
//	{
//		m_volume = 0.000000000;
//		m_capacity = capacity;
//	}
//	bool Truck::addCargo(double cargo)
//	{
//		bool ret = true;
//		if (m_volume == m_capacity)
//			ret = false;
//		else if ((m_volume + cargo) >= m_capacity)
//			m_volume = m_capacity;
//		else
//			m_volume += cargo;
//		return ret;
//	}
//	bool Truck::unloadCargo()
//	{
//		bool ret = true;
//		if (m_volume != 0)
//			m_volume = 0;
//		else
//			ret = false;
//		return ret;
//	}
//	std::ostream& Truck::write(std::ostream& os) const
//	{
//		MotorVehicle::write(os);
//		os << " | " << m_volume << "/" << m_capacity;
//		return os;
//	}
//	std::istream& Truck::read(std::istream& is)
//	{
//		MotorVehicle::read(is);
//		double capacity, volume;
//		cout << "Capacity: ";
//		is >> capacity;
//		cout << "Cargo: ";
//		is >> volume;
//		m_volume = volume;
//		m_capacity = capacity;
//		return is;
//	}
//	istream& operator>>(istream& left, Truck& obj)
//	{
//		return obj.read(left);
//	}
//	ostream& operator<<(ostream& left, const Truck& obj)
//	{
//		return obj.write(left);
//	}
//}