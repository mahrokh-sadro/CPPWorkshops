//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 02.21.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_


namespace sdds {
	class Mark {
		int m_value;
		void setEmpty(); //invalid empty state
	public:
		Mark();
		Mark(int value);
		//~Mark();
		operator bool() const; //mine         is the value in range??
		operator int()const;
		Mark& operator+=(int value);
		Mark& operator=(int value);
		operator double()const;
		operator char()const;

	};

                int operator+=(int& leftOper, const Mark& rightOper);


}

#endif // SDDS_MARK_H_