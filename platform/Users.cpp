#include "Users.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<time.h>
#include "Goods.h"
#include "Orders.h"
#include "wo_exchange.h"
using namespace std;
users user_list[100];
int user_count=0;
const char* user_title[7]={"userID","username","password","phoneNumber","address","balance","userState"};

void users::user_read(){
    //int i=0;
    ifstream infile;
	infile.open("../files/user.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf[1024];
    infile.getline(buf,sizeof(buf));
    //cout<<buf<<endl;
    while (infile.getline(buf,sizeof(buf)))
	{
		users U1;
        char *p;
        p=strtok(buf,",");
        U1.user_ID=p;
        //cout<<user_ID<<endl;
        p = strtok(NULL, ",");
        U1.user_name=p;
        p = strtok(NULL, ",");
        U1.user_password=p;
        //cout<<strtod(p,NULL)<<endl;
        p = strtok(NULL, ",");
        U1.user_tel=p;
        p = strtok(NULL, ",");
        U1.user_address=p;
        p = strtok(NULL, ",");
        U1.user_balance=p;
        p = strtok(NULL, ",");
        U1.user_state=p;
        string temp;
        temp=p;
        if(temp=="active")U1.user_state=1;
        else U1.user_state=0;
        user_list[user_count]=U1;
        user_count++;
        //for(int i=0;i<8;++i)cout<<p[i]<<endl;
	}
}

void users::user_show(){
    cout<<user_ID<<'\t'<<user_name<<'\t'<<user_password<<'\t'<<user_tel<<'\t'<<user_address<<'\t'<<user_balance<<'\t'<<user_state<<endl;
}

void users_signup() {
    users UUU;
	UUU.user_read();
    string input_new_name, input_password, input_phoneNumber, input_address, input_balance, input_userID;
    cout<<"Please enter a new user name:"<<endl;
    cin>>input_new_name;
    for(int i=0;i<user_count;++i){
        if(user_list[i].user_name==input_new_name){
            cout<<"User name has existed. Back to the main menu..."<<endl;
            return;
        }
    }
    cout<<"Please enter a password:"<<endl;
    cin>>input_password;//phoneNumber,address,balance,userState
    cout<<"Please enter your phoneNumber:"<<endl;
    cin>>input_phoneNumber;
    cout<<"Please enter your address:"<<endl;
    cin>>input_address;
    cout<<"Please enter your balance:"<<endl;
    cin>>input_balance;
     cout<<"Please confirm the info."<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"your name: "<<input_new_name<<endl;
    cout<<"your password: "<<input_password<<endl;
    cout<<"your phoneNumber: "<<input_phoneNumber<<endl;
    cout<<"your address: "<<input_address<<endl;
    cout<<"your balance: "<<input_balance<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
    string input_yn;
	cin>>input_yn;
	if(input_yn[0]=='y'){   // TODO////////////////////////////////write in the file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! good file and user file
		if(user_count>=99)input_userID=to_string(user_count+1);
        else if(user_count>=9)input_userID="0"+to_string(user_count+1);
        else input_userID="00"+to_string(user_count+1);
        users temp;
        temp.user_ID="U"+input_userID;temp.user_name=input_new_name;temp.user_password=input_password;
        temp.user_tel=input_phoneNumber;temp.user_address=input_address;temp.user_balance=input_balance;temp.user_state=1;
        user_list[user_count]=temp;
        user_count++;
        fstream outfile;
        outfile.open("../files/user.txt",ios::out|ios::app);
        //outfile<<endl;
        outfile<<"U"<<input_userID<<","<<input_new_name<<","<<input_password<<","<<input_phoneNumber<<","<<input_address<<","<<input_balance<<","<<"active"<<endl;
        outfile.close();
        }
    else{
        cout<<"Not to signup. Back to the main menu..."<<endl;return;
    }

}

void users_login() {
    users UUU;
	UUU.user_read();
    string input_name;
	string input_code;
	cout << "Please enter your name:";   
	cin >> input_name;
    int flag=0, i=0;
    for(i=0;i<user_count;++i){
        if(user_list[i].user_name==input_name){flag=1;break;}
    }
    if(!flag){cout << "-----------Wrong name! Back to main menu...-----------" << endl;return;}
	cout << "Please enter your password:";
	cin >> input_code;
    if(user_list[i].user_password==input_code){
        cout << "-----------Successfully login!-----------" << endl;
        UUU.users_module(user_list[i].user_ID);
    }
    else{
        cout << "-----------Wrong password! Back to main menu...-----------" << endl;return;
    }
}

void users::users_menu(){
    cout << "===================================================================" << endl;
	cout << "1.I'm buyer 2.I'm seller 3.Personal information 4.user logout" << endl;
	cout << "===================================================================" << endl;
}

void users::users_module(string userID){
    users U;
    int choice;
	while (true) {
		//system("cls");
		U.users_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			//cin.clear();
			//cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:U.buyer_module(userID); break;
		case 2:U.seller_module(userID); break;
		case 3:U.user_self_info(); break;
		case 4:U.user_logout(); return; break;
		default:cout << "Error! Please enter a number:" << endl; break;  ///////////////////////////////check enter 8!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}

void users::buyer_module(string userID){
    buyers B;
    int choice;
	while (true) {
		//system("cls");
		B.buyer_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			//cin.clear();
			//cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:B.buyer_check_goods(userID); break;
		case 2:B.buy_goods(userID); break;
		case 3:B.buyer_search_goods(userID); break;
		case 4:B.buyer_check_orders(userID); break;
        case 5:B.buyer_check_goods_info(userID); break;
		case 6:B.back_to_users(); return; break;
		default:cout << "Error! Please enter a number:" << endl; break;  ///////////////////////////////check enter 8!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}

void buyers::buyer_menu(){
    cout << "===================================================================================================" << endl;
	cout << "1.check goods 2.buy goods 3.search goods 4.check orders 5.check goods' details 6.back to user menu" << endl;
	cout << "===================================================================================================" << endl;
}
void buyers::buyer_check_goods(string userID){
    string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM commodity";
	write_sql_command(temp_time, temp_word);
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int i=0;
	for(i=0;i<7;++i){
		cout<<good_title[i]<<'\t';
	}
	cout<<good_title[i]<<endl;
	int j=0;
	for(int j=0;j<good_count;++j){
        if(good_list[j].good_state==1){
            good_list[j].good_show();
        }
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void buyers::buy_goods(string userID){
    string input_ID;
    int input_number; double input_balance, input_price;
    cout<<"Please enter the ID of the good your want to buy:";
    cin>>input_ID;
    cout<<"Please enter the number of the good you want to buy:";
    cin>>input_number;
    int i=0, flag=0;
    for(i=0;i<good_count;++i){
        if(good_list[i].good_ID==input_ID && good_list[i].good_state==1){
            flag=1;
            break;
        }
    }
    if(!flag){cout<<"The ID of the good does not exist or the good has been out of sale. Back to the user menu..."<<endl; return;}
    input_balance=is_buy_success(string input_ID, int input_number);
    if(input_balance>=0){
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout<<"buy remind: "<<endl;
        cout<<"buy date: "<<get_day()<<endl;
        cout<<"buy price of each good: "<<good_list[i].good_price<<endl;
        cout<<"buy number: "<<input_number<<endl;
        cout<<"buy state: success"<<endl;
        cout<<"your balance: "<<input_balance<<endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
    }
    else{
        cout<<"Not success. Balance not enough. You can recharge in the user self info. Back to the user menu... "<<endl; ///TODO change the buyer balance seller balance good order file
    }
}
void buyers::buyer_search_goods(string userID){
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
		if((good_list[i].good_name.find(input_name))!=-1 && good_list[i].good_state==1){
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

void buyers::buyer_check_orders(string userID){
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
        if(order_list[j].buyer_ID==userID)
		    order_list[j].order_show();
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void buyers::buyer_check_goods_info(string userID){
    string input_ID;
    cout<<"Please enter the ID of the good you want to check:";
    cin>>input_ID;
    int i=0;
    for(i=0;i<good_count;++i){
        if(good_list[i].good_ID==input_ID && good_list[i].good_state==1){
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
            cout<<"good's ID: "<<input_ID<<endl;
            cout<<"good's name: "<<good_list[i].good_name<<endl;
            cout<<"good's price: "<<good_list[i].good_price<<endl;
            cout<<"good's number: "<<good_list[i].good_number<<endl;
            cout<<"good's description: "<<good_list[i].good_description<<endl;
            cout<<"good's added date: "<<good_list[i].good_added_date<<endl;
            cout<<"good's seller: "<<good_list[i].seller_ID<<endl;
            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        }
    }
}
void buyers::back_to_users(){
    cout<<"Back to the user menu..."<<endl;return;
}

void users::seller_module(string userID){
    sellers S;
    int choice;
	while (true) {
		//system("cls");
		S.seller_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			//cin.clear();
			//cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:S.seller_publish_goods(userID); break;
		case 2:S.seller_check_published_goods(userID); break;
		case 3:S.seller_change_goods_info(userID); break;
		case 4:S.seller_del_goods(userID); break;
        case 5:S.seller_check_orders(userID); break;
		case 6:S.back_to_users(); return; break;
		default:cout << "Error! Please enter a number:" << endl; break;  ///////////////////////////////check enter 8!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}
void sellers::seller_menu(){
    cout << "=======================================================================================================" << endl;
	cout << "1.publish goods 2.check goods 3.change goods' info 4.delete goods 5.check orders 6.back to user menu" << endl;
	cout << "=======================================================================================================" << endl;
}
void sellers::seller_publish_goods(string userID){
    goods temp;
    users UUU;
	UUU.user_read();
    string input_new_name, input_price, input_number, input_descrip, input_balance, input_good_ID, input_yn;
    cout<<"Please enter the good's name:"<<endl;
    cin>>input_new_name;
    cout<<"Please enter the price:"<<endl;
    cin>>input_price;
    cout<<"Please enter the number:"<<endl;
    cin>>input_number;
    cout<<"Please enter the description:"<<endl;
    cin>>input_descrip; //TODO description without kongge?????
    cout<<"Please confirm the info."<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"good's name: "<<input_new_name<<endl;
    cout<<"good's price: "<<input_price<<endl;
    cout<<"good's number: "<<input_number<<endl;
    cout<<"good's description: "<<input_descrip<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
	cin>>input_yn;
	if(input_yn[0]=='y'){   // TODO////////////////////////////////write in the file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! good file and user file
		try{
            temp.good_price=stod(input_price);
            temp.good_number=stoi(input_number);
        }
        catch(int){
            cout<<"The good's info is not valid. Back to the user menu..."<<endl;
            return;
        }
        if(good_count>=99)temp.good_ID="M"+to_string(good_count+1);
        else if(good_count>=9)temp.good_ID="M0"+to_string(good_count+1);
        else temp.good_ID="M00"+to_string(good_count+1);
        temp.good_name=input_new_name;temp.good_description=input_descrip;temp.seller_ID=userID;temp.good_state=1;
        temp.good_added_date=get_day();
        good_list[good_count]=temp;
        good_count++;
        fstream outfile;
        outfile.open("../files/commodity.txt",ios::out|ios::app);
        //outfile<<endl;
        outfile<<temp.good_ID<<","<<input_new_name<<","<<temp.good_price<<","<<temp.good_number<<","<<input_descrip<<","<<userID<<","<<temp.good_added_date<<","<<"onSale"<<endl;
        outfile.close();
		string temp_time, temp_word;
		temp_time=get_time();
		//cout<<temp_time<<endl;
		temp_word="INSERT INTO commodity VALUES ("+input_new_name+","+to_string(temp.good_price)+","+to_string(temp.good_number)+","+input_descrip+") ";
		write_sql_command(temp_time, temp_word);
		cout<<"Successfully published this good!"<<endl;
	}
	else{
		cout<<"Not to publish this good"<<endl;
	}
}

void sellers::seller_check_published_goods(string userID){
    string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM commodity";
	write_sql_command(temp_time, temp_word);
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	int i=0;
	for(i=0;i<7;++i){
		cout<<good_title[i]<<'\t';
	}
	cout<<good_title[i]<<endl;
	int j=0;
	for(int j=0;j<good_count;++j){
        if(good_list[j].seller_ID==userID){
            good_list[j].good_show();
        }
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void sellers::seller_change_goods_info(string userID){  //TODO change the file
    string input_ID, input_descript, input_new_name;
    int input_choice; double input_price;
    cout<<"Please enter the ID of the good you want to change:"<<endl;
    cin>>input_ID;
    cout<<"Please enter the choice you want to change(1. price 2. description):"<<endl;
    cin>>input_choice;
    if(input_choice==1){cout<<"Please enter the new price: "; cin>>input_price; }
    else if(input_choice==2){cout<<"Please enetr the new description: "; cin>>input_descript;}
    else{
        cout<<"Unvalid choice. Back to the user menu..."<<endl;
    }
    cout<<"Please confirm the good's info."<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"good's ID: "<<input_ID<<endl;
    int i=0, flag=0;
    for(i=0;i<good_count;++i){
        if(good_list[i].good_ID==input_ID && good_list[i].seller_ID==userID){
            flag=1;
            break;}
    }
    if(!flag){cout<<"Not valid. The ID of the good does not exist or your are not the seller of the good. Back to the user menu..."<<endl;return;}
    cout<<"good's name: "<<good_list[i].good_name<<endl;
    if(input_choice==1){cout<<"good's price: "<<input_price<<endl;cout<<"good's description: "<<good_list[i].good_description<<endl;}
    else if(input_choice==2){cout<<"good's price: "<<good_list[i].good_price<<endl;cout<<"good's description: "<<input_descript<<endl;}
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
    string input_yn;
	cin>>input_yn;
	if(input_yn[0]=='y'){   // TODO////////////////////////////////write in the file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!! good file and user file
		string temp_time, temp_word;
		temp_time=get_time();
        if(input_choice==1){good_list[i].good_price=input_price;temp_word="UPDATE commodity SET price= "+to_string(input_price)+"WHERE good's ID= "+input_ID;}
        else if(input_choice==2){good_list[i].good_description=input_descript;temp_word="UPDATE commodity SET description= "+input_descript+"WHERE good's ID= "+input_ID;}
		write_sql_command(temp_time, temp_word);
    	cout<<"Successfully changed the info of this good!"<<endl;
	}
	else{
		cout<<"Not to change the info of this good"<<endl;
    }
}
void sellers::seller_del_goods(string userID){
    string input_ID, input_yn; int i=0;
	cout << "Please enter the good's ID you want to delete:";   
	cin >> input_ID;
    for(i=0;i<good_count;++i){
		if(good_list[i].good_ID==input_ID){
            if(good_list[i].seller_ID==userID){
                cout<<"Are you sure to delete this good?"<<endl;
	            cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                int k=0;
                for(k=0;k<7;++k){
                    cout<<good_title[k]<<'\t';
                }
                cout<<good_title[k]<<endl;
                good_list[i].good_show();
                cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
                cout<<"Please choose(y/n):";
                cin>>input_yn;
                if(input_yn[0]=='y'){   // TODO////////////////////////////////write in the file!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
                    good_list[i].good_state=0;
                    string temp_time, temp_word;
                    temp_time=get_time();
                    //cout<<temp_time<<endl;
                    temp_word="UPDATE commodity SET state=outSale WHERE commodityID = "+input_ID;
                    write_sql_command(temp_time, temp_word);
                    cout<<"Successfully delete this good"<<endl;
                }
                else{
                    cout<<"Not to delete this good"<<endl;
                }
			    break;
            }
            else{
                cout<<"You are not permitted to chech other seller's goods. Back to the user menu..."<<endl;return;
            }
		}
	}	
}
void sellers::seller_check_orders(string userID){
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
        if(order_list[j].seller_ID==userID)
		    order_list[j].order_show();
	}
	cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;

}
void sellers::back_to_users(){
    cout<<"Back to the user menu..."<<endl;return;
}


void users::user_self_info(){

}
void users::user_logout(){

}

double is_buy_success(string input_ID, int input_number){
    
}