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

	void Stats:: setEmpty(){
		delete[] m_filename;
		m_filename=nullptr;
		delete[] m_textNumbers;
		m_textNumbers=nullptr;
		m_columnWidth=15;
		m_noOfColumns=4;
		m_precision=2;
	
	}
		
	





	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
		:m_filename{ nullptr },
		m_textNumbers{ nullptr },
		m_columnWidth(columnWidth),
		m_noOfColumns(noOfColumns),
		m_precision{ 2 } {}

	
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision):
		m_filename{ nullptr },
		m_textNumbers{ nullptr },
		m_columnWidth(columnWidth),
		m_noOfColumns(noOfColumns),
		m_precision{2}
	{
		if (filename) {
			m_filename = new char[strlen(filename) + 1];
			strcpy(m_filename, filename);
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


	Stats::Stats(const Stats& obj)
		:m_filename{ nullptr },
		m_textNumbers{nullptr},
		m_columnWidth{ 15 },
		m_noOfColumns{ 4 },
		m_precision{ 2 }{

		if (obj) {

			m_filename = new char[strlen(obj.m_filename) + 3];//C_
			strcpy(m_filename, "C_");
			strcat(m_filename, obj.m_filename);

			obj.saveAs(m_filename);
			setNoOfNumbers();
			loadText();

		}
	}

	//copy assignment
	/*Copy assignment

		Assigning a Stats object to another
		should be done safelyand the content
		of the target file should also be
		overwritten by the content of the
		source file.*/

	Stats& Stats::operator=(const Stats& obj) {
		if (this != &obj && m_filename && obj.m_filename) {
			// shallow copy non-resource variables
			m_columnWidth = obj.m_columnWidth;
			m_columnWidth = obj.m_noOfColumns;

			delete[] m_textNumbers;
			m_textNumbers = nullptr;

			obj.saveAs(m_filename);
			setNoOfNumbers();
			loadText();
		}
		return *this;
	}



	

	void Stats::setNoOfNumbers() {

		ifstream f(m_filename);
		int m_noOfNumbers = 0;
		string num;
		if (f.is_open()) {
			while (getline(f,num,' ')) ++m_noOfNumbers;	
		}
		if (m_noOfNumbers == 0) {
			delete[] m_filename;
			m_filename = nullptr;
		}
	}


	

	void Stats::loadText() {
		if (m_filename) {
			int i(0);

			delete[] m_textNumbers;
			m_textNumbers = nullptr;
			m_textNumbers = new Line[m_noOfNumbers];
			//string temp;
			double temp;
			ifstream f(m_filename);

			while (f>> temp) {//extraction operator

				m_textNumbers[i] = temp;/////////////////////////////////??????????????????????????????????????????????????????????
				i++;
			}
			m_noOfNumbers = i;

		}
	}
	
	void Stats::saveAs(const char* fileName) const {
		ofstream f(fileName);//open a new file
		unsigned i(0);
		if (f.is_open()) {
			for (i = 0; /*i < m_noOfNumbers*/m_textNumbers[i]; i++)  f << m_textNumbers[i];

		}

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
		double dummy =0.00;//If the Stats object is empty, it should return the reference of a dummy double member variable.
		double& ret = dummy;
		if (*this) {
			ret = m_textNumbers[idx % m_noOfNumbers].m_value;
		}
		return ret;////////////////////////////////////////???????????????????????????????????????????????????????????????????


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
		double ret = 0.00;
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