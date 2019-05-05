// Owl.h
#ifndef OWL_H
#define OWL_H

#include "Standard.h"

class Owl: public Standard
{
	string id;									// string that stores id for type Owl

public:
	Owl();										// default constructor
	Owl(std::string name, std::string time_stamp, double weight, string id); 	//overloaded constructor
	string get_id();								//accessor
	void print_info();								// prints delivery information
};

#endif

