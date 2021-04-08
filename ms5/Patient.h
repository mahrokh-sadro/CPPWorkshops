//#ifndef SDDS_PATIENT_H
//#define SDDS_PATIENT_H
//#include "IOAble.h"
//#include "Ticket.h"
//#include <iostream>
//namespace sdds {
//    class Patient: public IOAble{
//            char* m_patientName = nullptr;
//            int m_ohipNum;
//            Ticket A;
//            bool m_fileIO;
//        public:
//            Patient(int number = 0, bool flag = false);
//            ~Patient();
//            Patient(const Patient&) = delete;
//            void operator=(const Patient&) = delete;
//            void getSpecs(std::istream&);
//            virtual char type() const = 0;
//            bool fileIO() const;
//            void fileIO(bool);
//            bool operator ==(char) const;
//            bool operator ==(const Patient&) const;
//            void setArrivalTime();
//            operator Time() const;
//            int number() const;
//            std::istream& read(std::istream& istr);
//            std::ostream& write(std::ostream& ostr) const;
//            std::istream& csvRead(std::istream& istr);
//            std::ostream& csvWrite(std::ostream& ostr) const;
//    };
//}
//#endif


/* Citation and Sources...
Final Project Milestone 4
Module: Patient
Filename: Patient.h
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/28  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/
#ifndef SDDS_PATIENT_H_
#define SDDS_PATIENT_H_

#include <iostream>
#include "IOAble.h"
#include "Ticket.h"

namespace sdds {
	class Patient :public IOAble {
		char* m_patientName;
		int m_ohipNum;
		Ticket A;
		bool m_fileIO;
	public:

		Patient(int ticketNumber = 0, bool fileIO = false);
		Patient(const Patient&) = delete;
		Patient& operator=(const Patient&) = delete;
		virtual ~Patient();
		virtual char type()const = 0;
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