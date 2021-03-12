//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.28.2021
//I have done all the coding by myselfand only copied the code that my professor provided to 
//complete my workshopsand assignments.
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


  /////////////////// TODO: read functions go here    
   bool read(char* name) {

       if (fscanf(fptr, "%[^\n]\n", name) != 1)       return false;
       else   return true;
          

   }
   bool read(int& m_empNo) {

      if (fscanf(fptr, "%d,", &m_empNo) != 1)      return false;
      else   return true;
          
   }
   bool read(double& m_salary) {
      
       if (fscanf(fptr, "%lf,", &m_salary) != 1)            return false;
       else   return true;
          
      
   }
  
}