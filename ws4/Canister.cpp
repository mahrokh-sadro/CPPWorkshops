//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.11.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <istream>    
#include <iomanip>

#include "Canister.h"


#include <cstring>

//#define SDDS_DEBUG

using namespace std;
namespace sdds {

	const double PI(3.14159265);





	void Canister::setToDefault()	{
		m_contentName = nullptr;
		m_hieght=13.0;
		m_diameter=10.0;
		m_contentVolume=0.0;
		m_usable=true;

	}

	
	bool Canister::isEmpty() const	{

		return m_contentVolume < 0.00001;
		
	}

	bool Canister::hasSameContent(const Canister& C) const { 
		return ((*this).m_contentName && C.m_contentName && strcmp((*this).m_contentName, C.m_contentName)==0);
		
	}



	void Canister::setName(const char* Cstr)	{

		if (Cstr && m_usable == true) {

			delete[] m_contentName;
			
			m_contentName = new char[strlen(Cstr) + 1];
			strcpy(m_contentName, Cstr);
			m_contentName[strlen(Cstr)]=0;
		}
		

	}





	Canister::Canister()	{     
#ifdef  SDDS_DEBUG

		cout << "default constructor" << endl;
#endif

		setToDefault();
	}





	Canister::Canister(const char* contentName)	{ 
#ifdef  SDDS_DEBUG

		cout << "1 arg constructor" << endl;
#endif


		setToDefault();
		setName(contentName);

	}




	Canister::Canister(double hieght, double diameter, const char* contentName)	{//dont call this

#ifdef  SDDS_DEBUG

		cout << "3 arg constructor" << endl;
#endif



		setToDefault();
		if (hieght >= 10 && hieght <= 40 && diameter >= 10 && diameter <= 30) {

			m_hieght = hieght;  
			m_diameter = diameter;
			m_contentVolume = 0.00000000001;
			setName(contentName);   
		}                            
		else {
			m_usable = false;
		}

	}

	



	Canister::~Canister()	{
#ifdef  SDDS_DEBUG

		cout << "destructor" << endl;

#endif



		delete[] m_contentName;
		m_contentName = nullptr;
	}


	

	void Canister::clear() {
		delete[] m_contentName;
		m_contentName = nullptr;
		m_contentVolume = 0.0;            
		m_usable = true;
	}

	

	double Canister::capacity() const {

		double H(m_hieght);
		double D(m_diameter);
		double capacity = PI * (H - 0.267) * (D / 2) * (D / 2);
		return capacity;
	}




	double Canister::volume() const	{

		return m_contentVolume;
	}


	Canister& Canister::setContent(const char* contentName)	{

		if (!contentName) {
			m_usable = false;
		}
		else if (!m_contentVolume) {      
			
		 
			setName(contentName);

		}
		else if (strcmp(/*this->*/m_contentName, contentName) != 0) {
			m_usable = false;
		}
		return *this;
	}





	Canister& Canister::pour(double quantity)	{       
		if (m_usable == true && quantity > 0 && capacity() >= (quantity + volume())) {
			m_contentVolume += quantity;
		}
		else {
			m_usable = false;
		}
		return *this;
	}


	

	                                                        
	Canister& Canister::pour(Canister& C)	{              
		                                                   
		setContent(C.m_contentName);                       
		if (C.m_contentVolume > ((*this).capacity() - (*this).volume())) {
			                                                         
			C.m_contentVolume=C.m_contentVolume - ((*this).capacity() - (*this).volume());
			(*this).m_contentVolume = (*this).capacity();

		}
		else {
			pour(C.m_contentVolume);
			C.m_contentVolume = 0.000000000000001;
		}
		return *this;
	}

	

	std::ostream& Canister::display() const	{
		
		cout << setw(7) << setfill(' ') << fixed << setprecision(1) << capacity() << "cc (" << m_hieght << "x" << m_diameter << ") Canister";

		if (m_usable == false) {

			cout << " of Unusable content, discard!";  
		}
		else if(m_contentName) {
			cout << " of " << setw(7) << setfill(' ') << fixed << setprecision(1) << volume() << "cc   " << m_contentName;               //newline

		}
		return cout;
	}

	
}