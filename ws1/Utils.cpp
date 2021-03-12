//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.19.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#include <iostream> // for cout, cin
using namespace std;
#include "Utils.h"

namespace sdds {

	//flushkeys
	//	ValidYesResponse
	//	yes
	//	readCstr
	//	readInt

	void flushkeys() {             //use it after getting input from user
		while (cin.get() != '\n');
	}


	bool ValidYesResponse(char ch) { //used in yes function
		return ch == 'Y' || ch == 'y' || ch == 'N' || ch == 'n';
	}

	bool yes() {      //getting yes or no answer from users
		char ch = 0;
		do {
			cin >> ch;
			flushkeys();
		} while (!ValidYesResponse(ch) && cout << "Only (Y/y) or (N/n) is acceptable: ");
		return ch == 'y' || ch == 'Y';
	}


	void readCstr(char cstr[], int len) {
		char buf[1024] = {};
		int i;
		cin.getline(buf, 1024);
		for (i = 0; i < len && buf[i]; i++) {
			cstr[i] = buf[i];
		}
		cstr[i] = 0;
	}

	int readInt(int min, int max) { //getting the number of needed items from user
		int value = 0;
		bool done = false;
		while (!done) {
			cin >> value;
			if (!cin) {
				cin.clear();
				cout << "Bad integer, try agian: ";
			}
			else {
				if (value >= min && value <= max) {
					done = true;
				}
				else {
					cout << "Value out of range (" << min << "<=value<=" << max << "): ";
				}
			}
			flushkeys();
		}
		return value;
	}

}