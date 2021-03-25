/* Citation and Sources...
Final Project Milestone 3
Module: Patient
Filename: Patient.h
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/25  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include <iostream>
#include "IOAble.h"
#include "Time.h"
#include "Ticket.h"

namespace sdds {
	class Patient :public IOAble {
		char* m_patientName;
		int m_ohipNum;
		Ticket A;
		bool m_fileIO;
	public:
		
		Patient(int ticketNumber=0, bool fileIO=false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		virtual ~Patient();
		virtual char type()const=0;
		bool fileIO() const;
		void fileIO(bool fileIO);
		bool operator==(char ch)const;
		bool operator==(const Patient&)const;
		void setArrivalTime();
		operator Time()const;
		int number() const;
		std::ostream& csvWrite(std::ostream& os = std::cout) const;
		std::istream& csvRead(std::istream& is = std::cin);
		std::ostream& write(std::ostream& os = std::cout) const;
		std::istream& read(std::istream& is = std::cin);

	};

}
#endif