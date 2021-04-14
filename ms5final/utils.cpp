
/* Citation and Sources...
Final Project Milestone 5
Module: utils
Filename: utils.h
Version 1.0
Author	Mahrokh Sadrolodabaee
Id 159436195
msadrolodabaee@myseneca.ca
Revision History
-----------------------------------------------------------
Date      Reason
2021/4/10  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/

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
    bool debug = false;
    int getTime() {
        int mins = -1;
        if (debug) {
            Time t(0);
            cout << "Enter current time: ";
            do {
                cin.clear();
                cin >> t;
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

    int getInt(const char* prompt) {

        if (prompt)     cout << prompt;
        int val = 0;
        bool done = false;
        do
        {
            done = false;
            cin >> val;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                done = true;
            }
            else
            {
                if (getchar() != '\n')
                {
                    cout << "Enter only an integer, try again: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    done = true;
                }
            }
        } while (done);

        return val;
    }

    int getInt(int min, int max, const char* prompt, const char* errorMessage, bool showRangeAtError) {

        cout << prompt;
        int val = 0;
        bool done = false;

        do
        {
            done = false;
            cin >> val;
            if (cin.fail())
            {
                cout << "Bad integer value, try again: ";
                cin.clear();
                cin.ignore(1000, '\n');
                done = true;
            }
            else
            {

                if (getchar() != '\n') {
                    cout << "Enter only an integer, try again: ";
                    cin.ignore(1000, '\n');
                    done = true;
                }
                else if (val > max || val < min)
                {
                    if (!showRangeAtError)
                    {
                        cout << errorMessage;
                        done = true;
                    }
                    else {
                        cout << errorMessage << " [" << min << " <= value <= " << max << "]: ";
                        done = true;
                    }
                }
            }
        } while (done);
        return val;
    }
   
    char* getcstr(
        const char* prompt,  
        std::istream& istr, 
        char delimiter    
    )
    {
        if (prompt)   cout << prompt;
        string str;
        getline(istr, str,delimiter);
        char* cstr = new char[str.length() + 1];
        strcpy(cstr, str.c_str());       
        return cstr;
    }
}
