#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <string>
#include <cstring>
#include "utils.h"
#include "Time.h"
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
    //int getInt(const char* prompt) {
    //    if (prompt) cout << prompt << endl;

    //    bool done = false;
    //    int num;
    //    while (!done) {
    //        cin >> num;
    //        if (cin.fail()) {
    //            cin.clear();
    //            cin.ignore(3000, '\n');
    //            cout << "Bad integer value, try again: ";
    //        }

    //        else  done = true;
    //    }
    //    while (getchar() != '\n')  cout << "Enter only an integer, try again: ";

    //    return num;

    //}



    //int getInt(const char* prompt) {
    //    if (prompt) cout << prompt << endl;

    //    bool done = false;
    //    int num;
    //    while (!done) {
    //        cin >> num;
    //        if (cin.fail()) {
    //            cin.clear();
    //            cin.ignore(3000, '\n');
    //            cout << "Bad integer value, try again: ";
    //        }

    //        else  done = true;
    //    }
    //    while (getchar() != '\n')  cout << "Enter only an integer, try again: ";

    //    return num;

    //}





    //void clear() { while (getchar() != '\n'); }

    //int getInt(const char* prompt) {

    //    if (prompt)  cout << prompt;
    //    int i = 0; char nl = 0;
    //    int check = 0;
    //    do {
    //        label:check = scanf("%d%c", &i, &nl);
    //        if (check == 0) {
    //            cout << "Bad integer value, try again: ";
    //            clear();
    //            continue;  //watt to do
    //            //goto label;
    //        }
    //        if (nl != '\n') {
    //            cout << "Enter only an integer, try again: ";
    //            clear();
    //        }
    //    } while (nl != '\n');
    //    return i;
    //}







    //int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError)    {

    //    int val = getInt();
    //    if (prompt)  cout << prompt;
    //    while (val<min || val>max) {
    //       // if (errorMessage)  cout << errorMessage;
    //       // if (showRangeAtError == true) cout << "[" << min << "<= value <=" << max << "]";
    //        printf("(%d<=value<=%d): ", min, max);
    //        val=getInt();

    //    }
    //    return val;
    //}

    //char* getcstr(const char* prompt, std::istream& istr, char delimiter)
    //{
    //    return nullptr;
    //}







}
    
    
    
    
    
    
    
  



       

  




