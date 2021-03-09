#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>
#include "TextFile.h"
#include <cstring>
using namespace std;
namespace sdds {
  /*  Line::Line() {
        m_value = nullptr;
    }*/
    Line::operator const char* () const {
        return (const char*)m_value;
    }
    Line& Line::operator=(const char* lineValue) {
        if (m_value != nullptr)
            delete[] m_value;
        m_value = new char[strlen(lineValue) + 1];
        strcpy(m_value, lineValue);
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
        //setEmpty(); //???
        delete[] m_filename;
        m_filename = nullptr;
        if (fname) {
            if (!isCopy) {
                m_filename = new char[strlen(fname) + 1];
                strcpy(m_filename, fname);
            }

            else {
                m_filename = new char[strlen(fname) + 3];//C_
                strcpy(m_filename, "C_");
                strcat(m_filename, fname);

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

            while (/*!f.eof() && */getline(f, temp)) {
                //f >> temp;//?????????????????????? wats the difference between this n getline
                m_textLines[i] = temp.c_str();            //how can i write a tester for each f? 
                i++;
            }
            m_noOfLines = i;


        }

    }



    void TextFile::saveAs(const char* fileName) const {
        ofstream f(fileName);//open a new file
        unsigned i(0);
        if (f.is_open()) {//r we supposed to check this????
            for (i = 0; i < m_noOfLines; i++)
                f << m_textLines[i] << endl;
        }

    }

    TextFile::TextFile(unsigned pageSize) :m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {
     //arent we supposed to use ostream obj?????????????????????????????????
    }

  
    TextFile::TextFile(const char* filename, unsigned pageSize) :m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(pageSize) {

        if (filename) {
            setFilename(filename);
            setNoOfLines();
            loadText();
        }


    }



    TextFile::TextFile(const TextFile& copyFrom) :m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0), m_pageSize(copyFrom.m_pageSize) {
        //*this = copyFrom;
       // setEmpty();
// If the incoming Text object is in a valid State??????????????????????????????????????????????????????????????      
/* Saves the content of the incoming TextFile under the
     file name of the current TextFile*/
        ifstream f(copyFrom.m_filename);
        if (!f.fail()) {
            setFilename(copyFrom.m_filename, true);
            copyFrom.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }

    }


    TextFile& TextFile::operator=(const TextFile& other)
    {
        ifstream file1(m_filename);
        ifstream file2(other.m_filename);
       // if (file1.good() && file2.good())
        //how to check if a file is in a valid state ?when we read it doesnt fail
            if (!file1.fail() && !file2.fail())

        {
            delete[] m_textLines;
            m_textLines = nullptr;
            other.saveAs(m_filename);
            setNoOfLines();
            loadText();
        }
        return *this;
    }

   
    //my operator=  was buggy




    TextFile::~TextFile() {
        delete[] m_filename;
        m_filename = nullptr;
        delete[] m_textLines;
        m_textLines = nullptr;
    }




    unsigned TextFile::lines() const    {
        return m_noOfLines;
    }

    std::ostream& TextFile::view(std::ostream& ostr) const//bbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbbb
    {
       
        if (*this) {
            ostr << m_filename << endl;
            for (int i = 0; m_filename[i]; i++)       ostr << "=";

            ostr << endl;
            for (unsigned i = 0; i < m_noOfLines; i++)
            {
                ostr << m_textLines[i] << endl;
                if (                     m_pageSize )
                {
                    ostr << "Hit ENTER to continue...";
                    cin.ignore();


                }
            }
        }
        return ostr;
    }
  

    //my view is buggy



  

   std::istream& TextFile::getFile(std::istream& istr) {//cin
       string temp;
       getline(istr, temp);   //why not istr>>temp????????????
       setFilename(temp.c_str()/*, true*/);
       setNoOfLines();
       loadText();
       return istr;

   }


   const char* TextFile::operator[](unsigned index) const {
       char* ret = nullptr;//wats const char*???????????????????????????????arr of pointers????????
       if (*this) {
           ret = m_textLines[index % m_noOfLines].m_value;
       }
       return ret;//how to do ternary????????????????
   }



   TextFile::operator bool() const {
     // return !!*this;?? or !!isEmpty()??
       return m_textLines && m_filename && m_noOfLines != 0 /*&& m_pageSize !=0*/;
   }



    const char* TextFile::name() const   {
        return m_filename;
    }

    std::ostream& operator<<(std::ostream& ostr, const TextFile& text) {
        return text.view(ostr);


    }

    std::istream& operator>>(std::istream& istr, TextFile& text) {
        return text.getFile(istr);
    }
}
