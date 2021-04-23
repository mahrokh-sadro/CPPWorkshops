#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include "HtmlText.h"
using namespace std;
namespace sdds {
	


	HtmlText::HtmlText(const char* filename, const char* title)
		:Text(filename)
	{
		if (filename && title)
		{
			m_title = new char[strlen(title) + 1];
			strcpy(m_title,title);
		}
		else
		{
			m_title = new char[1];
			m_title[0] = 0;
		}

	}
	/*
		 FullName::FullName(const FullName& fn):Name(fn) {
		  m_lastname = new char[strlen(fn.m_lastname) + 1];
		  strcpy(m_lastname, fn.m_lastname);
	   }
	   //FullName::FullName(const FullName& fn) {
	   //   operator=(fn); // make sure name is copied too
	   //}

	
	*/
	HtmlText::HtmlText(const HtmlText& html)
		:Text(html)
	{
		m_title = new char[strlen(html.m_title) + 1];
		strcpy(m_title, html.m_title);

	}

	//or
	/*HtmlText::HtmlText(const HtmlText& html)
		
	{
		operator=(html);

	}*/


	/*
	FullName& FullName::operator=(const FullName& fn) {
      if (this != &fn) {
         delete[] m_lastname;
         Name::operator=(fn);
         m_lastname = new char[strlen(fn.m_lastname) + 1];
         strcpy(m_lastname, fn.m_lastname);
      }
      return *this;
   }
	*/
	HtmlText& HtmlText::operator=(const HtmlText& html)//for asg operator first check for self asg
	{
		if (this != &html)
		{
			delete[] m_title;
			m_title = nullptr;
			Text::operator=(html);
			m_title = new char[strlen(html.m_title) + 1];
			strcpy(m_title, html.m_title);
		}
		return *this;
	}

	HtmlText::~HtmlText()
	{
		delete[] m_title;
		m_title = nullptr;
	}

	ostream& HtmlText::write(ostream& os) const
	{
		bool ms = false;
		os << "<html><head><title>"<<(m_title?m_title:"No Title")

			<< "</html></head>\n</title>\n";
		if (m_title) os << "<h1>" << m_title << "</h1>\n";



		return os;
	}

	//create a boolean variable and set it to false to keep track of the occurance of multiple 
	//spaces(let's call it MS for Multiple Spaces)
	//	insert "<html><head><title>"
	//	if m_title is not null, insert the title, otherwise insert "No Title"
	//		insert "</title></head>\n<body>\n"

	//		if "</title>\n\n" is not null insert "<h1>" << m_title << "</h1>\n"


	//			loop through all the elements of the m_content
	//(using the protected index operator) and convert the characters as follows :











}