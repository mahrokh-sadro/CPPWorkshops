//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.31.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments, and specifiers on line 33 and 38 from Leon Li.
////////////////////////////////////////////////
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include "File.h"

namespace sdds {
   FILE* fptr;
   bool openFile(const char filename[]) {
      fptr = fopen(filename, "r");
      return fptr != NULL;
   }
   int noOfRecords() {
      int noOfRecs = 0;
      char ch;
      while (fscanf(fptr, "%c", &ch) == 1) {
         noOfRecs += (ch == '\n');
      }
      rewind(fptr);
      return noOfRecs;
   }
   void closeFile() {
      if (fptr) fclose(fptr);
   }


   bool read(char* m_postalcode) {

       //scanf return the number of successful reads
       return (fscanf(fptr, "%[^,],", m_postalcode) == 1);

   }

   bool read(int& m_population) {

       return (fscanf(fptr, "%d\n", &m_population) == 1);

   }
}