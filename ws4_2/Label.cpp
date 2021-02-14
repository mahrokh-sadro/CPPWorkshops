
#define _CRT_SECURE_NO_WARNINGS
#include <istream>///?????????
#include <iomanip>//???????//
#include <iostream>

#include "Label.h"


#include <cstring>

#define SDDS_DEBUG

using namespace std;
namespace sdds {

	void Label::setToDefault() {
		m_label = nullptr;
		m_frame[0] =0;
	}

	void Label::setLable(const char* theLable) {

		delete[] m_label;
		m_label = nullptr;
		int  maxLen = 70;
		int len = (size_t)strlen(theLable) > (size_t)maxLen ? maxLen : strlen(theLable);
		m_label = new char[len + 1];           //whyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy????????????
		strncpy(m_label, theLable, len);
		m_label[len] = 0;

	}

	void Label::setFrame(const char* theFrame) {
		//m_frame[0] = 0;
		strcpy(m_frame, theFrame);
		m_frame[8] = 0;
	
		
	}


	//Creates an empty label and defaults the frame to "+-+|+-+|"
	Label::Label() {
		setToDefault();
		setFrame("+-+|+-+|");

	}
	//Creates an empty label and sets the frame to the frameArg argument.

	Label::Label(const char* frameArg) {
		setToDefault();
		setFrame(frameArg);
	}

	Label::Label(const char* frameArg, const char* content) {
		setToDefault();
		setFrame(frameArg);
		setLable(content);

	}


	//Makes sure there is no memory leak when the label goes out of scope.
	Label::~Label() {
		delete[] m_label;
		
		m_label = nullptr;
	
	}

	/*Reads the label from console up to 70 characters and stores it in the
		Label as shown in the Execution sample*/
	void Label::readLabel() {//

		char inputLabel[71];
		cin.getline(inputLabel, 71);
		setLable(inputLabel);

	}
	

	


	std::ostream& Label::printLabel() const {//how to get the length?????
		if (m_label && m_frame) { //////////////why this doesnt work????????????????

			int len = (size_t)strlen(m_label) + 3;//inttttttt??????????????????????????????????

			cout << m_frame[0] << setw(len) << setfill(m_frame[1]) << m_frame[2] << endl;                                          //A


			cout << m_frame[7] << setw(len) << setfill(' ') << m_frame[3] << endl;   //h  d

			cout << m_frame[7] << ' ' << m_label << ' ' << m_frame[3] << endl;   //h  d

			cout << m_frame[7] << setw(len) << setfill(' ') << m_frame[3] << endl;   //h  d

			cout << m_frame[6] << setw(len) << setfill(m_frame[5]) << m_frame[4] << endl;                                          //A



			return cout;
		}


	}

}

	















// #define _CRT_SECURE_NO_WARNINGS
// #include <istream>///?????????
// #include <iomanip>//???????//
// #include <iostream>

// #include "Label.h"


// #include <cstring>

// #define SDDS_DEBUG

// using namespace std;
// namespace sdds {

// 	void Label::setLable(const char* theLable) {

// 		delete[] m_label;
// 		m_label = nullptr;
// 		int  maxLen = 70;
// 		int len = (size_t)strlen(theLable) > (size_t)maxLen ? maxLen : strlen(theLable);
// 		m_label = new char[len + 1];           //whyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyyy????????????
// 		strncpy(m_label, theLable, len);
// 		m_label[len] = 0;
// 	}

// 	void Label::setFrame(const char* theFrame) {

// 		strncpy(m_frame, theFrame, 8);
// 		m_frame[8] = 0;

// 	}
		 
// 	//Creates an empty label and defaults the frame to "+-+|+-+|"
// 	Label::Label()	{		                            //m_label = nullptr;??????????????????????????????????????????????????????????

		
// 		m_label = new char[71];/////////////////////////////////////////////////////////////////////////////////////////
// 		strcpy(m_label, "");
		
// 		                                               //when i set m_label to nullptr it stopssssssssssss!!!!!!!!!!!!!!!!!!!
		
// 		setFrame("+-+|+-+|");

// 	}

// 	Label::Label(const char* frameArg)	{

// 		setFrame(frameArg);
		
// 		m_label = new char[71];////////////////////////////////////////////////////////////////////////////////////////
// 		strcpy(m_label, "");
// 	}

// 	Label::Label(const char* frameArg, const char* content)	{

// 		//if (frameArg && content) {
// 			setFrame(frameArg);

// 			setLable(content);

// 		//}
// 	}

// 	Label::~Label()	{
		
// 		delete[] m_label;
// 	}

// 	void Label::readLabel()	{

// 		char inputLabel[71];
// 		cin.getline(inputLabel, 71);
// 		strcpy(m_label, inputLabel);
// 	}


// 	std::ostream& Label::printLabel() const {//how to get the length?????



// 		/*readLabel();
// 		readFrame();*/          //I havnt called these,how come they impact m_label n m_frame????????

		
// 		//if (/*m_label!=nullptr && */m_frame) { //////////////why this doesnt work????????????????

// 			int len = (size_t)strlen(m_label) + 3;//inttttttt??????????????????????????????????

// 			cout << m_frame[0] << setw(len) << setfill(m_frame[1]) << m_frame[2] << endl;                                          //A


// 			cout << m_frame[7] << setw(len) << setfill(' ') << m_frame[3] << endl;   //h  d

// 			cout << m_frame[7] << ' ' << m_label << ' ' << m_frame[3] << endl;   //h  d

// 			cout << m_frame[7] << setw(len) << setfill(' ') << m_frame[3] << endl;   //h  d

// 			cout << m_frame[6] << setw(len) << setfill(m_frame[5]) << m_frame[4] << endl;                                          //A



// 			return cout;
// 		/*}*/
		


// 	}


// }






// 	//void Label::readFrame() {		// ref of obj ? ? ? ? ?
// 	//
// 	//	char inputFrame[9];
// 	//	cin.getline(inputFrame,9);
// 	//	setFrame(inputFrame);
// 	//}

// 	//
// 	////////////////when we call a function without . notation

//  ///why setting to null doesnt work????
// ///why not calling set naem n set frame in display
// /// why we don nee read label?????






