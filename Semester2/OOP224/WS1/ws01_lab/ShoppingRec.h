/* -------------------------------------------
I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.

Name: SANGHWA SUH
Student number: 100711209
Email: ssuh6@myseneca.ca
Section: WS01_LAB
Date: 2021/01/20

----------------------------------------------
---------------------------------------------- */


#ifndef SHOPPINGREC_H // replace with relevant names
#define SHOPPINGREC_H
// Your header file content goes here

namespace sdds
{

    const int MAX_TITLE_LENGTH = 50;
    const int MAX_QUANTITY_VALUE = 50;
    struct ShoppingRec
    {
        char m_title[MAX_TITLE_LENGTH + 1];
        int m_quantity;
        bool m_bought;
    };

    ShoppingRec getShoppingRec();
    void displayShoppingRec(const ShoppingRec* shp);
    void toggleBoughtFlag(ShoppingRec* rec);
    bool isShoppingRecEmpty(const ShoppingRec* shp);
}
#endif
