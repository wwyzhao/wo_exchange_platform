#include<iostream>
#include<string>
using namespace std;
#ifndef GOODS_H
#define GOODS_H

class goods {
	string good_name;
	string good_ID;
    double good_price;
    int good_number;
	string good_description;
	string seller_ID;
	string good_added_date;
	bool good_state;
public:
	goods(){

	} /////////////////////////////////goods() ~goods!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void good_read();
	void good_show();
	//void good_description();
	bool good_added_time();
	//void good_state();
	//void seller_ID();  ////////////////////////friend?!!!!!!!!!!!!!!!!!!!

};
extern goods good_list[100];
extern int good_count;
extern const char* good_title[8];
void good_module();
#endif // GOODS_H
