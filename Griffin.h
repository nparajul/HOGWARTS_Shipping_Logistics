// Griffin.h
#ifndef GRIFFIN_H
#define GRIFFIN_H
#include "Standard.h"



class Griffin: public Standard
{
  	string id;								// stores id for type Griffin

public:
	Griffin();								// default constructor	
	Griffin(string name, string time_stamp, double weight, string id);	// overloaded constructor
	string get_id();							// id accessor
	void print_info();							// prints delivery information
};

#endif



