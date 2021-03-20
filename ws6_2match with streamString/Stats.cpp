#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include "cstring.h"


#include <cstring>

#include "Stats.h"
#include <string>
#include <sstream> 

using namespace std;
namespace sdds
{

	void Stats::setFilename(const char* fname, bool isCopy) {
		delete[] m_filename;
		m_filename = nullptr;
		if (fname) {
			if (!isCopy) {
				m_filename = new char[strlen(fname) + 1];
				strcpy(m_filename, fname);
			}

			else {
				m_filename = new char[strlen(fname) + 3];//C_
				strcpy(m_filename, "C_");
				strcat(m_filename, fname);

			}


		}


	}


	void Stats::saveAs(const char* fileName) const
	{
		ofstream fout(fileName);
		ifstream fin(m_filename);
		string line;
		while (getline(fin, line))
		{
			fout << line;
		}
		fin.close();
		fout.close();
	}

	void Stats::loadNums() {
		m_noOfNums = 0;
		ifstream file(m_filename);
		if (file.good())
		{
			string line;
			getline(file, line);
		
			double n;
			string num;
		

			
			ifstream f(m_filename);
		    while (getline(f, num, ',')) ++m_noOfNums;
			




			
			m_arr = new double[m_noOfNums];
			stringstream ss2(line);
			int idx = 0;
			while (getline(ss2, num, ','))
			{


				n = stod(num);
				m_arr[idx] = n;
				idx++;
			}
		



			//file.close();
		}
	}

	
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) :m_arr(nullptr), m_noOfNums(0), m_filename(nullptr), m_columnWidth(0), m_noOfColumns(0), m_precision(0)
	{
		/*Same as the previous constructor, but in this case, if the filename argument is not
		null and is successfully opened, the numbers in the file will be loaded into the
		Stats object.*/
		m_noOfNums = 0;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
		m_filename = nullptr;
		m_arr = nullptr;
		if (filename != nullptr)
		{
			setFilename(filename);
			loadNums();
		}
	}
	
	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision) :m_arr(nullptr), m_noOfNums(0), m_filename(nullptr), m_columnWidth(0), m_noOfColumns(0), m_precision(0)
	{
		//In this case, the "Stats" object is not tied to any file on the hard drive and is empty
		m_noOfNums = 0;
		m_filename = nullptr;
		m_columnWidth = columnWidth;
		m_noOfColumns = noOfColumns;
		m_precision = precision;
		m_arr = nullptr;
	}
	
	Stats::Stats(const Stats& other) :m_arr(nullptr), m_noOfNums(0), m_filename(nullptr), m_columnWidth(0), m_noOfColumns(0), m_precision(0)
	{
		ifstream file(other.m_filename);
		if (/*file.good()*/other)
		{
			m_noOfColumns = other.m_noOfColumns;
			m_precision = other.m_precision;
			m_columnWidth = other.m_columnWidth;
			setFilename(other.m_filename, true);
			other.saveAs(m_filename);
			loadNums();
		}
	}

	Stats::~Stats()
	{
		
			delete[] m_arr;
			delete[] m_filename;
	}

	Stats& Stats::operator=(Stats& other)
	{
		
		if (this != &other && m_filename && other.m_filename)
		{
			m_noOfColumns = other.m_noOfColumns;
			m_precision = other.m_precision;
			m_columnWidth = other.m_columnWidth;
			other.saveAs(m_filename);
			delete[] m_arr;
			m_arr = nullptr;
			m_noOfNums = 0;
			other.m_noOfNums = 0;
			loadNums();
		}
		return *this;
	}

	void Stats::sort(bool ascending)
	{
		int i, j;
		int n = m_noOfNums;
		for (i = 0; i < n - 1; i++)
		{
			for (j = 0; j < n - i - 1; j++)
			{
				if ((ascending && m_arr[j] > m_arr[j + 1]) ||
					(!ascending && m_arr[j] < m_arr[j + 1]))
				{
					double temp = m_arr[j];
					m_arr[j] = m_arr[j + 1];
					m_arr[j + 1] = temp;
				}
			}
		}

	}
//it throws error


	/*void Stats::sort(bool ascending) {
		unsigned int i, j;
		double temp;
		if (ascending == true) {

			for (i = m_noOfNums - 1; i > 0; i--) {
				for (j = 0; j < i; j++) {
					if (m_arr[j] > m_arr[j + 1]) {
						temp = m_arr[j];
						m_arr[j] = m_arr[j + 1];
						m_arr[j + 1] = temp;
					}
				}

			}
		}

		else {

			for (i = 0; i < m_noOfNums; ++i) {
				for (j = i + 1; j < m_noOfNums; ++j) {
					if (m_arr[i] < m_arr[j]) {
						temp = m_arr[i];
						m_arr[i] = m_arr[j];
						m_arr[j] = temp;
					}
				}
			}
		}
	}
*/


	unsigned Stats::size() const
	{
	//	returns the number of numbers in the Stats object
		return m_noOfNums;
	}

	const char* Stats::name() const
	{
		//returns the name of the file tied to the Stats object.
		return m_filename;
	}


	//this works tooooooooooooooooooooooooooooooooooo






	//unsigned Stats::occurrence(double min, double max, std::ostream& ostr)	{
	//	 
	//	unsigned count = 0;
	//	if (*this)
	//	{
	//		
	//		ostr << endl << fixed << setprecision(m_precision);




	//		bool check = false;
	//		for (int i = 0; i < m_noOfNums; i++)// for the numbers
	//		{
	//			if (m_arr[i] >= min && m_arr[i] <= max)   //if they r un range
	//			{
	//				check = false;
	//				ostr << right << setw(m_columnWidth) << m_arr[i];
	//				if ((count + 1) % m_noOfColumns == 0) //when we hit the number of numbers that make a column
	//				{
	//					check = true;
	//					ostr << endl;  
	//				}
	//				count++;
	//			}
	//		}
	//		if (!check)  ostr << endl;
	//			



	//		ostr << "Total of " << count << " numbers are between " << min << " and " << max << endl;
	//	}
	//	return count;
	//}



	//this is better tho




unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
{
    int Counter = 0;
    if (m_filename)
    {
        ostr << endl << fixed << setprecision(m_precision);
        for (int i = 0; i < m_noOfNums; i++)
        {
            if (m_arr[i] >= min && m_arr[i] <= max)
            {
                ostr << right << setw(m_columnWidth) << m_arr[i];
                if ((Counter + 1) % m_noOfColumns == 0)
                    ostr << endl;
                Counter++;
            }
        }
        if (Counter % m_noOfColumns != 0)
            ostr << endl;
        ostr << "Total of " << Counter << " numbers are between " << min << " and " << max << endl;
    }
    return Counter;
}








	double Stats::operator[](unsigned idx) const
	{
		/*Returns the value of the number at idx index.If the index exceeds the size of the
		array, it should loop back to the beginning.For example, if the array size is 10,
		index 10 will be the value of the element at index 0 and index 11 will be the value
		of the element at index 1.
		If the Stats object is empty, it should return zero*/
		double ret = 0;
		if (*this && m_noOfNums > 0)
		{
			ret = m_arr[idx % m_noOfNums];
		}
		return ret;
	}



	double& Stats::operator[](unsigned idx) {
		//If the Stats object is empty, it should return the reference of a dummy double member variable.
		double* ret = &dummy; //here we cant use reference as we cant chnge the reference and set it to 2 different values so we have to use pointer
		if (*this) {
			ret = &m_arr[idx % m_noOfNums];
		}
		return *ret;//???
	}










	Stats::operator bool() const
	{
		if (m_filename == nullptr || m_noOfNums == 0)
		{
			return false;
		}
		return true;
	}
	std::ostream& Stats::view(std::ostream& ostr) const {
		if (m_arr == nullptr || m_filename == nullptr || m_noOfNums == 0)
		{
			return ostr;
		}
		ostr << m_filename << endl;
		for (int i = 0; m_filename[i] != '\0'; i++)
		{
			ostr << "=";
		}
		bool check = false;
		ostr << endl << endl;
		ostr << fixed << setprecision(m_precision);
		for (int i = 0; i < m_noOfNums; i++)
		{
			ostr << right << setw(m_columnWidth) << m_arr[i];
			check = false;
			if ((i + 1) % m_noOfColumns == 0)
			{
				check = true;
				ostr << endl;
			}
		}
		if (!check)
			ostr << endl;
		ostr << "Total of " << m_noOfNums << " listed!" << endl;
		return ostr;
	}

	std::istream& Stats::getFile(std::istream& istr)
	{
		string temp;
		getline(istr, temp);
		setFilename(temp.c_str());
		loadNums();
		return istr;
	}

	std::istream& operator>>(std::istream& istr, Stats& text)
	{
		return text.getFile(istr);
	}

	std::ostream& operator<<(std::ostream& ostr, const Stats& text)
	{
		text.view(ostr);
		return ostr;
	}
}