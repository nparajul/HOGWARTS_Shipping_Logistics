// Delivery.h
#ifndef DELIVERY_H
#define DELIVERY_H

#include<iostream>
#include<string>
using namespace std;

class Delivery
{
  	string sender_name;				//stroes sender hname
	string timestamp;				//stores timestamp

protected:
	Delivery();					// default contructor
	Delivery(string name, string time_stamp);	// overloaded constructor
public:
	string get_time_stamp();			// timestamp accessor
	string get_sender_name();			// sender name accessor
	void set_name(string name);			// name mutator
	virtual void print_info();			// prints delivery info
	virtual string get_id();			// id accessor
	virtual double get_weight();			// weight accessor
	virtual void set_weight(double weight);		// weight mutator
};

#endif
