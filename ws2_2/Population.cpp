
//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.31.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "Population.h"
#include "File.h"
//#include "cstring.h"

using namespace std;
namespace sdds {
    /*dynamic memory allocation since the number of records in submission will
        be much more that what you have for development.*/
	int noOfPostalcodes; //number of objects/rows
    Postalcode* postalcodess; //pointer of type Postalcode



    void sort() {
        int i, j;
        Postalcode temp;
        for (i = noOfPostalcodes - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (postalcodess[j].m_population > postalcodess[j + 1].m_population) {
                    temp = postalcodess[j];
                    postalcodess[j] = postalcodess[j + 1];
                    postalcodess[j + 1] = temp;
                }
            }
        }
    }





    bool load(Postalcode& postal) {

        return (read(postal.m_postalcode) && read(postal.m_population));
    }

    

    bool load(const char filename[]) {

        bool ok = false;
        int i;
        if (openFile(filename)) {     

            noOfPostalcodes = noOfRecords();
            postalcodess = new Postalcode[noOfPostalcodes];  
        

            for (i = 0;i < noOfPostalcodes;i++)
            {
                load(postalcodess[i]);
            }

            //If the file doesn't have a correct content,that is number of read != number of rows
            if (i != noOfPostalcodes)    cout << "Error : incorrect number of records read; the data is possibly corrupted!" << endl;           
            else ok = true;
            closeFile();           
        }

        //	If the file cannot be found
        else {

            cout << "Could not open data file: " << filename << endl;

        }
        return ok;

    }



    void display(const Postalcode& postal) {   //for 1 row

       cout << postal.m_postalcode << ":  " << postal.m_population << endl;
     
    }


    void display() {
        //	Postal Code : population
    //		------------------------ -
    //		1 - A0R : 2543
    //		Population of Canada : 282439
        sort();

        cout << "Postal Code: population" << endl;
        cout << "-------------------------" << endl;
        int i;
        int totalPopulation=0;

        for (i = 0; i < noOfPostalcodes; i++)
        {
            cout << i+1 << "- ";
            display(postalcodess[i]);
            totalPopulation += postalcodess[i].m_population;
        }
        cout << "-------------------------" << endl;

        cout << "Population of Canada: " << totalPopulation << endl;
    }

    
    void deallocateMemory() {
        //deallocateMemory : a function with no parameters that return nothing and
        //deallocate all dynamic memory used by the program.

        delete[] postalcodess;
        postalcodess = nullptr;
    }



}