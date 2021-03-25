#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <cstring>

#include "Patient.h"
#include "Ticket.h"
#include "Time.h"
#include "utils.h"

using namespace std;
namespace sdds {
	
	Patient::Patient(int ticketNumber, bool fileIO)
		: m_patientName{nullptr}, m_ohipNum{}, A(ticketNumber), m_fileIO{ fileIO } {}

	Patient::~Patient()
	{

		delete[] m_patientName;
		m_patientName = nullptr;
	}

	
	bool Patient::fileIO() const
	{
		return m_fileIO;
	}

	void Patient::fileIO(bool fileIO)
	{
		m_fileIO =fileIO;
	}


	bool Patient::operator==(char ch) const
	{
		return type()==ch;
	}

	bool Patient::operator==(const Patient& obj) const
	{
		return type()==obj.type();
	}
		
	void Patient::setArrivalTime()
	{
		A.resetTime();
	}

	Patient::operator Time() const
	{
		return (Time)A;
	}

	int Patient::number() const
	{
		return A.number();
	}

	std::ostream& Patient::csvWrite(std::ostream& os) const
	{
		os << type() << "," << m_patientName << "," << m_ohipNum << ",";
		return A.csvWrite(os);
	}

	std::istream& Patient::csvRead(std::istream& is)
	{
		delete[] m_patientName;
		string str;
		getline(is, str,',');
		m_patientName = new char[str.length() + 1];
		strcpy(m_patientName, str.c_str());
		is >> m_ohipNum;
		is.ignore();
        return A.csvRead(is);


	}

	std::ostream& Patient::write(std::ostream& os) const
	{
		os << A << endl;		
		char name[26];
		strncpy(name, m_patientName,25);
		name[25] = 0;
		return os << name << ", OHIP: " << m_ohipNum;

	}

	std::istream& Patient::read(std::istream& is)
	{
		cout << "Name: ";
		delete[] m_patientName;
		string name;
		getline(is, name,'\n');		
		m_patientName = new char[name.length()+1];
		strcpy(m_patientName, name.c_str());
		cout << "OHIP:";
		m_ohipNum=  getInt(100000000, 999999999,"" ,"Invalid OHIP Number,", true);
		return is;
	}

	

}
