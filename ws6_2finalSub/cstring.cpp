//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.20.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#include "cstring.h"
namespace sdds {
   
	void strCpy(char* des, const char* src) {
		int i;
		for (i = 0; src[i] != '\0'; i++) {   
			des[i] = src[i];
		}
		des[i] = 0;  
	}


	int strLen(const char* s) {
		unsigned count = 0;
		for (unsigned i = 0; s[i]; i++) ++count;
		return count;
	}
	int strCmp(const char* s1, const char* s2) {

		for (int i = 0; s2[i]; i++) {
			return s1[i] == s2[i] ? 0 : s1[i] - s2[i];
		}

		return 0;
	}
	void strCat(char* des, const char* src) {
		int i = 0;
		int j = 0;
		int len = strLen(des);
		for (i = len, j = 0; src[j]; i++, j++) des[i] = src[j];

		des[i] = 0;

	}
}