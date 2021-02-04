





#include <iostream>
#include <iomanip>

#include "cstring.h"
#include "Bill.h"
#include "Item.h"
using namespace std;

namespace sdds {



	void Bill::setEmpty()
	{
		//Sets the Bill object to an empty state by 
		//setting m_title to an Empty Cstring      //setting a string to a blank string(first character set to null).
		m_title[0] = 0;
		
		//and m_items to nullptr
		m_items = nullptr;    //name of array
	}

	bool Bill::isValid() const
	{
		//	Returns true if m_title is not empty and m_items is not null and all the Items in the m_items array 
			//are valid.
		
		
		bool ok = true;

		int i;
		if (m_title[0] == 0 || m_items == nullptr) ok = false;
		for (i = 0; ok && i < m_noOfItems; i++) {
			if (!m_items[i].isValid()) ok = false;
			//if (!m_title || !m_items || !m_items[i].isValid())   return false;	//ok = false;//????????????????
			//else ok = true;//??????????????????????????????
		}
		
		//all the Items in the m_items array are valid.
			

			//	hint: First checkand make sure m_title and m_items are valid.Then loop through all the Items in the 
			//	m_items arrayand make sure they are all valid.
		return ok;
		
	}

	double Bill::totalTax() const
	{

		//Adds all the taxes of the items using a loop and returns the sum.
		//int m_noOfItems;    size of the dynamically allocated array of Items
		int i;
		double totalTax = 0.0;
		for (i = 0; i < m_noOfItems; i++) {  //its conts how can we addd a dynamic number??????????????????????????????
			
			totalTax += m_items[i].tax();  //using properties with . notation
		}        

		return totalTax;
	}



	double Bill::totalPrice() const
	{   
		int i;
		double totalPrice = 0.0;
		for (i = 0; i < m_noOfItems; i++) {
			totalPrice += m_items[i].price();
		}

		return totalPrice;
	}


	void Bill::Title() const
	{  

		cout << "+--------------------------------------+" << endl;

	//	If the Bill is valid
	// "| "    m_title; left - justified in 36 spaces   " |"   Newline
		if (isValid()) 	 cout << "| " << setw(36) << setfill(' ') << left << m_title << " |" << endl;
		else	         cout << "| Invalid Bill                         |" << endl;
			
	// in both cases
		cout << "+----------------------+---------+-----+" << endl;
		cout << "| Item Name            | Price   + Tax |" << endl;
		cout << "+----------------------+---------+-----+" << endl;

	}


	void Bill::footer() const
	{
		//Prints the footer in the following format :

		cout << "+----------------------+---------+-----+" << endl;

		//If the Bill is valid
		if (isValid()) {
			//"|                Total Tax: "
			//totalTax(); right justified in 10 spaces with two digits after the decimal point   " |"   Newline
			cout << "|                Total Tax: " << //new l?????????????????????????????????
				setw(10) << setfill(' ') << right << fixed << setprecision(2) << totalTax() << " |" << endl;

			//"|              Total Price: "
			//totalPrice(); right justified in 10 spaces with two digits after the decimal point    " |"   Newline
			cout << "|              Total Price: " <<
				setw(10) << setfill(' ') << right << fixed << setprecision(2) << totalPrice() << " |" << endl;


			//"|          Total After Tax: "
			//totalTax() + totalPrice(); right justified in 10 spaces with two digits after the decimal point  " |"   Newline
			cout << "|          Total After Tax: " <<
				setw(10) << setfill(' ') << right << fixed << setprecision(2) << totalTax() + totalPrice() << " |" << endl;

		}

		//If the Bill is invalid
		else  cout << "| Invalid Bill                         |" << endl;

		//Then in both cases
		cout << "+--------------------------------------+" <<endl;
	
	}
	void Bill::init(const char* title, int noOfItems)
	{

		//If any of the arguments are invalid, it will set the Bill to an empty state(ie.title is null or noOfItems 
		//	is zero or less)
		if(!title || noOfItems<=0) setEmpty();
		//Otherwise, if the incoming arguments are valid :
		else {
			//	this f set the m_noOfItems member variable to the incoming corresponding
			//argument and sets m_itemsAdded to zero.
			m_noOfItems = noOfItems;
			m_itemsAdded = 0;

			//	Next, it will copy the Cstring pointed by the title argument into m_title attribute up to
			//36 characters
			strnCpy(m_title, title,36);
			//	Then it will dynamically allocate an array of Items pointed by m_items member variable.The length 
			//of this array will be m_noOfItems.
			m_items = new Item[m_noOfItems];  //dma an array of the type Item

			//	Make sure all the dynamically allocated Items are set to empty
			int i;
			for (i = 0; i < m_noOfItems; i++) {
				 m_items[i].setEmpty();  // m_items[i]=m_items[i].setEmpty();???????????????????????????????????
			}

		}
	}



// 	bool Bill::add(const char* item_name, double price, bool taxed)
// 	{
// 		bool flag = false;
// 		//If the number of added Items(m_itemsAdded) is less than the length of the m_items array,
// 		if ((m_itemsAdded < m_noOfItems)) {
// 			//  this function  will set the next available subject to the incoming argument values.Then it will add
// 			//	one to the  m_itemsAdded and return true;

// 				//finding the next availale subject in m_items array
// 			int i;
// 			int index = 0; //fist empty index in m_items array
// 			for (i = 0; i < m_noOfItems; i++) {
// 				if (!m_items[i].isValid()) {  //if m_items[i] is empty
// 					index = i;             //save the index number
// 					i = m_noOfItems;       //end the loop
// 				}
// 			}
// 			//char m_itemName[21];   
// 			//double m_price;
// 			//bool m_taxed;       we cant change these directly, we need to acces them using functions
// 			m_items[index].set(item_name, price, taxed);  //set doesnt cover nullptr
		    
// 			//add one to the  m_itemsAdded 
// 			m_itemsAdded += 1;
// 			flag = true;

// 		}
// 		//if(!item_name)  flag = false;
// 		//Otherwise, this function will do nothing, returning false;
// 		else  flag = false;
// 		return flag;
	
// 		//return false;
// 	}
	
	bool Bill::add(const char* item_name, double price, bool taxed) {
		bool ok = false;
		//If the number of added Items(m_itemsAdded) is less than the length of the m_items array,
		if (m_itemsAdded < m_noOfItems) {
			int i;   /// wholy mother, fix this  // Fardad was here
			for (i = 0; i < m_noOfItems; i++) {		
					m_items[m_itemsAdded].set(item_name, price, taxed);				
			}
			m_itemsAdded += 1;
			ok = true;
		}
		else ok = false;
		
		return ok;

	}


	void Bill::display() const    //This function can not modify the Bill.
	{
		//This function will first print the title()
		Title();

		//loop through the m_items elements, printing every one of them
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}

		//prints the footer().
		footer();   //	Bill::footer();???????????????//

	}


	void Bill::deallocate()
	{
		delete[] m_items;
		m_items = nullptr;

	}

}
