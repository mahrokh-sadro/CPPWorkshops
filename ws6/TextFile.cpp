//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.11.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {

    Line::operator const char* () const {
        return (const char*)m_value;
    }

   







    Line& Line::operator=(const char* lineValue) {
        if (m_value != nullptr)
            delete[] m_value;
        m_value = new char[strLen(lineValue) + 1];
        strCpy(m_value, lineValue);
        return *this;
    }
    Line::~Line() {
        if (m_value != nullptr)
            delete[] m_value;
    }

    void TextFile::setEmpty() {

        delete[] m_textLines;
        m_textLines = nullptr;
        delete[] m_filename;
        m_filename = nullptr;

        m_noOfLines = 0;
    }

    void TextFile::setFilename(const char* fname, bool isCopy) {

        delete[] m_filename;
        m_filename = nullptr;
        if (fname) {
            if (isCopy==false) {
                m_filename = new char[strLen(fname) + 1];
                strCpy(m_filename, fname);
            }

            else {
                m_filename = new char[strLen(fname) + 3];//C_
                strCpy(m_filename, "C_");
                strCat(m_filename, fname);

            }
        }




    }


    void TextFile::setNoOfLines() {

        ifstream f(m_filename);
        m_noOfLines = 0;
        string line;
        if (f.is_open()) {
            while (getline(f, line)) {
                ++m_noOfLines;

            }
            ++m_noOfLines;
        }
        if (m_noOfLines == 0) {
            delete[] m_filename;
            m_filename = nullptr;
        }
    }

    void TextFile::loadText() {
        if (m_filename) {
            int i(0);

            delete[] m_textLines;
            m_textLines = nullptr;
            m_textLines = new Line[m_noOfLines];
            string temp;
            ifstream f(m_filename);

            while (/*!f.eof() && */getline(f, temp)) {//not f>>temp cuz f is an instance of istream and just reads a word

                m_textLines[i] = temp.c_str();
                i++;
            }
            m_noOfLines = i;

        }
    }
    void TextFile::saveAs(const char* fileName) const {
        ofstream f(fileName);//open a new file
        unsigned i(0);
        if (f.is_open()) {// r we supposed to check this?/
            for (i = 0; i < m_noOfLines; i++)  f << m_textLines[i] << endl;

        }

    }

    TextFile::TextFile(unsigned pageSize)
        :m_textLines(nullptr),
        m_filename(nullptr),
        m_noOfLines(0),
        m_pageSize(pageSize) {}



    TextFile::TextFile(const char* filename, unsigned pageSize)
        :m_textLines(nullptr),
        m_filename(nullptr),
        m_noOfLines(0),
        m_pageSize(pageSize) {

        if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }

    }

    TextFile::TextFile(const TextFile& copyFrom)
        :m_textLines{nullptr},
        m_filename(nullptr),
        m_noOfLines(0),
        m_pageSize{copyFrom.m_pageSize} {
    
        if (copyFrom) {
            setFilename(copyFrom.m_filename, true);
            copyFrom.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }

    }
    //for the validation of textfile we don need to create an instance of ifstream
    //if theres a filename thats valid
    // ifstream f(copyFrom.m_filename);
   // if (!f.fail())



    TextFile& TextFile::operator=(const TextFile& other)   {
        if(m_filename && other.m_filename)
        {
            delete[] m_textLines;
            m_textLines = nullptr;
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

    TextFile::~TextFile() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_textLines;
        m_textLines = nullptr;
    }

    unsigned TextFile::lines() const {
        return m_noOfLines;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const {

        if (*this) {
            ostr << m_filename << endl;
            for (int i = 0; m_filename[i]; i++)       ostr << "=";

            ostr << endl;
            for (unsigned i = 0; i < m_noOfLines; i++)
            {
                ostr << m_textLines[i] << endl;
                if ((i + 1) == m_pageSize)

                {
                    ostr << "Hit ENTER to continue...";
                    cin.ignore();
                }
            }
        }
        return ostr;
    }


   std::istream& TextFile::getFile(std::istream& istr) {
       string temp;
       getline(istr, temp); 
       setFilename(temp.c_str());
       setNoOfLines();
       loadText();
       return istr;

   }

   const char* TextFile::operator[](unsigned index) const {
       char* ret = nullptr;//wats const char*?has anything to do with arr of poiters
       if (*this) {
           ret = m_textLines[index % m_noOfLines].m_value;
       }
       return ret;//how to do ternary????????????????
   }

   TextFile::operator bool() const {
       // return !!*this;?? or !!isEmpty()??

      return m_textLines && m_filename && m_noOfLines != 0;
   }

    const char* TextFile::name() const {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);

    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}