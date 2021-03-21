//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.20.2021
//I have copied the usage of stringstream from a similar question(line 68)
//https://stackoverflow.com/questions/35974402/reading-getline-from-cin-into-a-stringstream-c
////////////////////////////////////////////////

#define  _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <iomanip>
#include <fstream>
#include <string>
#include <sstream> 
#include "Stats.h"
#include "cstring.h"

using namespace std;
namespace sdds
{

	void Stats::setFilename(const char* fname, bool isCopy) {
		delete[] m_filename;
		m_filename = nullptr;
		if (fname) {
			if (!isCopy) {
				m_filename = new char[strLen(fname) + 1];
				strCpy(m_filename, fname);
			}

			else {
				m_filename = new char[strLen(fname) + 3];//C_
				strCpy(m_filename, "C_");
				strCat(m_filename, fname);

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
			int i = 0;
			while (getline(ss2, num, ','))
			{

				n = stod(num);
				m_arr[i] = n;
				i++;
			}

			
		}
	}

	
	Stats::Stats(const char* filename, unsigned columnWidth, unsigned noOfColumns, unsigned precision) 
		:m_arr(nullptr), m_noOfNums(noOfColumns), m_filename(nullptr),
		m_columnWidth(columnWidth), m_noOfColumns(noOfColumns), m_precision(precision)
	{
		
		if (filename)
		{
			setFilename(filename);
			loadNums();
		}
	}
	
	Stats::Stats(unsigned columnWidth, unsigned noOfColumns, unsigned precision)
		:m_arr(nullptr), m_noOfNums(0), m_filename(nullptr),
		m_columnWidth(columnWidth), m_noOfColumns(noOfColumns), m_precision(precision){}
	
	
	Stats::Stats(const Stats& other) :m_arr(nullptr), m_noOfNums(0),
		m_filename(nullptr), m_columnWidth(0), m_noOfColumns(0), m_precision(0)
	{
		ifstream file(other.m_filename);
		if (other)
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
			m_arr = nullptr;
			delete[] m_filename;
			m_filename=nullptr;
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



	unsigned Stats::size() const
	{
		return m_noOfNums;
	}

	const char* Stats::name() const
	{
		return m_filename;
	}


unsigned Stats::occurrence(double min, double max, std::ostream& ostr)
{
    int Count = 0;
    if (*this)
    {
        ostr << endl << fixed << setprecision(m_precision);
        for (unsigned i = 0; i < m_noOfNums; i++)
        {
            if (m_arr[i] >= min && m_arr[i] <= max)
            {
                ostr << right << setw(m_columnWidth) << m_arr[i];
                if ((Count + 1) % m_noOfColumns == 0)
                    ostr << endl;
				Count++;
            }
        }
        if (Count % m_noOfColumns != 0)
            ostr << endl;
        ostr << "Total of " << Count<< " numbers are between " << min << " and " << max << endl;
    }
    return Count;
}

	double Stats::operator[](unsigned idx) const
	{
		
		double ret = 0;
		if (*this && m_noOfNums > 0)
		{
			ret = m_arr[idx % m_noOfNums];
		}
		return ret;
	}

	double& Stats::operator[](unsigned idx) {
		double* ret = &dummy; 
		if (*this) {
			ret = &m_arr[idx % m_noOfNums];
		}
		return *ret;
	}

	Stats::operator bool() const
	{
		bool ret = true;
		if (m_filename == nullptr || m_noOfNums == 0) 	ret = false;

		else ret = true;
		return ret;
	}
	std::ostream& Stats::view(std::ostream& ostr) const {
		if (*this) {
			ostr << m_filename << endl;
			for (unsigned i = 0; m_filename[i]; i++) ostr << "=";

			bool done = false;
			ostr << endl << endl << fixed << setprecision(m_precision);
			for (unsigned i = 0; i < m_noOfNums; i++)
			{
				ostr << right << setw(m_columnWidth) << m_arr[i];
				done = false;
				if ((i + 1) % m_noOfColumns == 0)
				{
					done = true;
					ostr << endl;
				}
			}
			if (!done)			ostr << endl;

			ostr << "Total of " << m_noOfNums << " listed!" << endl;


		}
		
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
		return text.view(ostr);
	}
}