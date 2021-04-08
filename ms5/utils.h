//#ifndef SDDS_UTILS_H_
//#define SDDS_UTILS_H_
//#include <iostream>
//namespace sdds {
//   extern bool debug; // making sdds::debug variable global to all the files
//                      // which include: "utils.h"
//
//   int getTime(); // returns the time of day in minutes
//   
//   int getInt(
//   const char* prompt = nullptr   // User entry prompt
//   );
//   
//   int getInt(
//   int min,   // minimum acceptable value
//   int max,   // maximum acceptable value
//   const char* prompt = nullptr,  // User entry prompt
//   const char* errorMessage = nullptr, // Invalid value error message
//   bool showRangeAtError = true    // display the range if invalud value entered 
//   );
//   
//   char* getcstr(
//   const char* prompt = nullptr,   // User entry prompt
//   std::istream& istr = std::cin,  // the Stream to read from
//   char delimiter = '\n'    // Delimiter to mark the end of data
//   );
//
//   template <typename type>
//   void removeDynamicElement(type* array[], int index, int& size) {
//      delete array[index];
//      for (int j = index; j < size; j++) {
//         array[j] = array[j + 1];
//      }
//      size--;
//   }
//}
//#endif // !SDDS_UTILS_H_
//
/* Citation and Sources...
Final Project Milestone 4
Module: utils
Filename: utils.h
Version 1.0
Author	Mahrokh Sadrolodabaee
Revision History
-----------------------------------------------------------
Date      Reason
2021/3/28  Preliminary release
-----------------------------------------------------------
I have done all the coding by myself and only copied the code
that my professor provided to complete my workshops and assignments.
-----------------------------------------------------------
*/


#ifndef SDDS_UTILS_H_
#define SDDS_UTILS_H_
#include <iostream>
namespace sdds {
    extern bool debug;

    int getTime();

    int getInt(const char* prompt = nullptr);

    int getInt(
        int min,
        int max,
        const char* prompt = nullptr,
        const char* errorMessage = nullptr,
        bool showRangeAtError = true
    );

    char* getcstr(
        const char* prompt = nullptr,
        std::istream& istr = std::cin,
        char delimiter = '\n'
    );

    template <typename type>
    void removeDynamicElement(type* array[], int index, int& size) {
        delete array[index];
        for (int j = index; j < size; j++) {
            array[j] = array[j + 1];
        }
        size--;
    }

}
#endif // !SDDS_UTILS_H_
