//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.19.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#include <iostream>  //for count and cin
#include <cstdlib>
#include "File.h"
#include "ShoppingList.h"
#include "Utils.h" 

// set to false when compling on Linux
const bool APP_OS_WINDOWS = false;

using namespace std;
using namespace sdds;



int listMenu() {     //use it in main
    cout << "-->>> My Shopping List <<<--" << endl;
    displayList();
    cout << "----------------------------" << endl
        << "1- Toggle bought Item" << endl
        << "2- Add Shopping Item" << endl
        << "3- Remove Shopping Item" << endl
        << "4- Remove bought Items" << endl
        << "5- Clear List" << endl
        << "0- Exit" << endl << "> ";
    return readInt(0, 5);
}


int main() {

	////main
	////	listMenu
        bool done = false;
        loadList();
        while (!done) {
            system(APP_OS_WINDOWS ? "cls" : "clear");
            switch (listMenu()) {
            case 1:
                toggleBought();
                break;
            case 2:
                addItemToList();
                break;
            case 3:
                removeItemfromList();
                break;
            case 4:
                removeBoughtItems();
                break;
            case 5:
                clearList();
                break;
            default:
                done = true;
            }
        }
        saveList();
        return 0;
}
   
