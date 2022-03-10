#ifndef ADMINS_H
#define ADMINS_H
class Admins {
	const char admin_name[10];
	const char admin_code[10];
public:
	Admins() :admin_name("admin"), admin_code("123456") {
	}
	
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

