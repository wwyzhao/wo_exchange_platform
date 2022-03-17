#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "Goods.h"
using namespace std;
goods good_list[100];
int good_count=0;
const char* good_title[8]={"commodityID","commodityName","price","number","description","sellerID","addedDate","state"};

void goods::good_read(){
    //int i=0;
    ifstream infile;
	infile.open("../files/commodity.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf[1024];
    infile.getline(buf,sizeof(buf));
    //cout<<buf<<endl;
    while (infile.getline(buf,sizeof(buf)))
	{
		goods G1;
        char *p;
        p=strtok(buf,",");
        G1.good_ID=p;
        //cout<<good_ID<<endl;
        p = strtok(NULL, ",");
        G1.good_name=p;
        p = strtok(NULL, ",");
        G1.good_price=strtod(p,NULL);
        //cout<<strtod(p,NULL)<<endl;
        p = strtok(NULL, ",");
        G1.good_number=stoi(p);
        p = strtok(NULL, ",");
        G1.good_description=p;
        p = strtok(NULL, ",");
        G1.seller_ID=p;
        p = strtok(NULL, ",");
        G1.good_added_date=p;
        p = strtok(NULL, ",");
        string temp;
        temp=p;
        if(temp=="onSale")G1.good_state=1;
        else G1.good_state=0;
        good_list[good_count]=G1;
        good_count++;
        //for(int i=0;i<8;++i)cout<<p[i]<<endl;
	}
}

void goods::good_show(){
    cout<<good_ID<<'\t'<<good_name<<'\t'<<good_price<<'\t'<<good_number<<'\t'<<good_description<<'\t'<<seller_ID<<'\t'<<good_added_date<<'\t'<<good_state<<endl;
}