#include<iostream>
#include<string>
#include "Admins.h"
#include "Users.h"
using namespace std;
#ifndef GOODS_H
#define GOODS_H

class goods {
	string good_name;
	string good_ID;
    double good_price;
    int good_number;
	string good_description;
	string seller_ID;
	string good_added_date;
	bool good_state;
	friend void Admins::admin_search_goods();
	friend void Admins::admin_del_goods();
	friend void Admins::admin_forbid_users();
	friend void sellers::seller_check_published_goods(string userID);
	friend void sellers::seller_del_goods(string userID);
	friend void sellers::seller_publish_goods(string userID);
	friend void sellers::seller_change_goods_info(string userID);
	friend void buyers::buyer_check_goods(string userID);
	friend void buyers::buyer_check_goods_info(string userID);
	friend void buyers::buy_goods(string userID);
	friend void buyers::buyer_search_goods(string userID);
	friend double is_buy_success(string userID, string input_ID, int input_number);
public:
	goods(){

	} /////////////////////////////////goods() ~goods!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void good_read(goods G1);
	void good_show();

};
extern goods good_list[100];
extern int good_count;
extern const char* good_title[8];
void good_module();
#endif // GOODS_H

