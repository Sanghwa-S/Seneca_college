/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS01_LAB
Date: 2021/01/20

----------------------------------------------
---------------------------------------------- */


#ifndef SHOPPINGLIST_H // replace with relevant names
#define SHOPPINGLIST_H

// Your header file content goes here
namespace sdds
{
	bool loadList();
	void displayList();
	void removeBoughtItems();
	void removeItem(int index);
	bool saveList();
	void clearList();
	void toggleBought();
	void addItemToList();
	void removeItemfromList();
	bool listIsEmpty();
}

#endif
