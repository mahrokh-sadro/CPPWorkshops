//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.28.2021
//I have done all the coding by myselfand only copied the code that my professor provided to 
//complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
	bool openFile(const char filename[]);
	void closeFile();
	int noOfRecords();
	// TODO: Declare read prototypes
	bool read(char* name);
	bool read(int& m_empNo);
	bool read(double& m_salary);

}
#endif 