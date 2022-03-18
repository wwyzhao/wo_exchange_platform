#include<iostream>
#include<string>
#include "Admins.h"
using namespace std;
#ifndef USERS_H
#define USERS_H

class users {
    string user_ID;
    string user_name;
    string user_password;
    string user_tel;
    string user_address;
    string user_balance;
    bool user_state;
    friend void Admins::admin_forbid_users();
    friend void users_signup();
    friend void users_login();
    friend double is_buy_success(string userID, string input_ID, int input_number);
public:
	users(){

	}
    void user_read();
    void user_show();
    void users_menu();
    void users_module(string userID);
	void buyer_module(string userID);
	void seller_module(string userID);
	void user_self_info(string userID);
    void user_self_info_menu();
    void check_self_info(string userID);
    void change_self_info(string userID);
    void recharge(string userID);
    void back_to_users();
	void user_logout();

};
extern users user_list[100];
extern int user_count;
extern const char* user_title[7];
void users_signup();
void users_login();
double is_buy_success(string userID, string input_ID, int input_number);



class buyers{
    //string buyer_ID;
 public:
    void buyer_menu();
    void buyer_check_goods(string userID);
    void buy_goods(string userID);
    void buyer_search_goods(string userID);
    void buyer_check_orders(string userID);
    void buyer_check_goods_info(string userID);
    void back_to_users();
};

class sellers{
    //string seller_ID;
   
 public:
    void seller_menu();
    void seller_publish_goods(string userID);
    void seller_check_published_goods(string userID);
    void seller_change_goods_info(string userID);
    void seller_del_goods(string userID);
    void seller_check_orders(string userID);
    void back_to_users();
};


#endif // USERS_H

