//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.22.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////

#ifndef SDDS_LBLSHAPE_H_
#define SDDS_LBLSHAPE_H_

#include "Shape.h"
namespace sdds {
	class LblShape :public Shape {
		
		char* m_label;
		void setLabel(const char*);//mine
	protected:
		const char* label() const;
	public:
		LblShape();
		LblShape(const char* label);
		virtual ~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&)=delete;
		std::istream& getSpecs(std::istream& is=std::cin);

	};
		
}
#endif
