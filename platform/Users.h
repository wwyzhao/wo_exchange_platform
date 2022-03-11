#ifndef USERS_H
#define USERS_H
class Users {
	string user_name[100];
	string user_code[100];
    string user_ID[100];
    string user_tel[100];
    string user_address[100];
    string user_balance[100];
    bool user_state;
public:
	Users(){

	}
	bool user_signup();
	bool user_login();
    void user_menu();
	void buyer_module();
	void seller_module();
	void user_self_info();
	void user_logout();

};
void users_signup();
void users_login();

class Buyers: public Users {
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

class Sellers: public Users {
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

