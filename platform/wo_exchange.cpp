#include<iostream>
//#include <unistd.h>
#include "Admins.h"
#include "Goods.h"
#include "Users.h"
#include "wo_exchange.h"
using namespace std;

void users_signup() {
	
}
void users_login() {

}

void wo_exchange() {
	int choice;
	while (true) {
		//system("cls");
		main_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			//cin.clear();
			//cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:admins_module(); break;
		case 2:users_signup(); break;
		case 3:users_login(); break;
		case 4:exit(-1); cout <<"Exit.."; return; break; //在前面sleep(1); 
		default:cout << "Error! Please enter a number:" ; break;
		}
	}
}

void main_menu() {
	cout << "===================================================" << endl;
	cout << "1.admins login 2.users signup 3.users login 4.exit" << endl;
	cout << "===================================================" << endl;

}