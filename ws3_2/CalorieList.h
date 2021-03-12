//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.07.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_CalorieList_H_
#define SDDS_CalorieList_H_
#include "Food.h"
namespace sdds {
    //The CalorieList class should dynamically hold series of Food items and display them in a report.
    class CalorieList {

        char m_title[37];  // title of the calorie list
        Item* m_items;     // pointer to the dynamically allocated array of Items
        int m_noOfItems;   // size of the dynamically allocated array of Items
        int m_itemsAdded;  // number of the Items added by the add method
        double totalCalories()const;  // returns the sum of calories of Items
        void Title()const;       // Prints the title of the calorie list             
        void footer()const;
        void setEmpty();     // sets the CalorieList to an emtpy state
        bool isValid()const;  // returns true is the CalorieList and all of its Items are valid



    public:
 
                                       // sets the CalorieList to accept the "size" number of Food Items. 
                                      // This function is called to prepare the CalorieList for accepting food items
        void init(int size);
                                        // Adds Food Items using their Name, Calorie count and time of consumption up to 
                                        // the number set in the init() function, returns true if successful.
        bool add(const char* item_name, int calories, int when);
                                        // Displays the report with food information and the total calorie consumed in the day
                                        // as shown in the report sample
        void display()const;
                                        // Releases all the memory used. After this function init() can be called for another
                                        // report;
        void deallocate();


    };
}
#endif // !SDDS_TRANSCRIPT_H


