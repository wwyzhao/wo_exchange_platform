#include<iostream>
#include<fstream>
#include<string>
using namespace std;
#ifndef ADMINS_H
#define ADMINS_H

class Admins {
	string admin_name="admin";
	string admin_code="123456";
public:
	Admins(){
		
	} /////////////////////////////////Admins() ~Admins!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void admin_menu();
	bool admin_login();
	void admin_check_goods();
	void admin_search_goods();
	void admin_del_goods();
	void admin_check_orders();
	void admin_check_users();
	void admin_forbid_users();
	void admin_logout();
};
void admins_module();
#endif // ADMINS_H

