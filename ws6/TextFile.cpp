#define  _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <fstream>
#include <string>



#include <cstring>


#include "TextFile.h"
#include "cstring.h"
using namespace std;
namespace sdds {
   Line::operator const char* () const {
      return (const char*)m_value;
   }
   Line& Line::operator=(const char* lineValue) {
      delete[] m_value;
      m_value = new char[strlen(lineValue) + 1];///////////////////
      strcpy(m_value, lineValue);////////////////////////////////////////////////
      return *this;
   }
   Line::~Line() {
      delete[] m_value;
   }
   //Line::Line():m_value(nullptr) {};


   void TextFile::setEmpty()  {
       delete[] m_textLines; 
       m_textLines = nullptr;
       delete[] m_filename;
       m_filename = nullptr;
       m_noOfLines = 0;
   }

   

   void TextFile::setFilename(const char* fname, bool isCopy){
      // setEmpty(); //???
      if (isCopy == true) {
           m_filename = new char[strlen(fname) + 3];//C_
           strcpy(m_filename, "C_");
           strcat(m_filename, fname);
      }
       else {
          m_filename = new char[strlen(fname) + 1];
          strcpy(m_filename, fname);
       }
   }

   void TextFile::setNoOfLines()  {
       char c;
       ifstream readFromFile(m_filename);
                                                                           /*string temp;
                                                                       while (getline(readFromFile, temp)) ++m_noOfLines;*/
       if (readFromFile.is_open()) {
           while (readFromFile) {
               readFromFile >> c;
               if(c=='\n')   ++m_noOfLines;

           }
           ++m_noOfLines;
       }
       if (m_noOfLines == 0) {
           delete[] m_filename;
           m_filename = nullptr;
       }
 


  void TextFile::loadText() {
      if (m_filename) {
          int i(0);

          delete[] m_textLines;
          m_textLines = nullptr;
          m_textLines=new Line[m_noOfLines];
          string temp;
          ifstream f(m_filename);
          getline(f, temp);
         
          while(!f.eof()){                                                // how to do for (i = 0; f != NULL; i++)//f???
              f >> temp;
              m_textLines[i] = temp.c_str();
              i++;
          }
          m_noOfLines = i;

        
      }
     


   }

   void TextFile::saveAs(const char* fileName) const {
       ofstream myDisplay(fileName);
       int i(0);
       if (myDisplay.is_open()) {
           for(i=0;i< m_noOfLines;i++)
           myDisplay << m_textLines[i] << endl;
       }

   }

 
   TextFile::TextFile(unsigned pageSize)/*:m_pageSize(pageSize)*/{
        setEmpty();
        m_pageSize=pageSize;
   }
   TextFile::TextFile(const char* filename, unsigned pageSize) /*:m_pageSize(pageSize)*/{
       setEmpty();
       m_pageSize=pageSize;
       if (filename) {
           setFilename(filename,true);
           setNoOfLines();
           loadText();
       }
   
   
   }
   //copy constructor


 
   TextFile::TextFile(const TextFile& copyFrom)   {
       //*this = copyFrom;????
       setEmpty();
       m_pageSize = copyFrom.m_pageSize;
       setFilename(copyFrom.m_filename,true);
       saveAs(copyFrom.m_filename);
       setNoOfLines();
      loadText();
   }
   //copy assignment
   TextFile& TextFile::operator=(const TextFile& str)   {
       if (this != &str && str && *this) {
           delete[] m_textLines;
           m_textLines = nullptr;
           //*this = str;
           saveAs(str.m_filename);
           setNoOfLines();
           loadText();
       }
     
       return *this;
   }

   TextFile::~TextFile()  {
       delete[] m_filename;
       m_filename = nullptr;
       delete[] m_textLines;
       m_textLines = nullptr;
   }
   unsigned TextFile::lines() const {
       return m_noOfLines;
   }


   

   std::ostream& TextFile::view(std::ostream& ostr) const  {//cout//dispplay
       int i(0);
       if (*this) {
           ostr << m_filename;    //if(*this)

           for (i = 0; i < strlen(m_filename); i++) ostr << '=';
           for (i = 0; i < m_pageSize; i++) ostr << m_textLines[i];

           ostr << "Hit ENTER to continue...";
           char input;
           cin >> input;
           if (input == '\n') {
               for (i = 0; i < m_noOfLines - m_pageSize; i++) {
                   ostr << m_textLines[i];
               }

           }
           return ostr;

       }


   }

  
 

   std::istream& TextFile::getFile(std::istream& istr)  {//cin
       string temp;
       //istr >> temp;
       getline(istr, temp);
      setFilename(temp.c_str(),true);
      setNoOfLines();
      loadText();
      return istr;
  
   }


   const char* TextFile::operator[](unsigned index) const  {
       if (*this) {
           return  m_textLines[index % m_noOfLines];
       }
       else return NULL;
   }

   TextFile::operator bool() const   {//all attributes??
      // return !!*this;??
       return m_textLines && m_filename && m_noOfLines && m_pageSize;//!isEmpty?
   }

    const char* TextFile::name() const  {

       return m_filename;
   }

  

   std::ostream& operator<<(std::ostream& ostr, const TextFile& text)  {
       return text.view(ostr);
        
      
   }

   std::istream& operator>>(std::istream& istr, TextFile& text)  {
       return text.getFile(istr);
   }

}
