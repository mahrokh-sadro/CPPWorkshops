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
				//getignore?????????????????????????????????????????????
				m_textNumbers[i].m_value = temp;//???????????????????????????????????????????????????????????????????????????????????????
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
		return ret;//????????????????????????????????????????????????????????????????????????????????????????????????????


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

	



	void Stats::sort(bool ascending)	{
		int i, j;
		Line temp;
		for (i = m_noOfNumbers - 1; i > 0; i--) {
			for (j = 0; j < i; j++) {
				if (m_textNumbers[j].m_value > m_textNumbers[j + 1].m_value) {
					temp = m_textNumbers[j];
					m_textNumbers[j].m_value = m_textNumbers[j+1].m_value;
					m_textNumbers[j + 1].m_value=temp;
				}
			}

		}
	}


	
	unsigned Stats::size() const{
		return m_noOfNumbers;
	}

	
	const char* Stats::name() const{

		return (const char*) m_filename;
	}

	/*displays the numbers that fall within a 
		specific rangeand the number of their
		occurrence on ostream.

		The format of the printout should be
		the same as printing all the numbers.*/
	unsigned Stats::occurrence(double min, double max, std::ostream& ostr)	{
		//each obj m_textNumbers[i].m_value

		unsigned i(0);
		unsigned count(0);
		for (i = 0; m_textNumbers[i]; i++) {
			if (m_textNumbers[i].m_value >= min && m_textNumbers[i].m_value <= max)  ++count;				
		}
		return count;
	}
	std::ostream& Stats::view(std::ostream& ostr) const {
		if (*this) {
			ostr << m_filename << endl;
			for (int i = 0; m_filename[i]; i++) ostr << "=";
			ostr << endl;
			for (unsigned i = 0; i < m_noOfNumbers; i++) {
				ostr << m_textNumbers;
			}

		}
		return ostr;

	}

	



	/*Stats should be printable by ostream(cout) using the operator<<.

		A Stats object should be able to display the numbers in a 
		tabular format on ostream in a specified number of columns,
		column width and precision.See the execution sample file.*/

	std::ostream& operator<<(std::ostream& os, const Stats& obj){

		return obj.view(os);
	}
	void Stats::setFilename(const char* fname) {
		delete[] m_filename;
		m_filename = nullptr;
		if (fname) {
			m_filename = new char[strlen(fname) + 1];
			strcpy(m_filename, fname);

		}

	}

	std::istream& Stats::getFile(std::istream& istr){
		string temp;
		getline(istr, temp);
		setFilename(temp.c_str());
		setNoOfNumbers();
		loadText();
		return istr;

	}
	/*istream extraction operator>>

		Stats object should be able to receive the data file
		name from ostream(cin) using operator>>.After receiving
		the name, if the data file is open successfully, the 
		numbers should be loaded into the Stats object.*/

	std::istream& operator>>(std::istream& is,  Stats& obj)	{
		return obj.getFile(is);
	}
}