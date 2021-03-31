//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 03.31.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
#include "Collection.h"
namespace sdds {

	template <typename T, typename Z>
	bool search(Collection<T>& obj,
		T arr[],
		unsigned size,
		Z match)
	{
		int count(0);
		for (unsigned i = 0; i < size; i++)
		{
			if (arr[i] == match)
			{
				obj.add(arr[i]);
				count++;
			}
		}
		return count;
	}

	template <typename T>
	 void listArrayElements(const char* title,
		const T arr[],
		unsigned size)
	{
		std::cout << title << std::endl;
		for (unsigned i = 0; i < size; i++) std::cout << i + 1 << ": " << arr[i] << std::endl;
	}

}



