//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.19.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////


#define _CRT_SECURE_NO_WARNINGS

#include <cstdlib>   // for fclose, fopen, File*
#include "File.h"  
namespace sdds {

	
	const char* const SHOPPING_DATA_FILE = "shoppinglist.csv";
	FILE* sfptr = nullptr;




	//openFileForRead
		//openFileForOverwrite
		//closeFile
		//freadShoppingRec
		//fwriteShoppintRec

	
	//bool openFileForRead();
	bool openFileForRead() {
		sfptr = fopen(SHOPPING_DATA_FILE, "r");
		return sfptr != NULL;
	}

	//	bool openFileForOverwrite();
	bool openFileForOverwrite() {
		sfptr = fopen(SHOPPING_DATA_FILE, "w");
		return sfptr != NULL;
	}
	//	void closeFile();
	void closeFile() {
		if (sfptr) fclose(sfptr);
	}
	//	bool freadShoppingRec(ShoppingRec* rec);
	bool freadShoppingRec(ShoppingRec* rec) {
		int flag = 0;
		bool success = fscanf(sfptr, "%[^,],%d,%d\n",
			rec->m_title, &rec->m_quantity, &flag) == 3;
		rec->m_bought = !!flag;
		return success;
	}
	//	void fwriteShoppintRec(const ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec) {
		fprintf(sfptr, "%s,%d,%d\n", rec->m_title, rec->m_quantity, rec->m_bought);
	}
		
}
