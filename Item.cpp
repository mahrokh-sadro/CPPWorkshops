#include <iostream>
#include <iomanip>

#include "cstring.h"
using namespace std;
#include "Item.h"
namespace sdds {


	void Item::setName(const char* name)
	{
		//This function sets the itemName member Cstring variable to a the Cstring in the name argument up to 20 characters.
		strnCpy(m_itemName, name, 20);//20 0r 21?????????????????????????
		m_itemName[20]=0;//???????????????????????????????????????????????????????????
	}


	//empty state
	void Item::setEmpty()    //safe Empty State
	{
		//setting the price to an impossible value like 0.0
		m_price = 0.0; // 0.0000000000000000000000000000000000000000000001
		//setting the m_itemName to a blank string(first character set to null).
		m_itemName[0] = 0;
		m_taxed = false;
	}

	void Item::set(const char* name, double price, bool taxed)	{

		//If price is less than 0 or name is null, then the Item is set to a recognizable invalid
			//empty state(safe empty state).
		if (!name || price < 0) {
			setEmpty();
		}
		else {
			//Sets the m_itemName attribute to the Cstring pointed by the name argument using the setName methodand 
			setName(name);
			//sets the m_priceand m_taxed attributes to the corresponding arguments.
			m_price = price;
			m_taxed = taxed;
		}
		
	}

	double Item::price() const
	{
		//Returns the m_price attribute;
		return m_price;
	}


	double Item::tax() const
	{
		double value = 0.0;
		//Returns the product of m_price and 0.13(define a constant double value for this tax rate).
		if (m_taxed) value =  0.13 * m_price;
		else         value = 0.0;
			//Or it returns 0.0 if the m_taxed is false.
		return value;
	}

	

	bool Item::isValid() const
	{
		//Returns true if the Item is not set to the empty state(As done in setEmpty function) .
		return m_itemName[0] != 0;                     //the Item??????????????yyy eerroorra with ()?????
		//	This function can not modify its owner.
		//return false;
	}




	void Item::display() const
	{
		//If the Item is valid :
		if (isValid()) {

		
		//	"| "   m_itemName; left - justified in 20 spaces, padded with '.' (dots)   " | "
        //	m_price; right - justified in 7 spaces with two digits after the decimal point  " | "
		//if m_taxed is true prints "Yes" otherwise prints "No "     " |"   Newline		

			cout << "| " << setw(20) << setfill('.') << left << m_itemName << " | " <<
			right << setw(7) << setfill(' ') << fixed << setprecision(2) << m_price << " | ";
				
			if (m_taxed)   cout << "Yes" << " |" << endl;
			else           cout << "No " << " |" << endl;
								
		}
					//If the Item is invalid
		  //  | xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx | Newline
		//else if(!m_itemName)  cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
		else cout << "| xxxxxxxxxxxxxxxxxxxx | xxxxxxx | xxx |" << endl;
	}




}
