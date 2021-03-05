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
       delete[] m_textLines; //why??we hadnt done this before
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
  /* Creates a local ifstream object to open the file 
       the name held in m_filename.Then it will read
       the file, character by character, and 
       accumulates the number of newlines in the 
       m_noOfLines attribute.
      In the end, it will increase m_noOfLines
       by one, just in case, the last line does
       not have a new line at the end.
       If the number of lines is zero, it will delete
       the m_filename and set it to nullptr. 
       (Setting the TextFile to a safe empty state)*/
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
   }//to read data from console or filelwe hvavr to use
   //getline????

  /* Loads the text file m_filename into the dynamic
       array of Lines pointed by m_textLines :
   If the m_filename is null, this function does 
       noe m_filename is not null
      (TextFile is not in a safe empty state), 
       loadText() will dynamically allocate an 
       array of Lines pointed by m_textLines with 
       the size kept in m_noOfLines.thing.
      If th*/
  /*Make sure m_textLine is deleted before this to 
      prevent memory leak.*/


  void TextFile::loadText() {
      if (m_filename) {
          int i(0);

          delete[] m_textLines;
          m_textLines = nullptr;
          m_textLines=new Line[m_noOfLines];
          string temp;
          ifstream f(m_filename);
          getline(f, temp);
         /* In a loop reads each line into the string 
              object and then sets the m_textLines
              array elements to the values returned 
              by the c_str() method of the string 
              object until the reading fails(end of
                  file reached).*/
          while(!f.eof()){// how to do for (i = 0; f != NULL; i++)//f???
              f >> temp;//??????????????????????
              m_textLines[i] = temp.c_str();
              i++;
          }
          m_noOfLines = i;

        
      }
     


   }
  /*Saves the content of the TextFile under a new name.
     Use a local ofstream object to open a new file
      using the name kept in the argument filename.Then
      loop through the elements of the m_textLines 
      arrayand write them in the opened file adding
      a new line to the end of each line.*/
   /*void TextFile::saveAs(const char* fileName) const   {
       ofstream myDisplay(fileName);
       int i(0);
       while (myDisplay) {
           myDisplay<< m_textLines[i]<<endl;
           i++;
       }
       
   }*////????????????????????
   void TextFile::saveAs(const char* fileName) const {
       ofstream myDisplay(fileName);
       int i(0);
       if (myDisplay.is_open()) {
           for(i=0;i< m_noOfLines;i++)
           myDisplay << m_textLines[i] << endl;
       }

   }

   /*Creates an empty TextFile and initializes the
       m_pageSize attribute using the pageSize
       argument.*/
   TextFile::TextFile(unsigned pageSize)/*:m_pageSize(pageSize)*/{
       //Creates an empty TextFile ???????????????????
        setEmpty();
        m_pageSize=pageSize;
       //which one happens first??
   }
   //?????nitialize????
   TextFile::TextFile(const char* filename, unsigned pageSize) /*:m_pageSize(pageSize)*/{
       setEmpty();
       m_pageSize=pageSize;
       if (filename) {
           setFilename(filename,true);
           setNoOfLines();
           // load the Text
           loadText();
       }
   
   
   }
   //copy constructor


  /* Sets the file - name to the name of the incoming 
       TextFile object(isCopy set to true) See 
       setFilename()
       Saves the content of the incoming TextFile
       under the file name of the current TextFile
       set the number of lines
       loads the Text*/

   //copy construction?????????????
   TextFile::TextFile(const TextFile& copyFrom)   {
       //*this = copyFrom;
       setEmpty();
       m_pageSize = copyFrom.m_pageSize;
       setFilename(copyFrom.m_filename,true);
       saveAs(copyFrom.m_filename);
       setNoOfLines();
      loadText();////////////////////////////////////
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
     
       return *this;//////?????????????//////////
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


   /*Prints the filename and then the content of the file "m_pageSize"
       lines at a time.

       print the file name
       underline the file name with '=' character
       loops through the lines and print them one by line
       pauses after printing "m_pageSize" lines and prompts the user
       Hit ENTER to continue... and waits for the user to press
       enterand repeats until all lines are printed.

       The function performs no action if the TextFile is in an empty state.

       This function receives and returns an instance of istreamand
       uses the instance for printouts.*/

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

  
 
  /* Receives a filename from istr to set the file name of the
       TextFile.Then sets the number of line sand loads the
       Text.When done it will return the istr;*/
   std::istream& TextFile::getFile(std::istream& istr)  {//cin
       string temp;
       //istr >> temp;
       getline(istr, temp);
      setFilename(temp.c_str(),true);
      setNoOfLines();
      loadText();
      return istr;
  
   }

  /* Returns the element in the m_textLine array corresponding
       to the index argument.If the TextFile is in an empty 
       state, it will return null.If the index exceeds the 
       size of the array it should loop back to the beginning.
     For example, if the number of lines is 10, the last 
       index should be 9 and index 10 should return the
       first element and index 11 should return the 
       second element.*/
   const char* TextFile::operator[](unsigned index) const  {
     // if(TextFile != nullptr)???????????????????/
       if (*this) {
           return  m_textLines[index % m_noOfLines];
       }
       else return NULL;
   }

   TextFile::operator bool() const   {//all attributes??
      // return !!*this;??
       return m_textLines && m_filename && m_noOfLines && m_pageSize;
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
