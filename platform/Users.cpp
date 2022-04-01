#include "Users.h"
#include<iostream>
#include<fstream>
#include<string.h>
#include<string>
#include<stdlib.h>
#include<stdlib.h>
#include<time.h>
#include "Goods.h"
#include "Orders.h"
#include "calculator.h"
#include "wo_exchange.h"
using namespace std;
users user_list[100];
int user_count=0;
const char* user_title[7]={"userID","username","password","phoneNumber","address","balance","userState"};

void users::user_read(users U1){
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
    infile.close();
}

void users::user_show(){
    cout<<user_ID<<'\t'<<user_name<<'\t'<<user_password<<'\t'<<user_tel<<'\t'<<user_address<<'\t'<<user_balance<<'\t'<<user_state<<endl;
}

void users_signup() {
    //users UUU;
	//UUU.user_read();
    string input_new_name, input_password, input_phoneNumber, input_address, input_balance, input_userID;
    cout<<"Please enter a new user name:";
    cin>>input_new_name;
    for(int i=0;i<user_count;++i){
        if(user_list[i].user_name==input_new_name){
            cout<<"User name has existed. Back to the main menu..."<<endl;
            return;
        }
    }
    cout<<"Please enter a password:";
    cin>>input_password;//phoneNumber,address,balance,userState
    cout<<"Please enter your phoneNumber:";
    cin>>input_phoneNumber;
    cout<<"Please enter your address:";
    cin>>input_address;
    input_balance="0.0";
    //cout<<"Please enter your balance:"<<endl;
    //cin>>input_balance;
     cout<<"Please confirm the info."<<endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout<<"your name: "<<input_new_name<<endl;
    cout<<"your password: "<<input_password<<endl;
    cout<<"your phoneNumber: "<<input_phoneNumber<<endl;
    cout<<"your address: "<<input_address<<endl;
    cout<<"your balance: "<<input_balance<<endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
    string input_yn;
	cin>>input_yn;
	if(input_yn[0]=='y'){  
		if(user_count>=99)input_userID=to_string(+1);
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
        cout<<"Successfully signed up. Back to the main menu..."<<endl;return;
        }
    else{
        cout<<"Not to signup. Back to the main menu..."<<endl;return;
    }
}

void users_login(users UUU) {
    //users UUU;
	//UUU.user_read();
    string input_name;
	string input_code;
	cout << "Please enter your name:";   
	cin >> input_name;
    int flag=0, i=0;
    for(i=0;i<user_count;++i){
        if(user_list[i].user_name==input_name){flag=1;break;}
    }
    if(!user_list[i].user_state){cout << "-----------Forbidden user! Back to main menu...-----------" << endl;return;}
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

void find_password(users UUU){
    string input_name, input_tel, input_address;
    cout<<"please enter your name:";
    cin>>input_name;
    cout<<"please enter your telephone:";
    cin>>input_tel;
    cout<<"please enter your address:";
    cin>>input_address;
    for(int i=0;i<user_count;++i){
        if(user_list[i].user_name==input_name && user_list[i].user_tel==input_tel && user_list[i].user_address==input_address){
            cout<<"your password is: "<<user_list[i].user_password<<endl;
        }
    }
}
void users::chat(string userID){
    string input_name, input_pass,input_word;
    cout<<"Please enter the name you want to chat with:";
    cin>>input_name;
    cout<<input_name<<" please enter your password:";
    cin>>input_pass;
    for(int i=0;i<user_count;++i){
        if(user_list[i].user_name==input_name && user_list[i].user_password==input_pass)cout<<"chat begin! end with #"<<endl;
    }
    cin>>input_word;
    while(input_word!="#"){
        cin>>input_word;
    }
}

void users::users_menu(){
    cout << "=====================================================================" << endl;
	cout << "1.I'm buyer 2.I'm seller 3.Personal information 4.chat 5.user logout" << endl;
	cout << "=====================================================================" << endl;
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
		case 3:U.user_self_info(userID); break;
        case 4:U.chat(userID); break;
		case 5:U.user_logout(); return; break;
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
        if(good_list[i].good_ID==input_ID && good_list[i].good_state==1 && good_list[i].good_number>=input_number){
            flag=1;
            break;
        }
    }
    if(!flag){
        if(good_list[i].good_state==0){cout<<"The good has been out of sale. Back to the user menu..."<<endl; return;}
        else if(good_list[i].good_number<input_number){cout<<"The number of good is not enough. Back to the user menu..."<<endl; return;}
        else {cout<<"The ID of the good does not exist. Back to the user menu..."<<endl; return;}}
    input_balance=is_buy_success(userID, input_ID, input_number);
    if(input_balance>=0){
        good_list[i].good_number-=input_number;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
        cout<<"buy info: "<<endl;
        cout<<"buy date: "<<get_day()<<endl;
        cout<<"buy price of each good: "<<good_list[i].good_price<<endl;
        cout<<"buy number: "<<input_number<<endl;
        cout<<"buy state: success"<<endl;
        cout<<"your balance: "<<input_balance<<endl;
        cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
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
				sbuf=sbuf+good_list[i].good_ID+','+good_list[i].good_name+','+to_string(good_list[i].good_price)+','+to_string(good_list[i].good_number)+','+good_list[i].good_description+','+good_list[i].seller_ID+','+good_list[i].good_added_date+','+"onSale\n";
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
        if(input_balance==0){
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
        }
        
        for(int s=0;s<user_count;++s){
            if(user_list[s].user_ID==userID){
                user_list[s].user_balance=to_string(input_balance);
            }
        }
         for(int s=0;s<user_count;++s){
           if(user_list[s].user_ID==good_list[i].seller_ID){
                user_list[s].user_balance=to_string(stod(user_list[s].user_balance)+good_list[i].good_price*input_number);
            }
        }
    
        ifstream infile1;
		infile1.open("../files/user.txt", ios::in);
		if (!infile1.is_open()) exit(-1);
		char buf1[1024]; string sbuf1;
		infile1.getline(buf1,sizeof(buf1));
		sbuf1=sbuf1+buf1+'\n';
        for(int p=0;p<user_count;++p){
            if(user_list[p].user_state){
                sbuf1=sbuf1+user_list[p].user_ID+','+user_list[p].user_name+','+user_list[p].user_password+','+user_list[p].user_tel+','+user_list[p].user_address+','+user_list[p].user_balance+','+"active\n";
            }
            else{
                sbuf1=sbuf1+user_list[p].user_ID+','+user_list[p].user_name+','+user_list[p].user_password+','+user_list[p].user_tel+','+user_list[p].user_address+','+user_list[p].user_balance+','+"inactive\n";
            }
        }
        int templen1=sbuf1.length();
		sbuf1[templen1]='\0';
		cout<<sbuf1<<endl;
		infile1.close();
        fstream outfile1;
        outfile1.open("../files/user.txt",ios::out);
        //outfile<<endl;
        outfile1<<sbuf1;
        outfile1.close();
        string input_orderID;
        if(order_count>=99)input_orderID=to_string(+1);
        else if(order_count>=9)input_orderID="0"+to_string(order_count+1);
        else input_orderID="00"+to_string(order_count+1);
        orders temp;
        temp.order_ID="T"+input_orderID;temp.good_ID=good_list[i].good_ID;temp.order_unitprice=good_list[i].good_price;
        temp.order_number=input_number;temp.order_date=get_day();temp.seller_ID=good_list[i].seller_ID;temp.buyer_ID=userID;
        order_list[order_count]=temp;
        order_count++;
        fstream outfile2;
        outfile2.open("../files/order.txt",ios::out|ios::app);
        //outfile<<endl;
        outfile2<< temp.order_ID<<','<< temp.good_ID<<','<< temp.order_unitprice<<','<< temp.order_number<<','<< temp.order_date<<','<< temp.seller_ID<<','<< temp.buyer_ID<<endl;
        outfile2.close();
        string temp_time, temp_word;
		temp_time=get_time();
		//cout<<temp_time<<endl;
		temp_word="INSERT INTO order VALUES("+temp.order_ID+","+temp.good_ID+","+to_string(temp.order_unitprice)+","+to_string(temp.order_number)+","+temp.order_date+","+temp.seller_ID+","+temp.buyer_ID+")";
		write_sql_command(temp_time, temp_word);
		temp_time=get_time();
		//cout<<temp_time<<endl;
		temp_word="UPDATE commodity SET number ="+to_string(good_list[i].good_number)+" WHERE commodityID = "+temp.good_ID;
		write_sql_command(temp_time, temp_word);
    }
    else{
        cout<<"Not success. Balance not enough. You can recharge in the user self info. Back to the user menu... "<<endl; 
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
    string temp_time, temp_word;
	temp_time=get_time();
	//cout<<temp_time<<endl;
	temp_word="SELECT * FROM commodity WHERE commodityID = "+input_ID;
	write_sql_command(temp_time, temp_word);
}
void buyers::back_to_users(){
    cout<<"Back to the user menu..."<<endl;return;
}

double is_buy_success(string userID, string input_ID, int input_number){
    double input_balance=0;
    for(int i=0;i<user_count;++i){
        if(user_list[i].user_ID==userID){
            input_balance=stod(user_list[i].user_balance);
            for(int j=0;j<good_count;++j){
                if(good_list[j].good_ID==input_ID){
                    if(good_list[j].good_price*input_number<=input_balance) return (input_balance-good_list[j].good_price*input_number);
                    else return -1.0;
                }
            }
        }
    }
}

//*****************************************************************************************************************************

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
    //users UUU;
	//UUU.user_read();
    string input_new_name, input_price, input_number, input_descrip, input_balance, input_good_ID, input_yn;
    cout<<"Please enter the good's name:";
    cin>>input_new_name;
    cout<<"Please enter the price:";
    cin>>input_price;
    cout<<"Please enter the number:";
    cin>>input_number;
    cout<<"Please enter the description:";
    cin>>input_descrip; 
    cout<<"Please confirm the info."<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"good's name: "<<input_new_name<<endl;
    cout<<"good's price: "<<input_price<<endl;
    cout<<"good's number: "<<input_number<<endl;
    cout<<"good's description: "<<input_descrip<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"Please choose(y/n):";
	cin>>input_yn;
	if(input_yn[0]=='y'){  
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
void sellers::seller_change_goods_info(string userID){ 
    string input_ID, input_descript, input_new_name;
    int input_choice; double input_price;
    cout<<"Please enter the ID of the good you want to change:";
    cin>>input_ID;
    cout<<"Please enter the choice you want to change(1. price 2. description):";
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
	if(input_yn[0]=='y'){   
		string temp_time, temp_word;
		temp_time=get_time();
        if(input_choice==1){good_list[i].good_price=input_price;temp_word="UPDATE commodity SET price= "+to_string(input_price)+"WHERE good's ID= "+input_ID;}
        else if(input_choice==2){good_list[i].good_description=input_descript;temp_word="UPDATE commodity SET description= "+input_descript+"WHERE good's ID= "+input_ID;}
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
                if(good_list[i].good_state==1){
                    sbuf=sbuf+good_list[i].good_ID+','+good_list[i].good_name+','+to_string(good_list[i].good_price)+','+to_string(good_list[i].good_number)+','+good_list[i].good_description+','+good_list[i].seller_ID+','+good_list[i].good_added_date+','+"onSale\n";
                }
                else{
                    sbuf=sbuf+good_list[i].good_ID+','+good_list[i].good_name+','+to_string(good_list[i].good_price)+','+to_string(good_list[i].good_number)+','+good_list[i].good_description+','+good_list[i].seller_ID+','+good_list[i].good_added_date+','+"outSale\n";
                }
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

//*****************************************************************************************************************************************

void users::user_self_info(string userID){
    users U0;
    int choice;
	while (true) {
		//system("cls");
		U0.user_self_info_menu();
		cout << "Please enter a number:";
		cin >> choice;
		while (!cin) {
			cout << "Error! Please enter a number:";
			//cin.clear();
			//cin.sync();
			cin >> choice;
		}
		switch (choice) {
		case 1:U0.check_self_info(userID); break;
		case 2:U0.change_self_info(userID); break;
		case 3:U0.recharge(userID); break;
		case 4:U0.back_to_users(); return; break;
		default:cout << "Error! Please enter a number:" << endl; break;  ///////////////////////////////check enter 8!!!!!!!!!!!!!!!!!!!!!!!!!!
		}
	}
}

void users::user_self_info_menu(){
    cout << "=====================================================================================" << endl;
	cout << "1.check info 2.change info 3.recharge 4.back to user menu" << endl;
	cout << "=====================================================================================" << endl;
}

void users::check_self_info(string userID){  //TODO calculator
    string input_name, input_phone, input_address, input_balance;
    for(int i=0;i<user_count;++i){
        if(user_list[i].user_ID==userID){
            input_name=user_list[i].user_name;
            input_phone=user_list[i].user_tel;
            input_address=user_list[i].user_address;
            input_balance=user_list[i].user_balance;
        }
    }
    //input_balance=to_string(cal_balance(userID));
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
	cout<<"user's name: "<<input_name<<endl;
    cout<<"user's phoneNumber: "<<input_phone<<endl;
    cout<<"user's address: "<<input_address<<endl;
    cout<<"user's balance: "<<input_balance<<endl;
    cout << "-------------------------------------------------------------------------------------------------------------------------------------------------------------" << endl;
}
void users::change_self_info(string userID){
    int choice; string inputa;
    ifstream infile1;
    infile1.open("../files/user.txt", ios::in);
    if (!infile1.is_open()) exit(-1);
    char buf1[1024]; string sbuf1;
    infile1.getline(buf1,sizeof(buf1));
    sbuf1=sbuf1+buf1+'\n';
    cout<<"Please choos the info you want to change(1. user name 2. user phoneNumber 3. address):";
    cin>>choice;
    int q=0;
    for(q=0;q<user_count;++q){
        if(user_list[q].user_ID==userID){
            if(choice==1){
                cout<<"Please enter the new user name:"; cin>>inputa;
                for(int j=0;j<user_count;++j){
                    if(user_list[j].user_name==inputa && user_list[j].user_ID!=userID){cout<<"User name has already existed. Back to the user menu..."<<endl;infile1.close();return;}
                }
                user_list[q].user_name=inputa;
            }
            else if(choice==2){
                cout<<"Please enter the new user phoneNumber:"; cin>>inputa;user_list[q].user_tel=inputa;
            }
            else if(choice==3){
                cout<<"Please enter the new address:"; cin>>inputa;user_list[q].user_address=inputa;
            }
            else {cout<<"unvalid choice. Back to the user menu..."<<endl; infile1.close();return;}
            break;
        }
    }
        
    while (infile1.getline(buf1,sizeof(buf1))){
        string tempbuf=buf1;
        char *p;
        p=strtok(buf1,",");
        if(p==userID){
            if(user_list[q].user_state==1){
                sbuf1=sbuf1+user_list[q].user_ID+','+user_list[q].user_name+','+user_list[q].user_password+','+user_list[q].user_tel+','+user_list[q].user_address+','+user_list[q].user_balance+','+"active\n";
            }
            else{
                sbuf1=sbuf1+user_list[q].user_ID+','+user_list[q].user_name+','+user_list[q].user_password+','+user_list[q].user_tel+','+user_list[q].user_address+','+user_list[q].user_balance+','+"inactive\n";
            }
        }
        else sbuf1=sbuf1+tempbuf+'\n';
	}
    int templen1=sbuf1.length();
    sbuf1[templen1]='\0';
    cout<<sbuf1<<endl;
    infile1.close();
    fstream outfile1;
    outfile1.open("../files/user.txt",ios::out);
    //outfile<<endl;
    outfile1<<sbuf1;
    outfile1.close();
}
void users::recharge(string userID){
    string inputamount;
    double yourbalance; int q=0;
    cout<<"Please enter the amount you want to recharge:"; cin>>inputamount;
    for(q=0;q<user_count;++q){
        if(user_list[q].user_ID==userID){
            user_list[q].user_balance=to_string(stod(user_list[q].user_balance)+stod(inputamount));
            break;
        }
    }
    fstream outfile;
    outfile.open("../files/recharge.txt",ios::out|ios::app);
    //outfile<<endl;
    outfile<< userID<<','<< inputamount<<','<< get_day()<<endl;
    outfile.close();
    //yourbalance=cal_balance(userID);
    //yourbalance=stod(user_list[q].user_balance);
    ifstream infile1;
    infile1.open("../files/user.txt", ios::in);
    if (!infile1.is_open()) exit(-1);
    char buf1[1024]; string sbuf1;
    infile1.getline(buf1,sizeof(buf1));
    sbuf1=sbuf1+buf1+'\n';
    while (infile1.getline(buf1,sizeof(buf1))){
			string tempbuf=buf1;
			char *p;
        	p=strtok(buf1,",");
			if(p==userID){
               if(user_list[q].user_state==1){
                sbuf1=sbuf1+user_list[q].user_ID+','+user_list[q].user_name+','+user_list[q].user_password+','+user_list[q].user_tel+','+user_list[q].user_address+','+user_list[q].user_balance+','+"active\n";
                }
                else{
                    sbuf1=sbuf1+user_list[q].user_ID+','+user_list[q].user_name+','+user_list[q].user_password+','+user_list[q].user_tel+','+user_list[q].user_address+','+user_list[q].user_balance+','+"inactive\n";
                }
            }
			else sbuf1=sbuf1+tempbuf+'\n';
		}
    int templen1=sbuf1.length();
    sbuf1[templen1]='\0';
    cout<<sbuf1<<endl;
    infile1.close();
    fstream outfile1;
    outfile1.open("../files/user.txt",ios::out);
    //outfile<<endl;
    outfile1<<sbuf1;
    outfile1.close();
    cout<<"Successfully recharged. Your balance:"<<user_list[q].user_balance<<endl;
}
void users::back_to_users(){
    cout<<"Back to the user menu..."<<endl;return;
}
void users::user_logout(){
    cout<<"user logout. Back to the main menu..."<<endl; return;
}

double cal_balance(string userID){
    Stack s;
    Stack1 s1;
    string balance;
    string formula=get_formula(userID);
    balance=cal(formula, s, s1);
    return stod(balance);
}

string get_formula(string userID){
    string formula;
    ifstream infile;
	infile.open("../files/recharge.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf[1024];
    infile.getline(buf,sizeof(buf));
    int flag=0;
    //cout<<buf<<endl;
    while (infile.getline(buf,sizeof(buf)))
	{
        char *p;
        p=strtok(buf,",");
        if(p==userID){
            p = strtok(NULL, ",");
            if(!flag)
                {formula=formula+p;flag=1;}
            else formula=formula+"+"+p;
        }
    }
    infile.close();
    infile.open("../files/order.txt", ios::in);
	if (!infile.is_open()) exit(-1);
	char buf1[1024];
    infile.getline(buf1,sizeof(buf1));
    flag=0; 
    string uprice, unumber;
    //cout<<buf<<endl;
    while (infile.getline(buf1,sizeof(buf1)))
	{
        char *p, *p1;
        p=strtok(buf1,",");p = strtok(NULL, ",");
        p = strtok(NULL, ",");uprice=p;
        p = strtok(NULL, ",");unumber=p;
        p = strtok(NULL, ",");p = strtok(NULL, ",");p1 = strtok(NULL, ",");
        if(p==userID){
           formula=formula+"+"+uprice+"x"+unumber;
        }
        if(p1==userID){
            formula=formula+"-"+uprice+"x"+unumber;
        }
    }
    infile.close();
    cout<<formula<<endl;
    return formula;
}