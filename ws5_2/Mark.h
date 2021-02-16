
#ifndef SDDS_MARK_H_
#define SDDS_MARK_H_
#include <iostream>//???

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



}

#endif // SDDS_MARK_H_