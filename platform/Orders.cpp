#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "Orders.h"
using namespace std;
orders order_list[100];
int order_count=0;
const char* order_title[7]={"orderID","commodityID","unitPrice","number","date","sellerID","buyerID"};

void orders::order_read(orders O1){
    //int i=0;
    ifstream infile;
	infile.open("../files/order.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf[1024];
    infile.getline(buf,sizeof(buf));
    //cout<<buf<<endl;
    while (infile.getline(buf,sizeof(buf)))
	{
        char *p;
        p=strtok(buf,",");
        O1.order_ID=p;
        //cout<<order_ID<<endl;
        p = strtok(NULL, ",");
        O1.good_ID=p;
        p = strtok(NULL, ",");
        O1.order_unitprice=strtod(p,NULL);
        //cout<<strtod(p,NULL)<<endl;
        p = strtok(NULL, ",");
        O1.order_number=stoi(p);
        p = strtok(NULL, ",");
        O1.order_date=p;
        p = strtok(NULL, ",");
        O1.seller_ID=p;
        p = strtok(NULL, ",");
        O1.buyer_ID=p;
        order_list[order_count]=O1;
        order_count++;
        
        //for(int i=0;i<8;++i)cout<<p[i]<<endl;
	}
    infile.close();
}

void orders::order_show(){
    cout<<order_ID<<'\t'<<good_ID<<'\t'<<order_unitprice<<'\t'<<order_number<<'\t'<<order_date<<'\t'<<seller_ID<<'\t'<<buyer_ID<<endl;
}