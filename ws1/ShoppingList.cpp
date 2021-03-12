//Name: Mahrokh Sadrolodabaee
//Seneca email: msadrolodabaee@myseneca.ca
//Seneca Student ID: 159436195
//Date: 1.19.2021
//I have done all the coding by myselfand only copied the code that my professor
//provided to complete my workshopsand assignments.
////////////////////////////////////////////////
#include <iostream> //for cout
using namespace std;//we use it when we have c++ library stuff
#include "ShoppingList.h"
#include "ShoppingRec.h" // for ShoppingRec recs[MAX_NO_OF_RECS] = {};
#include "File.h"  //for openFileForRead, freadShoppingRec, closeFile
#include "Utils.h"   //for yes, readInt, 
#include "ShoppingRec.h" //for getShoppingRec
namespace sdds {

	
	const int MAX_NO_OF_RECS = 15;
	ShoppingRec recs[MAX_NO_OF_RECS] = {}; ///whats this? like struct arr????????????
	int noOfRecs = 0;

	//loadList
	//	displayList
	//	removeBoughtItems
	//	removeItem
	//	saveList
	//	clearList
	//	toggleBought
	//	addItemToList
	//	removeItemfromList
	//	listIsEmpty



	//bool loadList();
	bool loadList() {
		ShoppingRec shpr = {};
		bool ok = false;
		if (openFileForRead()) {
			ok = true;
			while (noOfRecs < MAX_NO_OF_RECS &&
				freadShoppingRec(&shpr)) {
				recs[noOfRecs++] = shpr;
			}
			closeFile();
		}
		return ok;
	}


	//void displayList();
	void displayList() {
		for (int i = 0; i < noOfRecs; i++) {
			cout << (i + 1) << "-";
			displayShoppingRec(&recs[i]);
		}

	}
	//void removeBoughtItems();
	void removeBoughtItems() {
		if (!listIsEmpty()) {
			cout << "Removing bought items, are you sure?" << endl;
			cout << "(Y)es/(N)o: ";
			if (yes()) {
				for (int i = 0; i < noOfRecs; i++) {
					if (recs[i].m_bought) removeItem(i--);
				}
			}
			else {
				cout << "Cancelled!" << endl;
			}
		}
		else {
			cout << "List is empty!" << endl;
		}
	}

	//void removeItem(int index);
	void removeItem(int index) {
		if (index > 0 && index < noOfRecs) {
			noOfRecs--;
			for (int i = index; i < noOfRecs; i++) {
				recs[i] = recs[i + 1];
			}
		}
	}

	//bool saveList();
	bool saveList() {
		bool ok = false;
		if (openFileForOverwrite()) {
			ok = true;
			for (int i = 0; i < noOfRecs; i++) {
				fwriteShoppintRec(&recs[i]);
			}
			closeFile();
		}
		return ok;
	}

	//void clearList();
	void clearList() {
		cout << "This will remove all the items from the list;" << endl
			<< "Are you sure? (Y)es/(N)o" << endl;
		if (yes()) {
			noOfRecs = 0;
		}
		else {
			cout << "Cancelled!" << endl;
		}
	}

	//void toggleBought();
	void toggleBought() {
		cout << "Item number: ";
		toggleBoughtFlag(&recs[readInt(1, noOfRecs) - 1]);
	}

	//void addItemToList();
	void addItemToList() {
		if (noOfRecs < MAX_NO_OF_RECS) {
			recs[noOfRecs] = getShoppingRec();
			noOfRecs += !isShoppingRecEmpty(&recs[noOfRecs]);
		}
		else {
			cout << "Shopping List is full!" << endl;
		}
	}

	//void removeItemfromList();
	void removeItemfromList() {
		if (!listIsEmpty()) {
			int value = 0;
			cout << "Item number to delete: ";
			value = readInt(1, noOfRecs);
			cout << "Deleting following item, are you sure?" << endl;
			displayShoppingRec(&recs[value - 1]);
			cout << "(Y)es/(N)o: ";
			if (yes()) {
				removeItem(value - 1);
			}
			else {
				cout << "Cancelled!" << endl;
			}
		}
		else {
			cout << "List is empty!" << endl;
		}

	}

	//bool listIsEmpty();
	bool listIsEmpty() {
		return noOfRecs == 0;
	}


}