#include<iostream>
#include "../platform/Admins.h"
#include<windows.h>
using namespace std;

void wo_exchange() {
	int choice;
	while (true) {
		system("cls");
		main_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			cin.clear();
			cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:admins_module(); break;
		case 2:users_signup(); break;
		case 3:users_login(); break;
		case 4:exit(-1); break;
		default:cout << "Error! Please enter a number:" << endl; break;
		}
	}
}

void main_menu() {
	cout << "=======================================" << endl;
	cout << "1.admins login 2.users signup 3.users login 4.exit" << endl;
	cout << "=======================================" << endl;

}