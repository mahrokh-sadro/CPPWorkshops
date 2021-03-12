//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.28.2021
//I have done all the coding by myselfand only copied the code that my professor provided to 
//complete my workshopsand assignments.
////////////////////////////////////////////////
#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
	struct Employee {
		char* m_name;
		int m_empNo;
		double m_salary;
	};
	
	void sort();
	
	bool load(Employee& emp);
	
	bool load();

	
	void display(const Employee& emp);

	void display();

	void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_