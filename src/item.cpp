#include "item.h"
#include "account.h"
#include "menu.h"

using namespace std;

//****************************************************************************
// THIS FUNCTION RETURNS THE CODE OF THE LAST RECORD IN THE
// ITEM FILE (ITEM.DAT).
//****************************************************************************
int item :: last_code()
{
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(item)))
        t = itemcode ;
    file.close() ;
    cout<<"t="<<t;
    cout<<"press any key to contd..";
    _getch();
    return t ;
}
//****************************************************************************
// THIS FUNCTION DISPLAY THE LIST OF THE ITEMS
//****************************************************************************
void item :: list_of_item()
{
    system("CLS");
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    file.seekg(0) ;
    int row = 6 , found = 0 , pageno = 1 ;
    cout <<"LIST OF ITEMS" <<endl;
    cout <<"~~~~~~~~~~~~~~~" <<endl;
    cout <<"ITEM CODE ITEM NAME ITEM PRICE" <<endl;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
    while (file.read((char *) this, sizeof(item)))
    {
        found = 1 ;
        cout<<itemcode <<"\t";
        cout<<itemname <<"\t";
        cout<<itemprice <<"\t";
        if ( row == 22 )
        {
            row = 5 ;
            cout <<"Page no. : " <<pageno <<endl;
            cout <<"===============" ;
            pageno++ ;
            cout <<"Press any key to continue..." <<endl;
            _getche() ;
            system("CLS");
            cout <<"LIST OF ITEMS" <<endl;
            cout <<"ITEM CODE ITEM NAME ITEM PRICE"<<endl;
            cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout <<"~~~~~~~~~~~~~~~" <<endl;
        }
        else
            row++ ;
    }
    if ( !found )
    {
        cout <<"\7Records not found" <<endl;
    }
    cout <<"Page no. : " <<pageno <<endl;
    cout <<"===============" <<endl;
    cout <<"Press any key to continue..." <<endl;
    _getche() ;
    file.close () ;
}

// THIS FUNCTION ADD RECORDS IN THE ITEM FILE (ITEM.DAT)

void item:: add_item()
{
    int tcode, valid ;
    char ch, t_itemprice[10] ;
    tcode = last_code() ;
    tcode++ ;
    do
    {
        system("CLS");
        cout <<"<0>=Exit" ;
        cout <<"ADD ITEM TO THE LIST"<<endl ;
        cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        cout <<"Item Code : " <<tcode <<endl ;
        cout <<"Item Name : "<<endl ;
        cout <<"Item Price : " <<endl;
        do
        {
            valid = 1 ;
            cout <<"ENTER ITEM NAME TO ADD IN THE MENU" <<endl;
            cout <<"Item Name : " <<endl;
            cin>>itemname;
            strupr(itemname) ;
            if (itemname[0] == '0')
                return ;
            if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
            {
                valid = 0 ;
                cout <<"\7 Range = 1..20" <<endl;
                _getch() ;
            }
        } while (!valid) ;
        do
        {
            valid = 1 ;
            cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" ;
            cout <<"Item Price : " ;
            cin>>t_itemprice ;
            itemprice = atof(t_itemprice) ;
            if (t_itemprice[0] == '0')
                return ;
            if (itemprice < 200 || itemprice > 2500)
            {
                valid = 0 ;
                cout <<"\7 Range = 200..2500" ;
                _getch() ;
            }
        } while (!valid) ;
        do
        {
            cout <<"Do you want to save this record (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        } while (ch != 'N' && ch != 'Y') ;
        if (ch == 'Y')
        {
            itemcode = tcode ;
            fstream file ;
            file.open("ITEM.DAT", ios::out | ios::app ) ;
            file.write((char *) this, sizeof(item)) ;
            file.close() ;
            tcode++ ;
        }
        do
        {
            cout <<"Do you want to add more records (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
            if (ch == '0')
                return ;
        } while (ch != 'N' && ch != 'Y') ;
    } while (ch == 'Y') ;
}
//****************************************************************************
// THIS FUNCTION DISPLAY THE RECORD OF THE GIVEN CODE FROM
// THE ITEM FILE (ITEM.DAT)
//****************************************************************************
void item :: display_record(int tcode)
{
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) this, sizeof(item)))
    {
        if (itemcode == tcode)
        {
            cout <<"Item Code : "<<"\t\t"<<itemcode <<endl;
            cout <<"Item Name : "<<"\t\t"<<itemname<<endl ;
            cout <<"Item Price : "<<"\t\t"<<itemprice<<endl;
            break ;
        }
    }
    file.close() ;
}
//****************************************************************************
// THIS FUNCTION RETURN THE VALUE 1 IF THE RECORD IS FOUND
// FOR THE GIVEN CODE IN THE ITEM FILE (ITEM.DAT)
//****************************************************************************
int item :: item_found(int tcode)
{
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(item)))
    {
        if (itemcode == tcode)
        {
            found++ ;
            break ;
        }
    }
    file.close() ;
    return found ;
}
//*******************************************************************************
// THIS FUNCTION RETURN THE RECORD NO. OF THE GIVEN CODE IN
// THE ITEM FILE (ITEM.DAT)
//*******************************************************************************
int item :: recordno(int tcode)
{
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int found=0 ;
    while (file.read((char *) this, sizeof(item)))
    {
        found++ ;
        if (itemcode == tcode)
            break ;
    }
    file.close() ;
    return found ;
}
//****************************************************************************
// THIS FUNCTION DELETES THE RECORD FOR THE GIVEN CODE FROM
// THE ITEM FILE (ITEM.DAT)
//****************************************************************************
void item :: delete_record(int tcode)
{
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    fstream temp ;
    temp.open("temp.dat", ios::out) ;
    file.seekg(0,ios::beg) ;
    while ( !file.eof() )
    {
        file.read((char *) this, sizeof(item)) ;
        if ( file.eof() )
            break ;
        if ( itemcode != tcode )
            temp.write((char *) this, sizeof(item)) ;
    }
    file.close() ;
    temp.close() ;
    file.open("ITEM.DAT", ios::out) ;
    temp.open("temp.dat", ios::in) ;
    temp.seekg(0,ios::beg) ;
    while ( !temp.eof() )
    {
        temp.read((char *) this, sizeof(item)) ;
        if ( temp.eof() )
            break ;
        file.write((char *) this, sizeof(item)) ;
    }
    file.close() ;
    temp.close() ;
}
//****************************************************************************
// THIS FUNCTION GIVES THE CODE NUMBER TO DELETE RECORD FROM
// THE ITEM FILE (ITEM.DAT)
//****************************************************************************
void item :: delete_item(void)
{
    system("CLS");
    char t_code[5], ch ;
    int t, tcode ;
    cout <<"Press <ENTER> to see the list" <<endl;
    cout <<"Enter Item Code of the item to be deleted : ";
    cin>>t_code;
    cout<<endl;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
        cout <<"Press <ENTER> to Exit" <<endl;
        cout <<"Enter Item Code of the item to be deleted : " ;
        cin>>t_code;
        cout<<endl;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    system("CLS");
    if (!item_found(tcode))
    {
        cout <<"\7Record not found" <<endl;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        cout <<"Do you want to delete this record (y/n) : " <<endl;
        ch = getche() ;
        ch = toupper(ch) ;
    } while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    delete_record(tcode) ;
    cout <<"\7Record Deleted"<<endl ;
    getch() ;
}
//***************************************************************************
// THIS FUNCTION MODIFY THE RECORD FOR THE GIVEN CODE FROM
// THE ITEM FILE (ITEM.DAT)
//***************************************************************************
void item :: modify_record(int tcode)
{
    int recno ;
    recno = recordno(tcode) ;
    int valid, t_code ;
    char ch, t_itemprice[10], t_itemcode[5] ;
    cout <<"<0>=Exit" <<endl;
    cout <<"Item Code : "<<endl ;
    cout <<"Item Name : " <<endl;
    cout <<"Item Price : " <<endl;
    do
    {
        cout <<"Change (y/n) : " <<endl;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        cout <<"ENTER ITEM CODE TO ADD IN THE MENU" <<endl;
        cout <<"Item Code : ";
        cin>>t_itemcode;
        cout<<endl;
        t_code = atoi(t_itemcode) ;
        if (t_code == 0)
            return ;
        if (item_found(t_code) && t_code != tcode)
        {
            valid = 0 ;
            cout <<"\7 CODE ALREADY GIVEN" <<endl;
            getch() ;
        }
    }
    if(ch=='N')
    {
        t_code=tcode;
    }
    do
    {
        cout <<"Change (y/n) : " ;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'N' && ch != 'Y') ;
    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        cout <<"ENTER ITEM NAME TO ADD IN THE MENU" <<endl;
        cout <<"Item Name : " ;
        cin>>itemname;
        cout<<endl;
        strupr(itemname) ;
        if (itemname[0] == '0')
            return ;
        if ((strlen(itemname) < 1) || (strlen(itemname) > 20))
        {
            valid = 0 ;
            cout <<"\7 Range = 1..20" ;
            getch() ;
        }
    }
    do
    {
        cout <<"Change (y/n) : " <<endl;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'N' && ch != 'Y') ;

    valid = 0 ;
    while (ch == 'Y' && !valid)
    {
        valid = 1 ;
        cout <<"ENTER ITEM PRICE TO ADD IN THE MENU" <<endl;
        cout <<"Item Price : ";
        cin>>t_itemprice;
        cout<<endl;
        itemprice = atof(t_itemprice) ;
        if (t_itemprice[0] == '0')
            return ;
        if (itemprice <200 || itemprice > 2500)
        {
            valid = 0 ;
            cout <<"\7 Range = 200..2500" ;
            getch() ;
        }
    }
    do
    {
        cout <<"Do you want to save this record (y/n) : " <<endl;
        ch = getche() ;
        ch = toupper(ch) ;
        if (ch == '0')
            return ;
    } while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    itemcode = t_code ;
    _getch() ;
    fstream file ;
    file.open("ITEM.DAT", ios::out | ios::ate) ;
    int location ;
    location = (recno-1) * sizeof(item) ;
    file.seekp(location) ;
    file.write((char *) this, sizeof(item)) ;
    file.close() ;
    sort() ;
    system("CLS");
    cout <<"\7Record Modified"<<endl ;
    getch() ;
}
//*****************************************************************************
// THIS FUNCTION GIVES THE CODE NO. TO MODIFY RECORD FROM
// THE ITEM FILE (ITEM.DAT)
//*****************************************************************************
void item :: modify_item()
{
    system("CLS");
    char t_code[5], ch ;
    int t, tcode ;
    cout <<"Press <ENTER> to see the list" <<endl;
    cout <<"Enter Item Code of the item to be Modify : ";
    cin>>t_code;
    cout<<endl;
    t = atoi(t_code) ;
    tcode = t ;
    if (t_code[0] == '0')
        return ;
    if (tcode == 0)
    {
        list_of_item() ;
        cout <<"Press <ENTER> to Exit" <<endl;
        cout <<"Enter Item Code of the item to be modify : ";
        cin>>t_code;
        cout<<endl;
        t = atoi(t_code) ;
        tcode = t ;
        if (tcode == 0)
            return ;
    }
    system("CLS");
    if (!item_found(tcode))
    {
        cout <<"\7Record not found" <<endl;
        getch() ;
        return ;
    }
    display_record(tcode) ;
    do
    {
        cout <<"Do you want to Modify this record (y/n) : " <<endl;
        ch = getche() ;
        ch = toupper(ch) ;
    } while (ch != 'N' && ch != 'Y') ;
    if (ch == 'N')
        return ;
    modify_record(tcode) ;
}
//****************************************************************************
// THIS FUNCTION SORT THE RECORD IN THE ITEM FILE (ITEM.DAT)
// ACCORDING TO THE CODE NUMBERS.
//****************************************************************************
void item :: sort()
{
    int i=0,j ;
    item arr[100] ;
    item temp ;
    fstream file ;
    file.open("ITEM.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    while (file.read((char *) &arr[i], sizeof(item)))
        i++ ;
    int size ;
    size = i ;
    file.close() ;
    for (i=1; i<size; i++)
        for (j=0; j<size-i; j++)
        {
            if (arr[j].itemcode > arr[j+1].itemcode)
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
            }
        }
    file.open("ITEM.DAT", ios::out) ;
    for (i=0; i<size; i++)
        file.write((char *) &arr[i], sizeof(item)) ;
    file.close() ;
}

//****************************************************************************
// THIS FUNCTION PURCHASES THE FOOD ITEM IN THE LIST
//****************************************************************************
void item :: purchase()
{
    system("CLS");
    account a{} ;
    int t_billno, purchased=0 ;
    t_billno = a.last_billno() ;
    t_billno++ ;
    char t_code[5], ch, t_quantity[5] ;
    int t, tcode, i=0, valid ;
    float qty ;
    int t_itemcode ;
    float t_qty, t_price ;
    char t_itemname[30] ;

    int d1, m1, y1 ;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    d1 = aTime->tm_mday ;
    m1 = aTime->tm_mon + 1;
    y1 = aTime->tm_year + 1900 ;
    do
    {
        system("CLS");
        cout <<"Press <ENTER> to see the list" <<endl;
        cout <<"Enter Item Code of the item to be Purchase : ";
        cin>>t_code;
        cout<<endl;
        t = atoi(t_code) ;
        tcode = t ;
        if (t_code[0] == '0')
        {
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        if (tcode == 0)
        {
            list_of_item() ;
            cout <<"Press <ENTER> to Exit" <<endl;
            cout <<"Enter Item Code of the item to be Purchased : ";
            cin>>t_code;
            cout<<endl;
            t = atoi(t_code) ;
            tcode = t ;
            if (tcode == 0)
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
        }
        system("CLS");
        if (!item_found(tcode))
        {
            cout <<"\7Item Code not found" <<endl;
            getch() ;
            if (purchased)
                a.prepare_bill(t_billno) ;
            return ;
        }
        cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 <<endl;
        display_record(tcode) ;
        do
        {
            valid = 1 ;
            cout <<"ENTER QUANTITY TO BE PURCHASED IN Numbers." <<endl;
            cout <<"Quantity : " ;
            cin>>t_quantity;
            cout<<endl;
            qty = atoi(t_quantity) ;
            if (t_quantity[0] == '0')
            {
                if (purchased)
                    a.prepare_bill(t_billno) ;
                return ;
            }
            if (qty < 1 || qty > 100)
            {
                valid = 0 ;
                cout <<"\7 Range = 1..100" <<endl;
                getch() ;
            }
        } while (!valid) ;
        do
        {
            cout <<"Do you want to cancel this purchase (y/n) : " <<endl;
            ch = getche() ;
            ch = toupper(ch) ;
        } while (ch != 'N' && ch != 'Y') ;
        if (ch == 'N')
        {
            purchased = 1 ;
            fstream file ;
            file.open("ITEM.DAT", ios::in) ;
            file.seekg(0,ios::beg) ;
            while (file.read((char *) this, sizeof(item)))
            {
                if (itemcode == tcode)
                {
                    t_itemcode = itemcode ;
                    strcpy(t_itemname,itemname) ;
// t_cost = itemcost ;
                    t_price = itemprice ;
                    t_qty = qty ;
                    a.add_bill(t_billno,t_itemcode
                            ,t_itemname,t_qty,t_price) ;
                    i++ ;
                    break ;
                }
            }
            file.close() ;
        }
        do
        {
            cout <<"Do you want to purchase more (y/n) : " ;
            ch = getche() ;
            ch = toupper(ch) ;
        } while (ch != 'N' && ch != 'Y') ;
    } while (ch == 'Y') ;
    a.prepare_bill(t_billno) ;
}