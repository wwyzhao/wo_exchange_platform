#include<iostream>
#include<time.h>
//#include <unistd.h>
#include "Admins.h"
#include "Goods.h"
#include "Users.h"
#include "Orders.h"
#include "wo_exchange.h"
using namespace std;


void wo_exchange() {
	goods GG;
	GG.good_read(GG);
	orders OO;
	OO.order_read(OO);
	users UU;
	UU.user_read(UU);
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
		case 3:users_login(UU); break;
		case 4:find_password(UU);break;
		case 5:exit(-1); cout <<"Exit.."; return; break; //在前面sleep(1); 
		default:cout << "Error! Please enter a number:" ; break;
		}
	}
}

void main_menu() {
	cout << "=================================================================" << endl;
	cout << "1.admins login 2.users signup 3.users login 4.forget password 5.exit" << endl;
	cout << "=================================================================" << endl;

}

string get_time(){
	time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d %H:%M:%S",localtime(&timep));
    return tmp;
}
string get_day(){
	time_t timep;
    time (&timep);
    char tmp[64];
    strftime(tmp, sizeof(tmp), "%Y-%m-%d",localtime(&timep));
    return tmp;
}

void write_sql_command(string temp_time, string temp_word){
	fstream outfile;
	outfile.open("../files/commands.txt",ios::out|ios::app);
	//outfile<<endl;
	outfile<<temp_time<<": "<<temp_word<<endl;
	outfile.close();
}