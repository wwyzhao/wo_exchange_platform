#include<iostream>
#include<fstream>
#include<string.h>
#include<stdlib.h>
#include "Admins.h"
#include "Goods.h"
#include "Orders.h"
#include "Users.h"
#include "wo_exchange.h"
using namespace std;

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
	string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM commodity";
	write_sql_command(temp_time, temp_word);
	cout << "--------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int i=0;
	for(i=0;i<7;++i){
		cout<<good_title[i]<<'\t';
	}
	cout<<good_title[i]<<endl;
	int j=0;
	for(int j=0;j<good_count;++j){
		good_list[j].good_show();
	}
	cout << "---------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void Admins::admin_search_goods(){
	string input_name;
	int flag=0;
	cout << "Please enter the good's name:";   
	cin >> input_name;
	string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM commodity WHERE commodityName CONTAINS "+input_name;
	write_sql_command(temp_time, temp_word);
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
	if(input_yn[0]=='y'){   
		good_list[i].good_state=0;
		string temp_time, temp_word;
		temp_time=get_time();
		//cout<<temp_time<<endl;
		temp_word="UPDATE commodity SET state=outSale WHERE commodityID = "+input_ID;
		write_sql_command(temp_time, temp_word);
		ifstream infile;
		infile.open("../files/commodity.txt", ios::in);
		if (!infile.is_open()) exit(-1);
		char buf[1024]; string sbuf;
		infile.getline(buf,sizeof(buf));
		sbuf=sbuf+buf+'\n';
		while (infile.getline(buf,sizeof(buf))){
			string tempbuf=buf;
			char *p;
        	p=strtok(buf,",");
			if(p==input_ID){
				sbuf=sbuf+good_list[i].good_ID+','+good_list[i].good_name+','+to_string(good_list[i].good_price)+','+to_string(good_list[i].good_number)+','+good_list[i].good_description+','+good_list[i].seller_ID+','+good_list[i].good_added_date+','+"outSale\n";
			}
			else sbuf=sbuf+tempbuf+'\n';
		}
		int templen=sbuf.length();
		sbuf[templen]='\0';
		cout<<sbuf<<endl;
		infile.close();
		fstream outfile;
        outfile.open("../files/commodity.txt",ios::out);
        //outfile<<endl;
        outfile<<sbuf;
        outfile.close();
		cout<<"Successfully delete this good"<<endl;
	}
	else{
		cout<<"Not to delete this good"<<endl;
	}
}
void Admins::admin_check_orders(){//TODO tab print
	string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM order";
	write_sql_command(temp_time, temp_word);
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
void Admins::admin_check_users(){//TODO tab print
	string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM user";
	write_sql_command(temp_time, temp_word);
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int i=0;
	for(i=0;i<6;++i){
		cout<<user_title[i]<<'\t';
	}
	cout<<user_title[i]<<endl;
	int j=0;
	for(int j=0;j<user_count;++j){
		user_list[j].user_show();
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void Admins::admin_forbid_users(){
	string input_ID, input_yn;
	cout << "Please enter the user's ID you want to delete:";   
	cin >> input_ID;
	cout<<"Are you sure to forbid this user?"<<endl;
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int k=0;
	for(k=0;k<6;++k){
		cout<<user_title[k]<<'\t';
	}
	cout<<user_title[k]<<endl;
	int i=0, j=0;
	for(i=0;i<user_count;++i){
		if(user_list[i].user_ID==input_ID){
			user_list[i].user_show();
			break;
		}
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
	cin>>input_yn;
	if(input_yn[0]=='y'){   
		user_list[i].user_state=0;
		for(j=0;j<good_count;++j){
			if(good_list[j].seller_ID==user_list[i].user_ID){
				good_list[j].good_state=0;
			}
		}
		string temp_time, temp_word;
		temp_time=get_time();
		//cout<<temp_time<<endl;
		temp_word="UPDATE commodity SET state=outSale WHERE sellerID = "+input_ID;
		write_sql_command(temp_time, temp_word);
		temp_time=get_time();
		//cout<<temp_time<<endl;
		temp_word="UPDATE user SET userState=inactive WHERE userID = "+input_ID;
		write_sql_command(temp_time, temp_word);
		ifstream infile;
		infile.open("../files/user.txt", ios::in);
		if (!infile.is_open()) exit(-1);
		char buf[1024]; string sbuf;
		infile.getline(buf,sizeof(buf));
		sbuf=sbuf+buf+'\n';
		while (infile.getline(buf,sizeof(buf))){
			string tempbuf=buf;
			char *p;
        	p=strtok(buf,",");
			if(p==input_ID){
				sbuf=sbuf+user_list[i].user_ID+','+user_list[i].user_name+','+user_list[i].user_password+','+user_list[i].user_tel+','+user_list[i].user_address+','+user_list[i].user_balance+','+"inactive\n";
			}
			else sbuf=sbuf+tempbuf+'\n';
		}
		int templen=sbuf.length();
		sbuf[templen]='\0';
		//cout<<sbuf<<endl;
		infile.close();
		fstream outfile;
        outfile.open("../files/user.txt",ios::out);
        //outfile<<endl;
        outfile<<sbuf;
        outfile.close();
		ifstream infile1;
		infile1.open("../files/commodity.txt", ios::in);
		if (!infile1.is_open()) exit(-1);
		char buf1[1024]; string sbuf1;
		infile1.getline(buf1,sizeof(buf1));
		sbuf1=sbuf1+buf1+'\n';
		while (infile1.getline(buf1,sizeof(buf1))){
			string tempbuf=buf1;
			char *p;
        	p=strtok(buf1,",");p = strtok(NULL, ",");p = strtok(NULL, ",");p = strtok(NULL, ",");p = strtok(NULL, ",");p = strtok(NULL, ",");
			if(p==input_ID){
				sbuf1=sbuf1+tempbuf;
				int templen2=sbuf1.length();
				int temp1;
				for(temp1=templen2;sbuf1[temp1]!=',';--temp1){
				}
				temp1++;
				sbuf1=sbuf1.substr(0,temp1);
				sbuf1=sbuf1+"outSale\n";
			}
			else sbuf1=sbuf1+tempbuf+'\n';
		}
		int templen1=sbuf1.length();
		sbuf[templen1]='\0';
		cout<<sbuf1<<endl;
		infile1.close();
		fstream outfile1;
        outfile1.open("../files/commodity.txt",ios::out);
        //outfile<<endl;
        outfile1<<sbuf1;
        outfile1.close();
		cout<<"Successfully forbid this user"<<endl;
	}
	else{
		cout<<"Not to forbid this user"<<endl;
	}
}
void Admins::admin_logout(){
	cout<<"log out! Back to the main menu..."<<endl;
}

void admins_module() {
	goods GG;
	GG.good_read();
	orders OO;
	OO.order_read();
	users UU;
	UU.user_read();
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