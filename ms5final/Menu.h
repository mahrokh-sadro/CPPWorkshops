

/* Citation and Sources...
Final Project Milestone 5
Module: Menu
Filename: Menu.h
Version 1.0
Author	Mahrokh Sadrolodabaee
Id 159436195
msadrolodabaee@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/4/10  Preliminary release

-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------*/

#ifndef SDDS_MENU_H
#define SDDS_MENU_H
namespace sdds {

    class Menu {
        char* m_text = nullptr;
        int m_noOfSel = 0;
        void display()const;

    public:
        Menu(const char* MenuContent, int NoOfSelections);
        virtual ~Menu();
        int& operator>>(int& Selection);
        Menu(const Menu&);
        Menu& operator=(const Menu&) = delete;
    };

}
#endif