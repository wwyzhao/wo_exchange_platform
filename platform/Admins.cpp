#include "Admins.h"
#include "../platform/wo_exchange.h"

void Admins::admin_menu() {
	cout << "===================================================================================================" << endl;
	cout << "1.check goods 2.search goods 3.delete goods 4.check orders 5.check users 6.forbid users 7.logout" << endl;
	cout << "===================================================================================================" << endl;
}
bool Admins::admin_login() {
	string input_name;
	string input_code;
	//for(int i=0;i<100;++i)input_name[i]='0';
	//for(int i=0;i<100;++i)input_code[i]='0';
	cout << "Please enter your name:";   
	cin >> input_name;
	//for(int i=0;input_name[i];++i)cout<<input_name[i]<<endl;
	//for(int i=0;admin_name[i];++i)cout<<admin_name[i];cout<<endl;
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
void Admins::admin_check_goods(){  
	ifstream infile;
	infile.open("../files/commodity.txt", ios::in);
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
void Admins::admin_search_goods(){
	string input_name;
	//for(int i=0;i<100;++i)input_name[i]='0';
	//for(int i=0;i<100;++i)input_code[i]='0';
	cout << "Please enter the good's name:";   
	cin >> input_name;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int flag=0, index=-1;
	ifstream infile;
	infile.open("../files/commodity.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	string title, buf;
	getline(infile, title, '\n');
	while (!infile.eof()){
		getline(infile, buf, '\n');
		if((buf.find(input_name))!=-1){
			if(!flag){
				for(int i=0;title[i];++i){
					if(buf[i]==','){cout << '\t';}
					else cout << title[i];
				}
				cout << endl;
			}
			flag=1;
			for(int i=0;buf[i];++i){
				if(buf[i]==','){cout << '\t';cout << '\t';}
				else cout << buf[i];
			}
			cout << endl;
		}
	}
	if(!flag)cout<<"Good not found! Back to the Admins menu..."<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}

void Admins::admin_del_goods(){
	string input_ID, input_yn;
	//for(int i=0;i<100;++i)input_name[i]='0';
	//for(int i=0;i<100;++i)input_code[i]='0';
	cout << "Please enter the good's ID you want to delete:";   
	cin >> input_ID;
	cout<<"Are you sure to delete this good?"<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	for(int i=0;title[i];++i){
		if(buf[i]==','){cout << '\t';}
		else cout << title[i];
	}
	cout << endl;
	int index=-1;
	ifstream infile;
	infile.open("../files/commodity.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	string title, buf;
	getline(infile, title, '\n');
	while (!infile.eof()){
		getline(infile, buf, '\n');
		if((buf.find(input_ID))!=-1){
			for(int i=0;buf[i];++i){
				if(buf[i]==','){cout << '\t';cout << '\t';}
				else cout << buf[i];
			}
			cout << endl;  
			break;
		}
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
	cin>>input_yn;
	if(input_yn=='y'){   //////////////////////////////////write in the file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
		cout<<"Successfully delete this good"<<endl;

	}
	else{
		cout<<"Not to delete this good"<<endl;
	}

	if(!flag)cout<<"Good not found! Back to the Admins menu..."<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Admins::admin_check_orders(){
	ifstream infile;
	infile.open("../files/order.txt", ios::in);
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