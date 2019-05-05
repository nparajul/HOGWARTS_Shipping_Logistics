// VanishingCabinet.cpp
#include "VanishingCabinet.h"



VanishingCabinet::VanishingCabinet():Delivery()
{
	this->id = "-";
}
VanishingCabinet::VanishingCabinet(string name, string 	time_stamp, double weight, string id):Delivery(name,time_stamp)
{
	this->weight = weight;
	this->id = id;
}
double VanishingCabinet::get_weight()
{
	Delivery::get_weight();
	return this->weight;
}
void VanishingCabinet::set_weight(double weight)
{
	this->weight = weight;
}
	
string VanishingCabinet::get_id()
{
	Delivery::get_id();
	return this->id;
}
void VanishingCabinet::print_info()
{
	Delivery::print_info();
	cout << this->id << " Vanishing Cabinet "<< Delivery::get_time_stamp()<<endl;
}
