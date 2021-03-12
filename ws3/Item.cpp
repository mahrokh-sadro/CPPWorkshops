//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.04.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

using namespace std;

#include "Item.h"
#include "cstring.h"
namespace sdds {

	/*This function sets the**itemName**member Cstring variable to a the
	   Cstring in the**name**argument up to 20 characters.*/
	  void Item::setName(const char* name) {
       
        strnCpy(m_itemName, name,20);
        m_itemName[20] = 0;//why????????????????????????even strncpy needs this to work????unless it throws an error
		
      }

	
	void Item::setEmpty()   {    //safe Empty State	
		//setting the price to an impossible value like 0.0
		m_price = 0.0000000000000000000000000000000000000000000001;
		m_itemName[0] = 0;
		m_taxed = false; //not in instructions
	}

	void Item::set(const char* name, double price, bool taxed)	{

		
		if (!name || price < 0) {
			setEmpty();
		}
		else {
			setName(name);			
			m_price = price;
			m_taxed = taxed;
		}
		
	}

	double Item::price() const{
		return m_price;
	}


	double Item::tax() const{
		double value = 0.000000000000000000000000001;
		if (m_taxed) value =  0.13 * m_price;
		else         value = 0.0;
		return value;
	}

	
	bool Item::isValid() const	{
		
		return m_itemName[0] != 0;                     //the Item??????????????yyy eerroorra with ()?????
	}


	void Item::display() const	{
		//If the Item is valid :
		if (isValid()) {

			cout << "| " << setw(20) << setfill('.') << left << m_itemName << " | " <<
			right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price << " | ";
				
			if (m_taxed)   cout << "Yes" << " |" << endl;
			else           cout << "No " << " |" << endl;
								
		}
		//If the Item is invalid
		else cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
	}
}