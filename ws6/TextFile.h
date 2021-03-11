//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.11.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
#ifndef SDDS_TEXTFILE_H__
#define SDDS_TEXTFILE_H__
#include <iostream>
namespace sdds {
    class Text;
    class Line {
        char* m_value{ nullptr };  
        operator const char* ()const;
        Line() {};
        Line& operator=(const char*);
        ~Line();
        // copy and copy assignment prevention goes here
        Line(const Line& copyfrom) = delete;
        Line& operator=(const Line&) = delete; 
        friend class TextFile;

    };

    class TextFile {
        Line* m_textLines; // initialized to nullptr
        char* m_filename;   // initialized to nullptr
        unsigned m_noOfLines;
        unsigned m_pageSize;
        void setFilename(const char* fname, bool isCopy = false);
        void setNoOfLines();
        void loadText();
        void saveAs(const char* fileName)const;
        void setEmpty();
    public:
        TextFile(unsigned pageSize = 15);
        TextFile(const char* filename, unsigned pageSize = 15);
        TextFile(const TextFile& copyFrom);
        TextFile& operator=(const TextFile& str);
        ~TextFile();
        std::ostream& view(std::ostream& ostr)const;
        std::istream& getFile(std::istream& istr);
        operator bool()const;
        unsigned lines()const;
        const char* name()const;
        const char* operator[](unsigned index)const;
    };
    std::ostream& operator<<(std::ostream& ostr, const TextFile& text);
    std::istream& operator>>(std::istream& istr, TextFile& text);

}
#endif // !SDDS_TEXTFILE_H__

