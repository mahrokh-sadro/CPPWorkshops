#ifndef SDDS_ITEM_H_
#define SDDS_ITEM_H_
namespace sdds {

   class Item {
      char m_itemName[21]; //we cant change these directly,we need to acces them using functions
      double m_price;
      bool m_taxed;
      void setName(const char* name);
   public:
      void setEmpty();
      void set(const char* name, double price, bool taxed);
      void display()const;
      bool isValid()const;  //Returns true if the Item is not set to the empty state
      double price()const;
      double tax()const;
   };
}

#endif // !SDDS_SUBJECT_H
