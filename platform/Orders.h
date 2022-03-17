#include<iostream>
#include<string>
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
public:
	orders(){

	} /////////////////////////////////orders() ~orders!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void order_read();
	void order_show();
	void exchange_price();
	bool order_description();
	void exchange_date();
	//void seller_ID();  ////////////////////////friend?!!!!!!!!!!!!!!!!!!!
	//void buyer_ID();  ////////////////////////friend?!!!!!!!!!!!!!!!!!!!
};
extern orders order_list[100];
extern int order_count;
extern const char* order_title[7];
void order_module();
#endif // ORDERS_H
