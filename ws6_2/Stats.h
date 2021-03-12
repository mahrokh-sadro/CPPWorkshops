#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
#include <iostream>
namespace sdds {

    class Line {
        double m_value; // 1 number
        operator double ()const; //
      //  Line() {};
      //  Line& operator=(double);
      //  ~Line();
        // copy and copy assignment prevention goes here
      //  Line(const Line& copyfrom);
      //  Line& operator=(const Line&);
        friend class Stats;

    };



   class Stats {
       char* m_filename;// name of file
       Line* m_textNumbers; //array of all numbers
       unsigned m_noOfNumbers;
       unsigned m_columnWidth;
       unsigned m_noOfColumns;
       unsigned m_precision;;
       //unsigned m_noOfLines;
       void setNoOfNumbers();
       void loadText();
       void saveAs(const char* fileName) const;
       void setEmpty();
   public:
       Stats(unsigned columnWidth = 15,
           unsigned noOfColumns = 4,
           unsigned precision = 2);

       Stats(const char* filename,
           unsigned columnWidth = 15,
           unsigned noOfColumns = 4,
           unsigned precision = 2);
       //copy constructor
       Stats(const Stats& obj);

       //Copy assignment
       Stats& operator=(const Stats& obj);

       double& operator[](unsigned idx);
       double operator[](unsigned idx)const;
       operator bool()const;
       void sort(bool ascending);
       unsigned size()const;
       const char* name()const;
       unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);

  };
   std::ostream& operator<<(std::ostream& os, const Stats& obj);
   std::istream& operator>>(std::istream& is, const Stats& obj);


}
#endif