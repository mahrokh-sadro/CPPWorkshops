

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>

#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds {

	

	/*Dynamically allocates memory to hold the content pointed
		by m_text.Also keeps the number of Selections in m_noOfSel.*/


	Menu::Menu(const char* MenuContent, int NoOfSelections) :m_noOfSel{ NoOfSelections }	
	{
		delete[] m_text;
		m_text = new char[strlen(MenuContent)+1];
		strcpy(m_text, MenuContent);

	}

	void Menu::display() const
	{
		cout << m_text<<endl;
		cout << "0- Exit" << endl;


	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;

	}

	/*The member insertion operator first calls the display 
		functionand then receives the user's selection as an 
		integer value using the getInt() function in utils
		module. The integer reference selection argument is
		then set to this value and returned.
		Make sure that the entered value is validated as an
		integer and also the value should be between 0 and m_noOfSel.
		If the above conditions are not met, a proper error
		message should be displayedand re - entry requested(see below)

		Assuming that the menu content is set to : "Tester Options
		menu:\n1- Option one\n2- Option two\n3- Option three" and
		the number of selections is set to 3 the operator>> should run like this :

Invalid option[0 <= value <= 3]: 4*/


	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ","Invalid option",true);//scope reso
		//input = Selection;
		//int* input = &Selection;
		return Selection;
	}

	Menu::Menu(const Menu& obj):m_noOfSel{obj.m_noOfSel }
	{
		//*this = obj;
		m_text = new char[strlen(obj.m_text) + 1];
		strcpy(m_text, obj.m_text);
	
	
	}







}