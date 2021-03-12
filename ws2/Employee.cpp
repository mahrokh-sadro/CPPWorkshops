//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.28.2021
//I have done all the coding by myselfand only copied the code that my professor provided to 
//complete my workshopsand assignments.
////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include "cstring.h"
#include "Employee.h"
#include "File.h"

using namespace std;


namespace sdds {

    int noOfEmployees;
    Employee* employees;


    void sort() {
        int i, j;
        Employee temp;
        for (i = noOfEmployees - 1; i > 0; i--) {
            for (j = 0; j < i; j++) {
                if (employees[j].m_empNo > employees[j + 1].m_empNo) {
                    temp = employees[j];
                    employees[j] = employees[j + 1];
                    employees[j + 1] = temp;
                }
            }
        }
    }



    bool load(Employee& emp)
    {
        bool ok = false;
        char name[128];
        //First it will read the employee number
        //then salar
        // in a local array of 128 characters, it will read the employee name from the file.
        if (read(emp.m_empNo) && read(emp.m_salary) && read(name))
        {
           
            emp.m_name = new char[strLen(name) + 1];
            strCpy(emp.m_name, name);
                      
            return !ok;
        }
        else return ok;
    }
    // TODO: Finish the implementation of the 0 arg load function
    bool load() {
        bool ok = false;
        int i = 0;
        if (openFile(DATAFILE)) {

            //Set the noOfEmployees to the number of recoreds in the file.
            noOfEmployees = noOfRecords();

                     //create a dynamically allocated array of Employee
                         //new Employee[]
                     //store its address into the global variable.
            employees = new Employee[noOfEmployees];

            for (i = 0; i < noOfEmployees; i++){ 
                // load the employee records from the file into
                 //the dynamic array.
                load(employees[i]);                 
            }
            //If the number of the records does not match the number of reads
            if (i!= noOfEmployees) cout << "Error: incorrect number of records read; the data is possibly corrupted" << endl;
            else ok = !ok;
            closeFile();

        }
        else {
            cout << "Could not open data file: " << DATAFILE << endl;
        }
        return ok;
    }

    // TODO: Implementation for the display functions go here

    //display: receives as a parameter a constant reference to an Employee objectand prints:
    //NUMBER: NAME, SALARY<NEWLINE>

    void display(const Employee& emp) {  //for 1 employee

        cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
    }

    void display() { //for all employees
        //receives no parametersand returns nothing.This function should :

         //print to screen

         //  sort the array
        sort();
        cout << "Employee Salary report, sorted by employee number" << endl;
        cout << "no- Empno, Name, Salary" << endl;
        cout << "------------------------------------------------" << endl;
        //  iterate over the sorted array an print each employee in th format :
        int i;
        for (i = 0; i < noOfEmployees; i++){ 
            //   IDX - NUMBER : NAME, SALARY<NEWLINE>
            cout << i+1 << "- ";
            display(employees[i]);
        }
    }


    // TODO: Implementation for the deallocateMemory function goes here

    void deallocateMemory() {
        // emp.m_name = new char[strLen(name) + 1];
        int i = 0;
        for (i = 0; i < noOfEmployees; i++) {
            delete[] employees[i].m_name;  //dealloction of memory for all employees' name
        }
        // employees = new Employee[noOfEmployees];
        delete[] employees;
    }

}