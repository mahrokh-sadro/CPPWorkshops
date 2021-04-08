//#define _CRT_SECURE_NO_WARNINGS
//#include <iostream>
//#include <cstdlib>
//#include <ctime>
//#include <string>
//#include <cstring>
//#include "utils.h"
//#include "Time.h"
//using namespace std;
//namespace sdds {
//   bool debug = false;  // made global in utils.h
//   int getTime() {  
//      int mins = -1;
//      if (debug) {
//         Time t(0);
//         cout << "Enter current time: ";
//         do {
//            cin.clear();
//            cin >> t;   // needs extraction operator overloaded for Time
//            if (!cin) {
//               cout << "Invlid time, try agian (HH:MM): ";
//               cin.clear();
//            }
//            else {
//               mins = int(t);
//            }
//            cin.ignore(1000, '\n');
//         } while (mins < 0);
//      }
//      else {
//         time_t t = time(NULL);
//         tm lt = *localtime(&t);
//         mins = lt.tm_hour * 60 + lt.tm_min;
//      }
//      return mins;
//   }
//
//   int getInt(const char* prompt)
//   {
//      // 0 for invalid integer, 1 for valid integer and other character, 2 for valid
//      int check = 0; 
//      bool num_found = false;
//      int num;
//      if(prompt != nullptr)
//         cout << prompt;
//      string line;
//      getline(cin, line);
//      line = line + '\n';
//      bool neg = false;
//
//      while(check == 0 || check == 1)
//      {
//         num = 0;
//         int i = 0;
//         neg = false;
//         num_found = false;
//         while(line[i])
//         {
//            if(line[i] == '-')
//               neg = true;
//            else if(line[i] < '0' || line[i] > '9')
//            {
//               if(num_found == false)
//               {
//                  cout << "Oye Hoye: " << line[i] << endl;
//                  check = 0;
//               }
//               else if(line[i] == '\n')
//                  check = 2;
//               else
//                  check = 1;
//               break;
//            }
//            else
//            {
//               num_found = true;
//               num = num * 10 + line[i] - '0';
//            }
//            i++;
//         }
//         if(neg)
//            num = 1 * num;
//         if(check != 2)
//         {
//            if(check == 0)
//               cout << "Bad integer value, try again: ";
//            else
//               cout << "Enter only an integer, try again: ";
//            getline(cin, line);
//            line = line + '\n';
//         }
//      }
//      return num;
//   }
//
//   int getInt(
//   int min,   // minimum acceptable value
//   int max,   // maximum acceptable value
//   const char* prompt ,  // User entry prompt
//   const char* errorMessage , // Invalid value error message
//   bool showRangeAtError     // display the range if invalid value entered 
//   )
//   {
//      // 0 for invalid integer, 1 for valid integer and other character, 2 for valid
//      int check = 0; 
//      bool num_found = false;
//      int num;
//      if(prompt != nullptr)
//         cout << prompt;
//      string line;
//      getline(cin, line);
//      line = line + '\n';
//      bool neg = false;
//
//      while(check == 0 || check == 1)
//      {
//         neg = false;
//         num = 0;
//         int i = 0;
//         num_found = false;
//         while(line[i])
//         {
//            if(line[i] == '-')
//               neg = true;
//            else if(line[i] < '0' || line[i] > '9')
//            {
//               if(num_found == false)
//                  check = 0;
//               else if(line[i] == '\n')
//                  check = 2;
//               else
//                  check = 1;
//               break;
//            }
//            else
//            {
//               num_found = true;
//               num = num * 10 + line[i] - '0';
//            }
//            i++;
//         }
//         if(neg)
//            num = -1 * num;
//         if(check != 2)
//         {
//            if(check == 0)
//               cout << "Bad integer value, try again: ";
//            else
//               cout << "Enter only an integer, try again: ";
//            getline(cin, line);
//            line = line + '\n';
//         }
//         else if(num < min || num > max)
//         {
//            check = 1;
//            if(errorMessage != nullptr)
//               cout << errorMessage;
//            if(showRangeAtError)
//            {
//               cout << "[" << min << " <= value <= " << max << "]: ";
//            }
//            getline(cin, line);
//            line = line + '\n';
//         }
//      }
//      return num;
//   }
//
//   char* getcstr(
//   const char* prompt ,   // User entry prompt
//   std::istream& istr ,  // the Stream to read from
//   char delimiter     // Delimiter to mark the end of data
//   )
//   {
//      if(prompt != nullptr)
//         cout << prompt;
//      string input;
//      getline(istr, input);
//      int len = input.length();
//      char *str = new char[len + 1];
//      strcpy(str, input.c_str());
//      str[len] = '\0';
//      return str;
//   }
//   /*char* getcstr(
//       const char* prompt,
//       std::istream& istr,
//       char delimiter
//   ) {
//       char* buf;
//       char ch;
//       int index;
//       int size;
//       if (prompt)  cout << prompt;
//       buf = new char[1];
//       ch = 0;
//       index = 0;
//       size = 1;
//
//       for (;;) {
//           istr.get(ch);
//
//           if (ch == delimiter) {
//               break;
//           }
//
//           if (!(index + 1 < size)) {
//               int newSize;
//               char* temp;
//               newSize = size * 2;
//               temp = new char[newSize];
//               memcpy(temp, buf, size);
//               delete[] buf;
//               buf = temp;
//               size = newSize;
//           }
//           buf[index++] = ch;
//       }
//       buf[index] = 0;
//       istr.clear();
//       return buf;
//   }*/
//
//}

/* Citation and Sources...
Final Project Milestone 4
Module: utils
Filename: utils.cpp
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/28  Preliminary release
-----------------------------------------------------------
I got the idea for getcstr() from
https://stackoverflow.com/questions/18286815/input-string-without-using-c-string
-----------------------------------------------------------*/

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

    //char* getcstr(
    //    const char* prompt,
    //    std::istream& istr,
    //    char delimiter
    //) {
    //    char* buf;
    //    char ch;
    //    int index;
    //    int size;
    //    if (prompt)  cout << prompt;
    //    buf = new char[1];
    //    ch = 0;
    //    index = 0;
    //    size = 1;

    //    for (;;) {
    //        istr.get(ch);

    //        if (ch == delimiter) {
    //            break;
    //        }

    //        if (!(index + 1 < size)) {
    //            int newSize;
    //            char* temp;
    //            newSize = size * 2;
    //            temp = new char[newSize];
    //            memcpy(temp, buf, size);
    //            delete[] buf;
    //            buf = temp;
    //            size = newSize;
    //        }
    //        buf[index++] = ch;
    //    }
    //    buf[index] = 0;
    //    istr.clear();
    //    return buf;
    //}
    char* getcstr(
        const char* prompt,   // User entry prompt
        std::istream& istr,  // the Stream to read from
        char delimiter     // Delimiter to mark the end of data
    )
    {
        if (prompt)              cout << prompt;

        string input;
        getline(istr, input);
        int len = input.length();
        char* str = new char[len + 1];
        strcpy(str, input.c_str());
        str[len] = '\0';
        return str;
    }
}
