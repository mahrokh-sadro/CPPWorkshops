#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>
namespace sdds {
   class Canister {
      char* m_contentName; // points to a dynamically allocated Cstring
      double m_diameter; // in centimeters 
      double m_hieght;   // in centimeters
      double m_contentVolume;  // in CCs
      bool m_usable; // a flag to identify if the Canister is usable or unusable
      void setToDefault();
      void setName(const char* Cstr);
      bool isEmpty()const;
      bool hasSameContent(const Canister& C)const;
   public:
      Canister();
      Canister(const char* contentName);
      Canister(double hieght, double diameter,
         const char* contentName = nullptr);
      ~Canister();
      Canister& setContent(const char* contentName);
      Canister& pour(double quantity);
      Canister& pour(Canister& C);//i added C
      double volume()const;
      std::ostream& display()const;
      double capacity()const;
      void clear();
   };
}

#endif // !SDDS_BOX_H
