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
using namespace std;
#include "Food.h"
#include "cstring.h"
namespace sdds {

	void Item::setName(const char* name) {
		strnCpy(m_itemName, name, 30);
		m_itemName[30] = 0;          //why????????  30th element???
		
	}

	void Item::setEmpty() {

		m_itemName[0] = 0;
		m_calories = 0.00000000000000000000001;   
		m_when = 0;

	}

	void Item::set(const char* item_name, double calories, int when)
	{

		if (calories < 0 || item_name == nullptr)	{    
			setEmpty();
		}
		else		{
			setName(item_name);
			m_calories = calories;
			m_when = when;
		}
	}

	double Item::calories() const {

		return m_calories;
	}

	/*char* Item::when() 
	{
		return m_when;
	}*/

	bool Item::isValid() const {//the function that handles nullptr, valid code of meals//valid calories

		return m_itemName[0] != 0 && m_when > 0 && m_when < 5 && m_calories>0 && m_calories <=3000;
		
	}

	void Item::display() const {

		if (isValid()) {

			cout << "| " << setw(30) << setfill('.') << left << m_itemName << " | " <<
				setw(4) << setfill(' ') << right << m_calories << " | " <<
				setw(10) << setfill(' ') << left;


			switch (m_when) {

			case 1:
				cout << "Breakfast";
				break;
			case 2:
				cout << "Lunch";
				break;
			case 3:
				cout << "Dinner";
				break;
			case 4:
				cout << "Snack";
				break;

			}

			cout << " |" << endl;


		}
		else {
			cout << "| xxxxxxxxxxxxxxxxxxxxxxxxxxxxxx | xxxx | xxxxxxxxxx |" << endl;
		}
	}


}