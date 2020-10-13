#ifndef SHOPPING_MALL_MANAGEMENT_SYSTEM_ACCOUNT_H
#define SHOPPING_MALL_MANAGEMENT_SYSTEM_ACCOUNT_H
#include <fstream>
#include <iostream>
#include <conio.h>
#include <time.h>

class account {
public :
    void bill_list() ;
    void prepare_bill(int) ;
    int last_billno() ;
    void add_bill(int t_billno, int t_itemcode, char *t_itemname,float t_qty, float t_price) ;

private :
    int code, billno;
    int dd, mm, yy ;
    float price, quantity ;
    char name[30] ;
};

#endif