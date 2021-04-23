#ifndef SDDS_TEXT_H__
#define SDDS_TEXT_H__
#include <iostream>
namespace sdds {
   class Text {
      char* m_filename ;
      char* m_content ;
      int getFileLength()const;
      void setFilename(const char* filename);
      void setContent(const char* content);


   protected:
      const char& operator[](int index)const;
   public:
      Text(const char* filename=nullptr);
      Text(const Text&);
      Text& operator=(const Text&);
      virtual ~Text();

      void read();
      virtual std::ostream&  write(std::ostream& os)const;
   };
   std::ostream& operator<<(std::ostream& os, const Text&);
}
#endif // !SDDS_PERSON_H__

