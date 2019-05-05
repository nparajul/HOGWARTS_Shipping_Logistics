// Standard.cpp
#include "Standard.h"

Standard::Standard():Delivery()
{

}
		
Standard::Standard(string name, string time_stamp, double weight):Delivery(name,time_stamp)
{
		this->weight = weight;
}

double Standard::get_weight()
{
	Delivery::get_weight();
	return this->weight;
}
void Standard::set_weight(double weight)
{
	this->weight = weight;
}
void Standard::print_info()
{
	Delivery::print_info();
}
string Standard::get_id()
{
	Delivery::get_id();
	return " ";
}
	
