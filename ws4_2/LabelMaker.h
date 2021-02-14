#ifndef SDDS_LABELMAKER_H
#define SDDS_LABELMAKER_H
#include <iostream>

#include "Label.h"
//The LabelMaker class creates a dynamic array of 
//Labels and gets their content from the user one by
//oneand prints them all at once.


namespace sdds {
	class LabelMaker {
         
		Label* m_labels;//   diffrent objs       dif labels
		int m_noOfLabels;//number of labels   dma
		void setEmpty();
	public:
		LabelMaker(int noOfLabels);
		void readLabels();
		void printLabels();
		~LabelMaker();
		
	};

}

#endif // !SDDS_BOX_H