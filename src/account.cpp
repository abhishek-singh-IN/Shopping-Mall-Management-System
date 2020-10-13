#include "account.h"

using  namespace std;

// THIS FUNCTION RETURNS THE BILL NO. OF THE LAST RECORD IN THE BILL FILE (BILLING.DAT)
int account :: last_billno()
{
    fstream file ;
    file.open("BILLING.DAT", ios::in) ;
    file.seekg(0,ios::beg) ;
    int t=0 ;
    while (file.read((char *) this, sizeof(account)))
        t = billno ;
    file.close() ;
    return t ;
}

// THIS FUNCTION ADDS THE RECORD IN THE BILL FILE (BILLING.DAT)
void account :: add_bill(int t_billno, int t_itemcode, char t_itemname[30]
        , float t_qty, float t_price)
{
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    int d1, m1, y1 ;
    d1 = aTime->tm_mday ;
    m1 =aTime->tm_mon + 1;
    y1 = aTime->tm_year + 1900;
    dd = d1 ;
    mm = m1 ;
    yy = y1 ;
    code = t_itemcode ;
    strcpy(name,t_itemname) ;
    price = t_price ;
    quantity = t_qty ;
    billno = t_billno ;
    fstream file ;
    file.open("BILLING.DAT", ios::out | ios:: app ) ;
    file.write((char *) this, sizeof(account));
    cout<<this->quantity;
    cout<<"press any key to contd..";
    file.close() ;
}
//*****************************************************************************
// THIS FUNCTION PREPARES AND DISPLAYS THE BILL FOR THE
// GIVEN BILL NO. ACCORDING TO PURCHASES MADE.
//*****************************************************************************
void account :: prepare_bill(int t_billno)
{
    system("CLS");

    int d1, m1, y1 ;
    time_t theTime = time(NULL);
    struct tm *aTime = localtime(&theTime);

    d1 = aTime->tm_mday;
    m1 = aTime->tm_mon + 1;
    y1 = aTime->tm_year + 1900;
    float total=0.0, total_bill=0.0 ;
    cout <<"CUSTOMER BILL" <<endl;
    cout <<"~~~~~~~~~~~~~~~" <<endl;
    cout <<"Date:" <<d1 <<"/" <<m1 <<"/" <<y1 <<endl;
    cout <<"ITEMS PURCHASED" <<endl;
    cout <<"~~~~~~~~~~~~~~~" <<endl;
    cout <<"Item code Item name Price Qty Total" <<endl;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" ;
    int row=11 ;
    fstream file ;
    file.open("BILLING.DAT", ios::in) ;
    file.seekg(0) ;
    while (file.read((char *) this, sizeof(account)))
    {
        if (billno == t_billno)
        {
            cout <<"BILL NO. # " <<billno <<endl;
            cout <<"~~~~~~~~~~~~~~~" <<endl;
            cout <<code <<endl;
            cout <<name <<endl;
            cout <<price <<endl;
            cout <<quantity <<endl;
            total = quantity * price ;
            cout <<total <<endl;
            total_bill = total_bill + total ;
            row++ ;
        }
    }
    file.close() ;
    cout <<"TOTAL BILL: Rs." <<total_bill <<" /=" <<endl;
    getch() ;
}
//****************************************************************************
// THIS FUNCTION DISPLAYS THE LIST OF THE BILLS
//****************************************************************************
void account :: bill_list()
{
    system("CLS");
    fstream file ;
    file.open("BILLING.DAT", ios::in) ;
    file.seekg(0) ;
    int row=5, found=0, pageno=1, prev_billno=0, flag=0 ;
    float total, total_bill=0.0 ;
    cout <<"LIST OF BILLS" <<endl;
    cout <<"~~~~~~~~~~~~~~~" <<endl;
    cout <<"Billno. Date Item Code Item name Price"<<endl;
    cout <<" Qty Total" <<endl;
    cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
    cout <<"~~~~~~~~~~~~~~" <<endl;
    while (file.read((char *) this, sizeof(account)))
    {
        row++ ;
        found = 1 ;
        if (prev_billno != billno)
        {
            if (flag)
            {
                row++ ;
            }
            cout <<billno ;
        }
        flag = 1 ;
        cout <<dd <<"/" <<mm <<"/" <<yy <<endl;
        cout <<code <<endl;
        cout <<name <<endl;
        cout <<price <<endl;
        cout <<quantity <<endl;
        total = quantity * price ;
        cout <<total ;
        total_bill = total_bill + total ;
        if ( row >= 23 )
        {
            row = 5 ;
            cout <<"Page no. : " <<pageno <<endl;
            pageno++ ;
            cout <<"Press any key to continue..." <<endl;
            getche() ;
            system("CLS");
            cout <<"LIST OF BILLS" ;
            cout <<"Billno. Date Item Code Item name"<<endl;
            cout <<" Price Qty Total" <<endl;
            cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~"<<endl;
            cout <<"~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~" <<endl;
        }
        prev_billno = billno ;
    }
    if ( !found )
    {
        cout <<"\7Records not found" <<endl;
    }
    cout <<"Page no. : " <<pageno <<endl;
    cout <<"TOTAL BILL: Rs." <<total_bill<<"/-" <<endl;
    cout <<"Press any key to continue..." ;
    getche() ;
    file.close () ;
}