// Standard.h
#ifndef STANDARD_H
#define STANDARD_H

using namespace std;
#include "Delivery.h"



class Standard:public Delivery
{
  	double weight;							// stores weight

protected:
	Standard();							// default constructor
	Standard(string name, string time_stamp, double weight);	// overloaded constructor

public:
	double get_weight();						// weight accesoor
	void set_weight(double weight);					// weight mutator
	void print_info();						// prints weight				
	virtual string get_id();					// virtual function get_id
};

#endif


