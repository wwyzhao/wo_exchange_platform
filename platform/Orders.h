#ifndef ORDERS_H
#define ORDERS_H
class orders {
	string order_ID;
    string good_ID;  ////////////////////friend?!!!!!!!!!!!!!!!!
public:
	orders(){

	} /////////////////////////////////orders() ~orders!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!
	void exchange_price();
	bool order_description();
	void exchange_date();
	void seller_ID();  ////////////////////////friend?!!!!!!!!!!!!!!!!!!!
	void buyer_ID();  ////////////////////////friend?!!!!!!!!!!!!!!!!!!!
};

void order_module();
#endif // ORDERS_H
