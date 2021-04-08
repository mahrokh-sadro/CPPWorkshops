

/* Citation and Sources...
Final Project Milestone 2
Module: Menu
Filename: Menu.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2020/3/23  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstring>
#include "Menu.h"
#include "utils.h"

using namespace std;
namespace sdds {

	Menu::Menu(const char* MenuContent, int NoOfSelections) :m_noOfSel{ NoOfSelections }
	{
		delete[] m_text;
		m_text = new char[strlen(MenuContent) + 1];
		strcpy(m_text, MenuContent);

	}

	void Menu::display() const
	{
		cout << m_text << endl;
		cout << "0- Exit" << endl;
	}

	Menu::~Menu()
	{
		delete[] m_text;
		m_text = nullptr;
	}

	int& Menu::operator>>(int& Selection)
	{
		display();
		Selection = getInt(0, m_noOfSel, "> ", "Invalid option", true);
		return Selection;
	}

	Menu::Menu(const Menu& obj) :m_noOfSel{ obj.m_noOfSel }
	{
		if (obj.m_text)
		{
			m_text = new char[strlen(obj.m_text) + 1];
			strcpy(m_text, obj.m_text);
		}

	}

}