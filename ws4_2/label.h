#ifndef SDDS_BOX_H
#define SDDS_BOX_H
#include <iostream>

//The label class creates a label by drawing a
//frame around a one - line text with an unknown
//size(maximum of 70 chars, must be kept dynamically).


namespace sdds {
	class Label { 

		char* m_label;   //pointer to the dma             //a one - line text with an unknown size 
		char m_frame[9]; //The frame is dictated by series of 8 characters in a Cstring.
public:
	void setToDefault();
	void setLable(const char* theLable);
	void setFrame(const char* theFrame);
	Label();

	Label(const char* frameArg);

	Label(const char* frameArg, const char* content);
	
	
	~Label();



	
	void readLabel();


	//Prints the label by drawing the frame around the content ad shown in
	//	the Execution sample.Note that no newline is printed after the last
	//	lineand cout is returned at the end.
	std::ostream& printLabel()const;


	};
}

#endif // !SDDS_BOX_H
