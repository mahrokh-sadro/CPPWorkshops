#include "cstring.h"
namespace sdds {
	void strnCpy(char* des, const char* src, int len) {
		int i(0);
		for (i = 0; src[i] && i < len; i++) des[i] = src[i];
		if (i != len) des[i] = 0;

	}
	int strLen(const char* s)	{
		unsigned count = 0;
		for (unsigned i = 0; s[i]; i++) ++count;
		return count;
	}
	int strCmp(const char* s1, const char* s2)	{
		
		for (int i = 0; s2[i]; i++) {
			return s1[i] == s2[i] ? 0 : s1[i] - s2[i];
		}

		return 0;
	}
}