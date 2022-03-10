#include<iostream>
#include "Admins.h"
#include<fstream> 
#include "../platform/wo_exchange.h"
using namespace std;

void Admins::admin_menu() {
	cout << "=============================================================================================" << endl;
	cout << "1.check goods 2.search goods 3.delete goods 4.check orders 5.check users 6.forbid users 7.logout" << endl;
	cout << "=============================================================================================" << endl;
}
bool Admins::admin_login() {
	char input_name[100];
	char input_code[100];
	cout << "Please enter your name:";
	cin >> input_name;
	cout << "Please enter your password:";
	cin >> input_code;
	if (input_name != admin_name) {
		cout << "-----------Wrong name! Back to main menu...-----------" << endl;
		return false;
	}
	else if (input_code != admin_code) {
		cout << "-----------Wrong password! Back to main menu...-----------" << endl;
		return false;
	}
	else {
		cout << "-----------Successfully login!-----------" << endl;
		return true;
	}
}
void Admins::admin_check_goods(){
	ifstream infile;
	infile.open("D:\\Desktop\\WO_exchange_platform\\exchange_platform\\files\\commodity.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf[1024];
	cout << "-----------------------------------------" << endl;
	while (infile.getline(buf,sizeof(buf)))
	{
		for(int i=0;buf[i];++i){
			if(buf[i]==',')cout << '\t';
			else cout << buf[i];
		}
		cout << endl;
	}
	cout << "-----------------------------------------" << endl;
}
void Admins::admin_search_goods(){

}
void Admins::admin_del_goods(){

}
void Admins::admin_check_orders(){

}
void Admins::admin_check_users(){

}
void Admins::admin_forbid_users(){

}
void Admins::admin_logout(){
	
}

void admins_module() {
	Admins AA;
	if (!AA.admin_login()) return;/////////
	int choice;
	while (true) {
		system("cls");
		AA.admin_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			cin.clear();
			cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:AA.admin_check_goods(); break;
		case 2:AA.admin_search_goods(); break;
		case 3:AA.admin_del_goods(); break;
		case 4:AA.admin_check_orders(); break;
		case 5:AA.admin_check_users(); break;
		case 6:AA.admin_forbid_users(); break;
		case 7:AA.admin_logout(); break;
		default:cout << "Error! Please enter a number:" << endl; break;
		}
	}
}