#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#include <cstring>
#include <string>

#include <fstream>
#include "Text.h"

using namespace std;
namespace sdds {
   int Text::getFileLength() const {
      int len = 0;
      ifstream fin(m_filename);
      while (fin) {
         fin.get();
         len += !!fin;
      }
      return len;
   }

   void Text::setFilename(const char* filename)//not deleting the pointer
   {
       if (filename)
       {
           m_filename = new char[strlen(filename) + 1];
           strcpy(m_filename, filename);
       }
       else
       {
           m_filename = new char[1];
           m_filename[0]=0;
       }
   }

   void Text::setContent(const char* content)
   {
       if (content)
       {
           m_content = new char[strlen(content) + 1];
           strcpy(m_content, content);
       }
       else
       {
           m_content = new char[1];
           m_content[0] = 0;

       }
   }
   /*This index operator provides read - only access to 
       the content of the text for the derived classes of Text.

       The behaviour of the operator is not defined if the index goes out of bounds.*/
   const char& Text::operator[](int index) const
   {
       return m_content[index];//???
   }

   Text::Text(const char* filename)
   {
       setFilename(filename);
   }

   Text::Text(const Text& obj)
   {
       //set attributes to null if they arent already
       *this = obj;
       //operator=(obj);make sure its impl
       
   }

   Text& Text::operator=(const Text& obj)
   {
       setFilename(obj.m_filename);
       setContent(obj.m_content);
       return *this;
   }

   Text::~Text()
   {
       delete[] m_filename;
       m_filename = nullptr;
       delete[] m_content;
       m_content = nullptr;
   }
  /*First, read will the current content of the file
  and then allocates memory to the size of the file 
  on the disk + 1 (for the null byte).
Then it will read the contents of the file character 
by character into the newly allocated memory and
terminates it with a null byte at the end. */

   void Text::read()
   {
       string str;
      /* ifstream fin(m_filename);
       while (fin)
       {
           getline(fin, str);
       }*/
       cin >> str;
       int len = getFileLength();//how
       m_content = new char[len + 1];
       strcpy(m_content, str.c_str());

   }
   //This virtual function will insert the content of the Text
   //class into the ostream if m_content is not null.
   ostream& Text::write(ostream& os) const
   {
       if (m_content) os << m_content;
       return os;

   }

   ostream& operator<<(ostream& os, const Text& obj)
   { 
       return obj.write(os);
   }

}