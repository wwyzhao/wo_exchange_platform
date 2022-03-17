#include "Users.h"
#include<fstream>
#include<string.h>
#include<stdlib.h>
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