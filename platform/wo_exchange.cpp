#include<iostream>
#include "Admins.h"
#include "wo_exchange.h"
using namespace std;


void users_signup() {
	
}
void users_login() {

}

void wo_exchange() {
	int choice;//����û�����
	while (true) {
		system("cls");
		main_menu();
		cout << "������һ������:";
		cin >> choice;
		while (!cin) {
			cout << "�������������һ������:";
			cin.clear();
			cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:admins_module(); break;
		case 2:users_signup(); break;
		case 3:users_login(); break;
		case 4:exit(-1); break;
		default:cout << "�������������һ��1-4������:" << endl; break;
		}
	}
}

void main_menu() {
	cout << "=======================================" << endl;
	cout << "1.����Ա��¼ 2.�û�ע�� 3.�û���¼ 4.�˳�����" << endl;
	cout << "=======================================" << endl;

}