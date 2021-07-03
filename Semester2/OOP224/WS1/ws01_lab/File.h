/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS01_LAB
Date: 2021/01/20

----------------------------------------------
---------------------------------------------- */


#ifndef FILE_H // replace with relevant names
#define FILE_H

// Your header file content goes here

namespace sdds
{
	struct ShoppingRec;

	bool openFileForRead();
	bool openFileForOverwrite();
	void closeFile();
	bool freadShoppingRec(ShoppingRec* rec);
	void fwriteShoppintRec(const ShoppingRec* rec);
}
#endif
