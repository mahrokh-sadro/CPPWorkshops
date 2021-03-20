
#ifndef SDDS_STATS_H__
#define SDDS_STATS_H__
#include <iostream>
namespace sdds {
    class Stats {
        double* m_arr= nullptr;
        unsigned  m_noOfNums= 0;
        char* m_filename= nullptr;
        unsigned m_columnWidth=0;
        unsigned m_noOfColumns = 0;
        unsigned m_precision = 0;
        double dummy = 0.00;

    public:
        Stats(unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        Stats(const char* filename, unsigned columnWidth = 15, unsigned noOfColumns = 4, unsigned precision = 2);
        Stats(const Stats&);
        ~Stats();
        Stats& operator=(Stats&);
        double& operator[](unsigned idx);
        double operator[](unsigned idx)const;
        operator bool()const;

        void sort(bool ascending);
        unsigned size()const;
        const char* name()const;
        unsigned occurrence(double min, double max, std::ostream& ostr = std::cout);
        void setFilename(const char* fname, bool isCopy = false);
        void loadNums();
        void saveAs(const char* fileName)const;
        std::ostream& view(std::ostream& ostr) const;
        std::istream& getFile(std::istream& istr);
    };
    std::ostream& operator<<(std::ostream& ostr, const Stats& text);
    std::istream& operator>>(std::istream& istr, Stats& text);
}
#endif