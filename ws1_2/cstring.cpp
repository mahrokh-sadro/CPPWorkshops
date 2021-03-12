//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.24.2021
//I have done all the coding by myself, except for strStr() that I copied it from
//Leon Li and the codes provided by my professor to complete my workshopsand assignments.
////////////////////////////////////////////////


#include "cstring.h"

namespace sdds {


      // Copies the srouce character string into the destination
    void strCpy(char* des, const char* src) {
        int i;

        //char* des is a pointer variable of type char,des is an address
        //using for loop and iterate all members of arr
        //cant use des=src as these are addresses of strings not the string 

        for (i = 0; src[i] != '\0'; i++) {    //
            des[i] = src[i];
        }
        des[i] = 0;   //des[i] = '\0';
    }



    //void strnCpy(char* des, const char* src, int len);    
    void strnCpy(char* des, const char* src, int len) {

        int i;
        int count=0; //to count the number of characters of destination string
        for (i = 0; i < len ; i++) {   //len-1 does not work
            des[i] = src[i];
            count++;
        }
        if (count < len)  des[count] = 0;   //null terminating the destination     (count < len) && des[count] = 0;?????
                      
    }

   ///* you should use a for loop when you know how many times the loop should run.If you want the loop 
   //     to*/ break based on a condition other than the number of times it runs, you should use a while loop


    int strCmp(const char* s1, const char* s2) {
        int i;
        for (i = 0; s2[i] != '\0'; i++) {
            if(s1[i] != s2[i])     return s1[i] - s2[i];
            
        }
        return 0;  //I tried to use 1 return and it seems to work without this 1 on VS but matrix throws errors
    }

    int strnCmp(const char* s1, const char* s2, int len) {
        int i;
        int value = 0;
        for (i = 0;  i<len ; i++) {
            if (s1[i] != s2[i])   value = s1[i] - s2[i];
                
                ///why return herer doesnt work
               
        }
        return value;
    }

    

    // returns the lenght of the C-string in characters
    int strLen(const char* s) {
        //char*s is equivalent of char s[] when it comes to arguments
        int i;
        int count = 0;
        for (i = 0; s[i] != '\0'; i++) count++;
                 
        return count;
    }

    // returns the address of first occurance of "str2" in "str1"
   // returns nullptr if no match is found
    const char* strStr(const char* str1, const char* str2)
    {
        while (*str1 != '\0')
        {
            if (*str1 == *str2)
            {
                if (strnCmp(str1, str2, strLen(str2)) == 0)   return str1;

            }
            str1++;
        }
        return nullptr;
    }

    // Concantinates "src" C-string to the end of "des"
    void strCat(char* des, const char* src) {
        int i=0;
        int j = 0;
        int len = strLen(des);
        for (i = len, j = 0; src[j] != 0;i++,j++ ) des[i] = src[j];
            
        des[i] = 0;//null termination

    }

  

    //const char* strStr(const char* str1, const char* str2) {

    //    int len1 = strLen(str1);
    //    int len2 = strLen(str2);
    //   /* if (len1 == 0 || len2 == 0)
    //        return nullptr;*/

    //    int i;
    //    int j;
    //    for (i = 0, j = 0; str2[i] != '\0' && j < len1 - len2; i++, j++) {   //
    //        if (str1[j] == str2[i] && strnCmp(str1, str2, len2) == 0) {
    //           
    //            return str1;
    //        }
    //       return nullptr;

    //    }

    //}


    //int strCmp(const char* s1, const char* s2) {
    //        int i;
    //        int value;
    //    loop:for (i = 0; s2[i] != '\0'; i++) {

    //        if (s1[1] != s2[i]) {
    //            value =s1[1] != s2[i];

    //        }
    //        
    //        else {
    //            value = 0;
    //           // goto loop;
    //            continue;
    //        }
    //        return value;
    //    }
    //    // return value;
    //}


   


}

