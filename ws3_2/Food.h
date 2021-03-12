//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.07.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////



#ifndef SDDS_FOOD_H_
#define SDDS_FOOD_H_
namespace sdds {

    class Item {
        char m_itemName[31];   //31 cuz I have a string with 30 chars 1 for null
        double m_calories;    //  >0 && <=3000 
        int m_when;      
        void setName(const char* name);  // sets the itemName member Cstring variable to a the Cstring in the name argument up to 29 characters.
      
    public:
        void setEmpty();
        void set(const char* name, double calories, int when);
        void display()const;
        bool isValid()const;
        double calories()const;
      //  int when()const;
    };
}

#endif // !SDDS_SUBJECT_H





