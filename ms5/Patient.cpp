


/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/28  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

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

	//Patient::Patient(int ticketNumber, bool fileIO)///

	//	:A(ticketNumber) /*m_pname{ nullptr }, ohip_no{0}, m_fileIO{ fileIO }*/ {//fixxxx
	//	m_fileIO = fileIO;
	//}
	Patient::Patient(int ticketNumber, bool fileIO)///

		: m_patientName{ nullptr }, m_ohipNum{}, A(ticketNumber), m_fileIO{ fileIO } {}

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
		m_fileIO = fileIO;
	}

	bool Patient::operator==(char ch) const
	{
		return type() == ch;
	}

	bool Patient::operator==(const Patient& obj) const
	{
		return type() == obj.type();
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
		/*string str="";
		is.ignore();

		getline(is, str,',');
		m_pname = new char[str.length() + 1];
		strcpy(m_pname, str.c_str());
		delete[] m_pname;

		is >> ohip_no;
		is.ignore();
        return obj.csvRead(is);*/
		std::string name = "";
		is.ignore();
		getline(is, name, ',');
		int len = name.length();
		delete[] m_patientName;
		m_patientName = new char[len + 1];
		strcpy(m_patientName, name.c_str());
		//m_pname[len] = '\0';

		is >> m_ohipNum;
		is.ignore();
		return A.csvRead(is);



	}

	std::ostream& Patient::write(std::ostream& os) const
	{
		os << A << endl;
		char name[26];
		strncpy(name, m_patientName, 25);
		name[25] = 0;
		return os << name << ", OHIP: " << m_ohipNum;

	}

	std::istream& Patient::read(std::istream& is)
	{
		cout << "Name: ";
		delete[] m_patientName;
		m_patientName = getcstr();
		cout << "OHIP: ";
		m_ohipNum = getInt(100000000, 999999999, "", "Invalid OHIP Number,", true);
		return is;
	}

}
