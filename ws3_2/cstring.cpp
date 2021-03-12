//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.07.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#include "cstring.h"
namespace sdds {
    // written by Fardad. 
    void strnCpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; src[i] && i < len; i++) {
            des[i] = src[i];
        }
        if (i != len) des[i] = 0;
    }
}