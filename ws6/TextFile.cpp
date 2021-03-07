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
      m_value = new char[strlen(lineValue) + 1];
      strcpy(m_value, lineValue);
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
             /*  m_filename = new char[fname.length() + 1];
               strcpy(m_filename, fname.c_str());*/
           }
       }
       
   }
  
   void TextFile::setNoOfLines()  {

       ifstream f(m_filename);
       m_noOfLines = 0;
       string line;
       if (f.is_open()) {
           while (getline(f,line)) {
                 ++m_noOfLines;

           }
           ++m_noOfLines;
       }
       if (m_noOfLines == 0) {
           delete[] m_filename;
           m_filename = nullptr;
       }
   }//to read data from console or filelwe hvavr to use
   //getline????

 


  void TextFile::loadText() {
      if (m_filename) {
          int i(0);

          delete[] m_textLines;
          m_textLines = nullptr;
          m_textLines=new Line[m_noOfLines];
          string temp;
          ifstream f(m_filename);
       
          while(/*!f.eof() && */getline(f, temp)){
                                                        //f >> temp;//?????????????????????? wats the difference between this n getline
              m_textLines[i] = temp.c_str();            //how can i write a tester for each f? 
              i++;
          }
          m_noOfLines = i;

        
      }
     


   }
  
   void TextFile::saveAs(const char* fileName) const {
       ofstream f(fileName);//open a new file
       int i(0);
       if (f.is_open()) {
           for(i=0;i< m_noOfLines;i++)
           f << m_textLines[i] << endl;
       }

   }
 /*  Creates an empty TextFileand initializes the m_pageSize 
       attribute using the pageSize argument.
   */
   TextFile::TextFile(unsigned pageSize):m_pageSize(pageSize), m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0) {///?
       //Creates an empty TextFile ??????????????????
      //arent we supposed to use ostream obj????????????????????????????????????????????????????????????????????????????????????/
   }
  
   TextFile::TextFile(const char* filename, unsigned pageSize) :m_pageSize(pageSize), m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0){
      
       if (filename) {
           setFilename(filename,true);
           setNoOfLines();
           loadText();
       }
   
   
   }


  
   //copy constructor
   TextFile::TextFile(const TextFile& copyFrom): m_pageSize(copyFrom.m_pageSize), m_textLines(nullptr), m_filename(nullptr), m_noOfLines(0) {
                                                                                                       //*this = copyFrom;
                                                                                                      // setEmpty();
        // If the incoming Text object is in a valid State???????? ??????????????      
       if (copyFrom) {
           setFilename(copyFrom.m_filename, true);
           saveAs(copyFrom.m_filename);
           setNoOfLines();
           loadText();
      }
       
   }
   //copy assignment
   TextFile& TextFile::operator=(const TextFile& str)   {
       if (this != &str && str && *this) {
                                                                                              /* delete[] m_textLines;
                                                                                               m_textLines = nullptr;*/
                                                                                               //*this = str;
           setEmpty();
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
           ostr << m_filename;   

           ostr.width(strlen(m_filename))<< ostr.fill('=');

           for (i = 0; i < m_pageSize; i++)    ostr << m_textLines[i];

           ostr << "Hit ENTER to continue...";
           char input;
           cin >> input;
           if (input == '\n') {
               for (i = 0; i < m_noOfLines - m_pageSize; i++) {
                   ostr << m_textLines[i];
               }

           }

       }

       return ostr;//////////////////////////////////////////////////was wrongggggg

   }

  
 
 
   std::istream& TextFile::getFile(std::istream& istr)  {//cin
       string temp;
       istr >> temp;   //reads till space??????????????????????????????????????????????????????????????????????????????????????//
      setFilename(temp.c_str(),true);
      setNoOfLines();
      loadText();
      return istr;
  
   }

  
   const char* TextFile::operator[](unsigned index) const  {
     
       if (*this) {
           return  m_textLines[index % m_noOfLines];
       }
      // return 0;return null????
   }

   TextFile::operator bool() const   {//all attributes??
      // return !!*this;?? or !!setEmpty()????????????????????????????????????????????????????????????????????????////
       return m_textLines && m_filename && m_noOfLines!=0 && m_pageSize !=0;
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
