//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.07.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <iomanip>

#include "CalorieList.h"
#include "cstring.h"
using namespace std;

namespace sdds {
	//Sets the Bill object to an empty state by 
	//setting m_title to an Empty Cstring      
	//setting a string to a blank string(first character set to null).

	void CalorieList::setEmpty() {
		m_title[0] = 0;
		m_items = nullptr;

	}

	bool CalorieList::isValid() const {

		bool ok = true;
		int i;                                            //in part 1 I have set the first element of the
		if (/*m_title[0] == 0 ||*/ m_items == nullptr) {  //regular array to 0 and the address of the dma
			                                              //array to nullptr and works properly, but here
			                                              //I get "Conditional jump or move depends on uninitialised value(s)"			                                               //on matrix????????????????????????
			ok = false;
		}
		for (i = 0; ok && i < m_noOfItems; i++) {

			if (!m_items[i].isValid()) ok = false;
		}
		return ok;

	}

	double CalorieList::totalCalories() const {
		int i;
		double totalCalories = 0.00000001;
		for (i = 0; i < m_noOfItems; i++) {
			totalCalories += m_items[i].calories();
		}

		return totalCalories;
	}

	void CalorieList::Title() const {
		cout << "+----------------------------------------------------+" << endl;
		if (isValid()) {
			cout << "|  Daily Calorie Consumption                         |" << endl;
		}
		else {
			cout << "| Invalid Calorie Consumption list                   |" << endl;
		}
		cout << "+--------------------------------+------+------------+" << endl;
		cout << "| Food name                      | Cals | When       |" << endl;
		cout << "+--------------------------------+------+------------+" << endl;

	}

	void CalorieList::footer() const {  
		cout << "+--------------------------------+------+------------+" << endl;
		if (isValid()) {

			cout << "|    Total Calories for today:" << setw(9) << setfill(' ') << right << totalCalories() << " |            |" << endl;

		}
		else {
			cout << "|    Invalid Calorie Consumption list                |" << endl;
		}
		cout << "+----------------------------------------------------+" << endl;
	}


	void CalorieList::init(int size) {

		m_noOfItems = size;
		m_itemsAdded = 0;
		m_items = new Item[m_noOfItems];
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].setEmpty();
		}

	}
	////////////////////////////
	bool CalorieList::add(const char* item_name, int calories, int when)
	{
		bool ok = true;
		if (m_itemsAdded < m_noOfItems)
		{
			m_items[m_itemsAdded].set(item_name, calories, when);
			m_itemsAdded++;

		}
		else ok = false;

		return ok;
	}

	void CalorieList::display() const {
		Title();
		int i;
		for (i = 0; i < m_noOfItems; i++) {
			m_items[i].display();
		}
		footer();
	}

	void CalorieList::deallocate() {
		delete[] m_items;
		m_items = nullptr;
	}

}