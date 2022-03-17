#include "Admins.h"
#include "Goods.h"
#include "Orders.h"
#include "../platform/wo_exchange.h"

void Admins::admin_menu() {
	cout << "===================================================================================================" << endl;
	cout << "1.check goods 2.search goods 3.delete goods 4.check orders 5.check users 6.forbid users 7.logout" << endl;
	cout << "===================================================================================================" << endl;
}
bool Admins::admin_login() {
	string input_name;
	string input_code;
	cout << "Please enter your name:";   
	cin >> input_name;
	cout << "Please enter your password:";
	cin >> input_code;
	if (input_name!=admin_name) {
		cout << "-----------Wrong name! Back to main menu...-----------" << endl;
		return false;
	}
	if (input_code!=admin_code) {
		cout << "-----------Wrong password! Back to main menu...-----------" << endl;
		return false;
	}
	cout << "-----------Successfully login!-----------" << endl;
	return true;
}
void Admins::admin_check_goods(){  //TODOtab print
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int i=0;
	for(i=0;i<7;++i){
		cout<<good_title[i]<<'\t';
	}
	cout<<good_title[i]<<endl;
	int j=0;
	for(int j=0;j<good_count;++j){
		good_list[j].good_show();
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Admins::admin_search_goods(){
	string input_name;
	int flag=0;
	cout << "Please enter the good's name:";   
	cin >> input_name;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for(int i=0;i<good_count;++i){
		if((good_list[i].good_name.find(input_name))!=-1){
			if(!flag){
				int k=0;
				for(k=0;k<7;++k){
					cout<<good_title[k]<<'\t';
				}
				cout<<good_title[k]<<endl;
			}
			good_list[i].good_show();
			flag=1;
		}
	}
	if(!flag)cout<<"Good not found! Back to the Admins menu..."<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Admins::admin_del_goods(){
	string input_ID, input_yn;
	cout << "Please enter the good's ID you want to delete:";   
	cin >> input_ID;
	cout<<"Are you sure to delete this good?"<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int k=0;
	for(k=0;k<7;++k){
		cout<<good_title[k]<<'\t';
	}
	cout<<good_title[k]<<endl;
	int i=0;
	for(i=0;i<good_count;++i){
		if(good_list[i].good_ID==input_ID){
			good_list[i].good_show();
			break;
		}
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
	cin>>input_yn;
	if(input_yn[0]=='y'){   // TODO////////////////////////////////write in the file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		good_list[i].good_state=0;
		cout<<"Successfully delete this good"<<endl;
	}
	else{
		cout<<"Not to delete this good"<<endl;
	}
}
void Admins::admin_check_orders(){//TODO tab print
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int i=0;
	for(i=0;i<6;++i){
		cout<<order_title[i]<<'\t';
	}
	cout<<order_title[i]<<endl;
	int j=0;
	for(int j=0;j<order_count;++j){
		order_list[j].order_show();
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Admins::admin_check_users(){
	ifstream infile;
	infile.open("../files/user.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf[1024];
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	infile.getline(buf,sizeof(buf));
	for(int i=0;buf[i];++i){
			if(buf[i]==','){cout << '\t';}
			else cout << buf[i];
		}
	cout << endl;
	while (infile.getline(buf,sizeof(buf)))
	{
		for(int i=0;buf[i];++i){
			if(buf[i]==','){cout << '\t'; cout << '\t';}
			else cout << buf[i];
		}
		cout << endl;
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Admins::admin_forbid_users(){

}
void Admins::admin_logout(){
	cout<<"log out! Back to the main menu..."<<endl;
}

void admins_module() {
	goods GG;
	GG.good_read();
	orders OO;
	OO.order_read();
	Admins AA;
	if (!AA.admin_login()) return;/////////
	int choice;
	while (true) {
		//system("cls");
		AA.admin_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			//cin.clear();
			//cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:AA.admin_check_goods(); break;
		case 2:AA.admin_search_goods(); break;
		case 3:AA.admin_del_goods(); break;
		case 4:AA.admin_check_orders(); break;
		case 5:AA.admin_check_users(); break;
		case 6:AA.admin_forbid_users(); break;
		case 7:AA.admin_logout(); return; break;
		default:cout << "Error! Please enter a number:" << endl; break;  ///////////////////////////////check enter 8!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}