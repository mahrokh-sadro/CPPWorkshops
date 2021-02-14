#define _CRT_SECURE_NO_WARNINGS
#include <iostream>///?????????
#include <iomanip>//???????//


#include "LabelMaker.h"


#include <cstring>

#define SDDS_DEBUG

using namespace std;
namespace sdds {

	void LabelMaker::setEmpty() {
		m_labels = nullptr;
	}


	//creates a dynamic array of Labels to the size of noOfLabels
	LabelMaker::LabelMaker(int noOfLabels) {
		if (noOfLabels > 0) {
			delete[] m_labels;
			m_labels = nullptr;
			m_noOfLabels = noOfLabels;
			m_labels = new Label[m_noOfLabels];
			/*int i(0);
			for(i=0; i< m_noOfLabels; i++)   m_labels[i].setToDefault();*/
		}
		//else setEmpty();
	}




	//Gets the contents of the Labels as demonstrated in the Execution sample
	void LabelMaker::readLabels() {
		cout << "Enter " << m_noOfLabels << " labels:" << endl;

		int i(0);
		for (i = 0; i < m_noOfLabels; i++) {

			cout << "Enter label number " << i + 1 << " " <<endl;
			cout << "> ";
			m_labels[i].readLabel();
		}
	}
	// Prints the Labels as demonstrated in the Execution sample
	void LabelMaker::printLabels() {

		int i(0);
		for (i = 0; i < m_noOfLabels; i++) {
			m_labels[i].printLabel();
		}

	}
	//Deallocates the memory when LabelMaker goes out of scope.
	LabelMaker::~LabelMaker() {


		delete[] m_labels;  
		setEmpty();

	}

}
