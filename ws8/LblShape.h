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
		~LblShape();
		LblShape(const LblShape&) = delete;
		LblShape& operator=(const LblShape&)=delete;
		/*virtual*/ std::istream& getSpecs(std::istream& is=std::cin);



	};
		


}
#endif