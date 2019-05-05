// Owl.cpp
// using namespace std;
//#include "Owl.h"
#include "Owl.h"



Owl::Owl():Standard()
	{
		this->id = "o";
	}
Owl::Owl(string name, string time_stamp, double weight, string 	id) :Standard(name, time_stamp, weight)
	{
		this->id = id;
	}
	
string Owl:: get_id()
	{

		return this->id;
	}
void Owl::print_info() 
	{
		Standard::print_info();
		cout << this->id << " Standard-Owl " <<Delivery::get_time_stamp()<<endl;
	}
