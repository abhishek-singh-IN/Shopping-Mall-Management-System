#include "menu.h"
#include "account.h"
#include "item.h"

using namespace std;

// THIS FUNCTION CREATE MAIN MENU AND CALLS OTHER FUNCTIONS
void menu :: main_menu()
{
    system("CLS");
    char ch ;
    item f{};
    while (true)
    {
        system("CLS");
        cout <<"SHOPPING MALL MANAGEMENT SYSTEM" <<endl;
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout <<"1: PURCHASE" <<endl;
        cout <<"2: SEE MENU" <<endl;
        cout <<"3: EDIT" <<endl;
        cout <<"4: TOTAL BILL" <<endl;
        cout <<"0: QUIT" <<endl;
        cout <<"Enter Choice : " ;
        cin>>ch;
        cout<<endl;
        if (ch == '1')
            f.purchase() ;
        else
        if (ch == '2')
            f.list_of_item() ;
        else
        if (ch == '3')
            edit_menu() ;
        else
        if (ch == '4')
        {
            account a{} ;
            a.bill_list();
        }
        else
        if (ch == '0')
            break ;
    }
}

// THIS FUNCTION CREATE EDIT MENU AND CALLS OTHER FUNCTIONS
void menu :: edit_menu()
{
    char ch ;
    while (true)
    {
        for (int i=5; i<=21; i++)
        {
            cout <<" " ;
        }
        cout <<"E D I T M E N U" <<endl;
        cout <<"~~~~~~~~~~~~~~~~" <<endl;
        cout <<"1: ADD ITEM" <<endl;
        cout <<"2: MODIFY ITEM" <<endl;
        cout <<"3: DELETE ITEM" <<endl;
        cout <<"0: EXIT" <<endl;
        cout <<"Enter Choice : " ;
        cin>>ch;
        if (ch == '1')
        {
            item f{} ;
            f.add_item() ;
            break ;
        }
        else
        if (ch == '2')
        {
            item f{} ;
            f.modify_item() ;
            break ;
        }
        else
        if (ch == '3')
        {
            item f{} ;
            f.delete_item() ;
            break ;
        }
        else
        if (ch == '0')
            break ;
    }
}