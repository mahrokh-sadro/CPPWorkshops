//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.31.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {

	bool openFile(const char filename[]);

	void closeFile();

	int noOfRecords();

	//to do
	bool read(char m_postalcode[4]);  //char* m_postalcode also works 
	bool read(int& m_population);

}
#endif // !SDDS_FILE_H_
