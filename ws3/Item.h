//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.04.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {
    class Item {
        char m_itemName[21];
        double m_price;
        bool m_taxed;
        void setName(const char* name);
    public:
        void setEmpty();
        void set(const char* name, double price, bool taxed);
        void display()const;
        bool isValid()const;
        double price()const;
        double tax()const;
    };
}

#endif // !SDDS_SUBJECT_H