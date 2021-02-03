#include "cstring.h"
namespace sdds {
  
    void strnCpy(char* des, const char* src, int len) {

        int i;
        int count = 0; //to count the number of characters of destination string
        for (i = 0; i < len; i++) {   //len-1 does not work
            des[i] = src[i];
            count++;
        }
        if (count < len)  des[count] = 0;   //null terminating the destination     (count < len) && des[count] = 0;?????

    }
}