// VanishingCabinet.h
#ifndef VANISHINGCABINET_H
#define VANISHINGCABINET_H

#include "Delivery.h"

class VanishingCabinet: public Delivery
{
  	double weight;									// stores weight		
	string id;									// stores id

public:
	VanishingCabinet();								// default constructor
	VanishingCabinet(string name, string time_stamp, double weight, string id);	// overloaded constructor
	double get_weight();								// weigth accessor
	void set_weight(double weight);							// weigth mutator
	string get_id();								// id accesoor
	void print_info();								// prints delivery information

};

#endif




