#include "cstring.h"
namespace sdds {
    // written by Fardad. 
    void strnCpy(char* des, const char* src, int len) {
        int i;
        for (i = 0; src[i] &&  i < len; i++) {   
            des[i] = src[i];
        }
        if (i != len) des[i] = 0;
    }
}