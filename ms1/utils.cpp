#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"


#include <cstdio>
using namespace std;
namespace sdds {
    bool debug = false;  // made global in utils.h
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;   // needs extraction operator overloaded for Time
                if (!cin) {
                    cout << "Invlid time, try agian (HH:MM): ";
                    cin.clear();
                }
                else {
                    mins = int(t);
                }
                cin.ignore(1000, '\n');
            } while (mins < 0);
        }
        else {
            time_t t = time(NULL);
            tm lt = *localtime(&t);
            mins = lt.tm_hour * 60 + lt.tm_min;
        }
        return mins;
    }



    void clear(void) {
        char junk;
        do {
            junk = getchar();
        } while (junk != '\n');
    }





    int getInt(const char* prompt)
    {
        int value, keeptrying = 1, rc;
        char after;
        if (prompt) cout << prompt;
        do {
           
         
           rc = scanf("%d%c", &value, &after);
            if (rc == 0) {
                cout << "Bad integer value, try again: ";
                clear();
            }
            else if (after != '\n') {
               cout<< "Enter only an integer, try again: ";
                clear();
            }
       
            else
                keeptrying = 0;
        } while (keeptrying == 1);

        return value;
    }



    int getInt(
        int min,   // minimum acceptable value
        int max,   // maximum acceptable value
        const char* prompt,  // User entry prompt
        const char* errorMessage, // Invalid value error message
        bool showRangeAtError     // display the range if invalud value entered 
    )
    {


        int value, keeptrying = 1, rc;
        char after;
        if (prompt) cout << prompt;
        do {
           

            rc = scanf("%d%c", &value, &after);
            if (rc == 0) {
                cout << "Bad integer value, try again: ";
                clear();
            }
            else if (after != '\n') {
                cout << "Enter only an integer, try again: ";
                clear();
            }


            else if (value < min || value > max) {

                if (errorMessage)    cout << errorMessage;

                if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";

            }




            else  keeptrying = 0;

        } while (keeptrying == 1);

        return value;
    }



   
}
    
    
    //works
    
//int getInt(
//    int min,   // minimum acceptable value
//    int max,   // maximum acceptable value
//    const char* prompt,  // User entry prompt
//    const char* errorMessage, // Invalid value error message
//    bool showRangeAtError     // display the range if invalud value entered 
//)
//{
//
//
//    int value, keeptrying = 1, rc;
//    char after;
//    if (prompt) cout << prompt;
//    do {
//
//
//        rc = scanf("%d%c", &value, &after);
//        if (rc == 0) {
//            cout << "Bad integer value, try again: ";
//            clear();
//        }
//        else if (after != '\n') {
//            cout << "Enter only an integer, try again: ";
//            clear();
//        }
//
//
//        else if (value < min || value > max) {
//
//            if (errorMessage)    cout << errorMessage;
//
//            if (showRangeAtError) cout << "[" << min << " <= value <= " << max << "]: ";
//
//        }
//
//
//
//
//        else  keeptrying = 0;
//
//    } while (keeptrying == 1);
//
//    return value;
//}


    
    
  



       

  




