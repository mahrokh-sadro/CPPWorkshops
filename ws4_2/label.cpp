#define _CRT_SECURE_NO_WARNINGS
#include <istream>///?????????
#include <iomanip>//???????//


#include "label.h"


#include <cstring>

#define SDDS_DEBUG

using namespace std;
namespace sdds {


	


	

	void Label::setToDefault()	{
		m_label = nullptr;
	}

	void Label::setLable(const char* theLable){

		delete[] m_label;
		m_label = new char[strlen(theLable) + 1];
		strcpy(m_label, theLable);
		m_label[strlen(theLable)] = 0;

	}

	void Label::setFrame(const char* theFrame)	{
		strcpy(m_frame, theFrame);
	}


	//Creates an empty label and defaults the frame to "+-+|+-+|"
	Label::Label()	{
		setToDefault();
		setFrame("+-+|+-+|");

	}
	//Creates an empty label and sets the frame to the frameArg argument.

	Label::Label(const char* frameArg)	{
		setToDefault();
		setFrame(frameArg);
	}

	/*Creates a Label with the frame set to frameArg and the content of
		the Label set to the corresponding argument.Note that you must
		keep the content dynamically even though it should never be more
		than 70 characters.*/
	Label::Label(const char* frameArg, const char* content)	{
		setFrame(frameArg);
		setLable(content);
	}


	//Makes sure there is no memory leak when the label goes out of scope.
	Label::~Label()	{
		delete[] m_label;
		m_label = nullptr;
	}

	/*Reads the label from console up to 70 characters and stores it in the
		Label as shown in the Execution sample*/
	void Label::readLabel()	{//////////////////////////////////////////////////////////////////////////////////////

	}

	std::ostream& Label::printLabel() const	{

		
	}

}
