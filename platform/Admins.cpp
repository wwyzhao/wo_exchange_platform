#include<iostream>
#include "Admins.h"
using namespace std;

void Admins::admin_menu() {
	cout << "====================================================================================" << endl;
	cout << "1.�鿴������Ʒ 2.������Ʒ 3.�¼���Ʒ 4.�鿴���ж��� 5.�鿴�����û� 6.����û� 7.ע��" << endl;
	cout << "====================================================================================" << endl;
}

bool Admins::admin_login() {
	char input_name[100];
	char input_code[100];
	cout << "���������Ա������";
	cin >> input_name;
	cin >> input_code;
	if (input_name != admin_name) {
		cout << "-----------����Ա�������󣬵�½ʧ�ܣ��������˵�-----------" << endl;
		return false;
	}
	else if (input_code != admin_code) {
		cout << "-----------������󣬵�½ʧ�ܣ��������˵�-----------" << endl;
		return false;
	}
	else {
		cout << "-----------��¼�ɹ�-----------" << endl;
		return true;
	}
}

void Admins::admin_check_goods(){
	FILE *fp=fopen("../../files/commodity.txt", "rw");
	if (fp==NULL) exit(-1);

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
	int choice;//����û�����
	while (true) {
		system("cls");
		AA.admin_menu();
		cout << "������һ������:";
		cin >> choice;
		while (!cin) {
			cout << "�������������һ������:";
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
		default:cout << "�������������һ��1-7������:" << endl; break;
		}
	}
}