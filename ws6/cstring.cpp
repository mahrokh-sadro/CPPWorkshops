//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.11.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
#include "cstring.h"
namespace sdds {
	void strCpy(char* des, const char* src) {
		unsigned i(0);
		for (i = 0; src[i]; i++) {
			des[i] = src[i];
		}
		des[i] = 0;
	}


	int strLen(const char* s) {
		unsigned count = 0;
		for (int i = 0; s[i]; i++) {
			++count;
		}
		return count;
	}

	void strCat(char* des, const char* src) {
		int i = 0;
		int j = 0;
		int len = strLen(des);
		for (i = len, j = 0; src[j]; i++, j++) des[i] = src[j];

		des[i] = 0;

	}

}