//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.14.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#define _CRT_SECURE_NO_WARNINGS
//#include <istream> // this is used for the input stream functions
#include <iomanip> // this is used for display formatting functions
#include <iostream>
#include "Label.h"
#include <cstring>
//#define SDDS_DEBUG
using namespace std;

namespace sdds
{
    void Label::setToDefault()
    {
        m_label = nullptr;
        m_frame[0] = 0;
    }

    void Label::setLable(const char* theLable)
    {
          delete[] m_label;
		m_label = nullptr;
		
		int len = (size_t)strlen(theLable) > 70 ? 70 : strlen(theLable);
		m_label = new char[len + 1];           //whyyyyyyyyyyyyyyyyyy it throws arithmetic overflow error??????????
		strncpy(m_label, theLable, len);
		m_label[len] = 0;

           }

    void Label::setFrame(const char* theFrame)
    {
        //m_frame[0] = 0;
        strcpy(m_frame, theFrame);
        m_frame[8] = 0;
    }

    //Creates an empty label and defaults the frame to "+-+|+-+|"
    Label::Label()
    {
        setToDefault();
        setFrame("+-+|+-+|");
    }

    //Creates an empty label and sets the frame to the frameArg argument.
    Label::Label(const char* frameArg)
    {
        setToDefault();
        setFrame(frameArg);
    }

    Label::Label(const char* frameArg, const char* content)
    {
        setToDefault();
        setFrame(frameArg);
        setLable(content);
    }

    //Makes sure there is no memory leak when the label goes out of scope.
    Label::~Label()
    {
        delete[] m_label;
        m_label = nullptr;
    }

    // Reads the label from console up to 70 characters and 
    // stores it in the Label as shown in the Execution sample
    void Label::readLabel()
    {
        char inputLabel[71];
        cin.getline(inputLabel, 71);
        setLable(inputLabel);
    }

    std::ostream& Label::printLabel() const
    {
        
        if (m_label)
        {
                  int len = (size_t)strlen(m_label) + 3;   //still throws warning for type conversion!
           
            cout << m_frame[0] << setw(len) << setfill(m_frame[1]) << m_frame[2] << endl; //A
            cout << m_frame[7] << setw(len) << setfill(' ') << m_frame[3] << endl;     //h d
            cout << m_frame[7] << ' ' << m_label << ' ' << m_frame[3] << endl;        //h d
            cout << m_frame[7] << setw(len) << setfill(' ') << m_frame[3] << endl;      //h d
            cout << m_frame[6] << setw(len) << setfill(m_frame[5]) << m_frame[4];         //A                       
        }
        return cout;
    }
}