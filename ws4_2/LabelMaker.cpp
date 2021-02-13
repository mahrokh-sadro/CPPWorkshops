#define _CRT_SECURE_NO_WARNINGS
#include <istream>///?????????
#include <iomanip>//???????//


#include "LabelMaker.h"


#include <cstring>

#define SDDS_DEBUG

using namespace std;
namespace sdds {

	void LabelMaker::setEmpty()	{
		m_labels = nullptr;
	}
	//creates a dynamic array of Labels to the size of noOfLabels
	LabelMaker::LabelMaker(int noOfLabels)	{
		if(noOfLabels>0){ 

			m_noOfLabels = noOfLabels;
			m_labels = new Label[m_noOfLabels];   
			int i(0);
			for(i=0; i< m_noOfLabels; i++)   m_labels[i].setToDefault();
		}
		else setEmpty();
	}


	//If the number of added Items(m_itemsAdded) is less than the length of the m_items array, this
	//	function will set the next available subject to the incoming argument values.Then it will add 
	//	one to the m_itemsAddedand return true;

	//Otherwise, this function will do nothing, returning false;

	//Gets the contents of the Labels as demonstrated in the Execution sample
	void LabelMaker::readLabels()	{

		int i(0);
		for (i = 0; i < m_noOfLabels; i++)  m_labels[i].readLabel();

	}
	// Prints the Labels as demonstrated in the Execution sample
	void LabelMaker::printLabels()	{

		int i(0);
		for (i = 0; i < m_noOfLabels; i++)  m_labels[i].readLabel();

	}
	//Deallocates the memory when LabelMaker goes out of scope.
	LabelMaker::~LabelMaker()	{
		delete[] m_labels;
			setEmpty();
	}

}