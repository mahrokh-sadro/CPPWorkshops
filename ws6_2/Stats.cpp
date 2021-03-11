#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <fstream>
#include <string>

#include <cstring>
#include "Stats.h"
using namespace std;

namespace sdds {

	Line::operator double () const {
		return (double)m_value;
	}







	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision):m_columnWidth(columnWidth),
		m_noOfColumns(noOfColumns),
		m_precision{ 2 } {}

	
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision):
		m_filename{ nullptr },
		m_columnWidth(columnWidth),
		m_noOfColumns(noOfColumns),
		m_precision{2}
	{
		if (filename) {
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
	    }
		
	}

	

	

	void Stats::setNoOfLines() {

		ifstream f(m_filename);
		m_noOfLines = 0;
		string line;
		if (f.is_open()) {
			while (getline(f, line)) {
				++m_noOfLines;

			}
			++m_noOfLines;
		}
		if (m_noOfLines == 0) {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}


	//copy constructor
	/*Copying a Stats object should be done safely
	and doing so it
		should also copy the data file on the hard disk
		.The new
		file name should be the same as the original
		file with
		an added "C_" prefix.*/

	void Stats::loadText() {
		if (m_filename) {
			int i(0);

			delete[] m_textLines;
			m_textLines = nullptr;
			m_textLines = new Line[m_noOfLines];
			string temp;
			ifstream f(m_filename);

			while (getline(f, temp)) {

				m_textLines[i] = temp.c_str();
				i++;
			}
			m_noOfLines = i;

		}
	}
	
	void Stats::saveAs(const char* fileName) const {
		ofstream f(fileName);//open a new file
		unsigned i(0);
		if (f.is_open()) {// r we supposed to check this?/
			for (i = 0; i < m_noOfNumbers; i++)  f << m_textNumbers[i];

		}

	}




	Stats::Stats(const Stats& obj)
		:m_columnWidth{15} ,
		m_noOfColumns{4},
		m_precision{ 2 }{ 
		
		
		m_filename = new char[strlen(obj.m_filename) + 3];//C_
		strcpy(m_filename, "C_");
		strcat(m_filename, obj.m_filename);
		loadText();
	
	
	
	}



	//copy assignment
	/*Copy assignment

		Assigning a Stats object to another
		should be done safelyand the content
		of the target file should also be
		overwritten by the content of the
		source file.*/

	Stats& Stats::operator=(const Stats& copyFrom){
		if (this != &copyFrom) {
			// shallow copy non-resource variables
			m_columnWidth = copyFrom.m_columnWidth;
			m_columnWidth = copyFrom.m_noOfColumns;
			// deallocate previously allocated dynamic memory 
			delete[] m_filename;
			m_filename = nullptr;
			// allocate new dynamic memory, if needed
			m_filename = new char[strlen(copyFrom.m_filename) + 1];
			strcpy(m_filename, copyFrom.m_filename);
		}
		return *this;
	}

	/*Returns the reference of the number at idx 
		index.If the index exceeds the size of 
		the array, it should loop back to the
		beginning.For example, if the array 
		size is 10, index 10 will be the reference 
		of the element at index 0 and index 11
		will be the reference of the element at 
		index 1.

		If the Stats object is empty, it should
		return the reference of a dummy double 
		member variable.*/


	double& Stats::operator[](unsigned idx){
		double ret =0.00;//If the Stats object is empty, it should return the reference of a dummy double member variable.
		if (*this) {
			ret = m_textNumbers[idx % m_noOfNumbers].m_value;
		}
		return ret;////////////////////////////////////////


	}
	/*Returns the value of the number at idx 
		index.If the index exceeds the size
		of the array, it should loop back 
		to the beginning.For example, if 
		the array size is 10, index 10 
		will be the value of the element 
		at index 0 and index 11 will be the 
		value of the element at index 1.

		If the Stats object is empty, it should
		return zero.*/


	double Stats::operator[](unsigned idx) const{
		double ret = 0.00;//If the Stats object is empty, it should return the reference of a dummy double member variable.
		if (*this) {
			ret = m_textNumbers[idx % m_noOfNumbers].m_value;
		}
		return ret;
	}

	/*If Stats is casted to boolean, it should
		return true only if it is not empty.Otherwise,
		it should return false.*/

	Stats::operator bool() const	{
		return (m_filename != nullptr);
	}

	//Sorts the numbers in ascending or descending order.

	void Stats::sort(bool ascending)	{

	}


	//returns the number of numbers in the Stats object.
	unsigned Stats::size() const{
		return m_noOfNumbers;
	}

	//returns the name of the file tied to the Stats object.
	const char* Stats::name() const{

		return (const char*) m_filename;
	}

	/*displays the numbers that fall within a 
		specific rangeand the number of their
		occurrence on ostream.

		The format of the printout should be
		the same as printing all the numbers.*/
	unsigned Stats::occurrence(double min, double max, std::ostream& ostr)	{
		return 0;
	}



	std::ostream& operator<<(std::ostream& os, const Stats& obj){
		// TODO: insert return statement here
	}



	std::istream& operator>>(std::istream& is, const Stats& obj)	{
		// TODO: insert return statement here
	}
}