#ifndef SHOPPING_MALL_MANAGEMENT_SYSTEM_ITEM_H
#define SHOPPING_MALL_MANAGEMENT_SYSTEM_ITEM_H

#include <fstream>
#include <iostream>
#include <conio.h>
#include <time.h>

//****************************************************************************
// CLASS NAME : item
// DETAILS : IT CONTROLLS OVER ALL THE FUNCTIONS
// RELATED TO ITEMS
//****************************************************************************

class item {
public :
    void add_item() ;
    void delete_item() ;
    void modify_item() ;
    void list_of_item() ;
    void purchase() ;
private :
    int last_code() ;
    void delete_record(int) ;
    void modify_record(int) ;
    void display_record(int) ;
    int item_found(int) ;
    int recordno(int) ;
    static void sort() ;
    int itemcode ;
    char itemname[30] ;
    float itemprice ;
};


#endif //SHOPPING_MALL_MANAGEMENT_SYSTEM_ITEM_H
