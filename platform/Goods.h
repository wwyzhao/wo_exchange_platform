#ifndef GOODS_H
#define GOODS_H
class goods {
	string good_name;
	string good_ID;
    string good_price;
    int good_count;
public:
	goods(){

	} /////////////////////////////////goods() ~goods!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void good_description();
	bool good_added_time();
	void good_state();
	void seller_ID();  ////////////////////////friend?!!!!!!!!!!!!!!!!!!!

};

void good_module();
#endif // GOODS_H

