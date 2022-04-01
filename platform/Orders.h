#include<iostream>
#include<string>
#include "Users.h"
using namespace std;
#ifndef ORDERS_H
#define ORDERS_H

class orders {
	string order_ID;
    string good_ID;  ////////////////////friend?!!!!!!!!!!!!!!!!
	double order_unitprice;
	int order_number;
	string order_date;
	string seller_ID;
	string buyer_ID;
	friend void sellers::seller_check_orders(string userID);
	friend void buyers::buyer_check_orders(string userID);
	friend void buyers::buy_goods(string userID);
public:
	orders(){

	} /////////////////////////////////orders() ~orders!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void order_read(orders O1);
	void order_show();
	void exchange_price();
	bool order_description();
	void exchange_date();
};

extern orders order_list[100];
extern int order_count;
extern const char* order_title[7];
void order_module();
#endif // ORDERS_H
