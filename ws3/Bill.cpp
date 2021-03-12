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


#include "Bill.h"
#include "Item.h"
#include "cstring.h"
using namespace std;

namespace sdds {

	//Sets the Bill object to an empty state by 
	//setting m_title to an Empty Cstring      setting a string to a blank string(first character set to null).

	void Bill::setEmpty()	{
		
		m_title[0] = 0;                             //for regular array:cuz m_title is const
		
		//and m_items to nullptr
		m_items = nullptr;                           //for dma array
	}

	bool Bill::isValid() const	{
		bool ok = true;
		int i;
		if (m_title[0] == 0 || m_items == nullptr) ok = false;
		for (i = 0; ok && i < m_noOfItems; i++) {
			if (!m_items[i].isValid()) ok = false;
		}
				
		return ok;
	}

	double Bill::totalTax() const	{

		int i;
		double totalTax = 0.0;
		for (i = 0; i < m_noOfItems; i++) {  

			totalTax += m_items[i].tax();  //using properties with . notation
		}        

		return totalTax;
	}



	double Bill::totalPrice() const	{   
		int i;
		double totalPrice = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].price();
		}

		return totalPrice;
	}


	void Bill::Title() const	{  

		cout << "+--------------------------------------+" << endl;	
		if (isValid()) 	 cout << "| " << setw(36) << setfill(' ') << left << m_title << " |" << endl;
		else	         cout << "| Invalid Bill                         |" << endl;
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;

	}


	void Bill::footer() const	{
		
		cout << "+----------------------+---------+-----+" << endl;

		//If the Bill is valid
		if (isValid()) {
		
			cout << "|                Total Tax: " << 
				setw(10) << setfill(' ') << right << fixed << setprecision(2) << totalTax() << " |" << endl;

			cout << "|              Total Price: " <<
				setw(10) << setfill(' ') << right << fixed << setprecision(2) << totalPrice() << " |" << endl;
			
			cout << "|          Total After Tax: " <<
				setw(10) << setfill(' ') << right << fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;

		}
		//If the Bill is invalid
		else  cout << "| Invalid Bill                         |" << endl;
		cout << "+--------------------------------------+" <<endl;
	
	}
	void Bill::init(const char* title, int noOfItems)	{

		
		if(!title || noOfItems<=0) setEmpty();
		
		else {
		
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;
			strnCpy(m_title, title,36);
			m_items = new Item[m_noOfItems];  //dma an array of the type Item

			int i;
			for (i = 0; i < m_noOfItems; i++) {
				 m_items[i].setEmpty();  // m_items[i]=m_items[i].setEmpty();???????????????????????????????????
			}

		}
	}


	
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool ok = true;
		//If the number of added Items(m_itemsAdded) is less than the length of the m_items array,
		if (m_itemsAdded < m_noOfItems) {
		   /// wholy mother, fix this  // Fardad was here
		    m_items[m_itemsAdded].set(item_name, price, taxed);				
			m_itemsAdded += 1;
			
		}
		else ok = false;
		
		return ok;

	}


	void Bill::display() const   {
		
		Title();
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();   

	}


	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;

	}

}
