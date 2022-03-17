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
public:
	users(){

	}
    void user_read();
    void user_show();
	bool user_signup();
	bool user_login();
    void user_menu();
	void buyer_module();
	void seller_module();
	void user_self_info();
	void user_logout();

};
extern users user_list[100];
extern int user_count;
extern const char* user_title[7];
void users_signup();
void users_login();

class buyers: public users {
    string buyer_ID;
 public:
    void buyer_menu();
    void buyer_check_goods();
    void buy_goods();
    void buyer_search_goods();
    void buyer_check_orders();
    void buyer_check_goods_info();
    void back_to_users();
};

class sellers: public users {
    string seller_ID;
 public:
    void seller_menu();
    void seller_publish_goods();
    void seller_check_published_goods();
    void seller_change_goods_info();
    void seller_del_goods();
    void seller_check_orders();
    void back_to_users();
};

#endif // USERS_H

