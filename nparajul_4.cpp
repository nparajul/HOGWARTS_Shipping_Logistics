#include "Owl.h"
#include "VanishingCabinet.h"
#include "Griffin.h"
#include <iostream>
#include <string>
#include <ctime>
#include <iomanip>
#include <cstdlib>
#include <fstream>
#include <sstream>
#include<vector>

using namespace std;

void print_menu(); 										//displays the menu
size_t get_selection();										//gets the menu selection from the user
void schedule_new_delivery(vector<Delivery*> &ptr_list);					//adds a new delivery
string generate_id(int type);									//generates a random number from 0 to 99999
void display_all(vector<Delivery*> ptr_list); 							//displays all deliveries
void display_type(vector<Delivery*> ptr_list ); 						//displays deliveries of chossen type
void remove_delivery(vector<Delivery*> &ptr_list);						// removes a delivery
void load_delivery(vector<Delivery*> &ptr_list);						//loads deliveries from files
void save_delivery(vector<Delivery*> ptr_list);							//saves deliveries to files
string timestamp();										//returns the timestamp
bool check_duplicate_id(vector<Delivery*> ptr_list, string id);					//checks for duplicate id
void sort_deliveries(vector<Delivery*> &ptr_list);						// sorts deliveries
void shuffle_deliveries(vector<Delivery*> &ptr_list);						// randomly shuffles deliveries
void swap(int i, int j,vector<Delivery*> &ptr_list);						//swaps two elements of the vector

int main()
{
	srand(time(NULL));									//seeding the random number genrator
	vector<Delivery*> ptr_list;								//vector that stores the address of an object	
	size_t user_choice;

	do
	{
		print_menu();									//calling the function that displays menu
		user_choice = get_selection();							//storing user selection returned by the function

		if (user_choice == 1)
		{
			schedule_new_delivery(ptr_list);					//calling the function to schedule a new delivery
		}
		else if (user_choice == 2)
		{
			remove_delivery(ptr_list);						//calling the function to remove a delivery
		}
		else if (user_choice == 3)
		{
			load_delivery(ptr_list);						//calling load_delivery function
		}
		else if (user_choice == 4)
		{
			save_delivery(ptr_list);						//calling save_delivery function
		}
		else if (user_choice == 5)
		{
			display_all(ptr_list);						//calling the function that displays all scheduled deliveries
		}
		else if (user_choice == 6)
		{
			display_type(ptr_list);							// calling the function that displays deliveries by type
		}
		else if (user_choice == 7)
		{
			sort_deliveries(ptr_list);						// calling the function that sorts all the deliveries
		}
		else if(user_choice == 8)
		{
			shuffle_deliveries(ptr_list);						// calling the function that shuffles all the deliveries
		}
		else if (user_choice == 9)
		{
			for (int i = 0; i < ptr_list.size();i++)
			{
				ptr_list.pop_back();						//pops back all the elements from the vector
				delete ptr_list[i];					//deletes dynamically created memory when user quits the program
			}
			cout << endl << "Thank you for using HOGWARTS." << endl << endl;			// displaying exit message
			return 0;
		}
		else
		{
			continue;									//keep continuing 
		}
	} while (user_choice != 9);

	return 0;
}

void print_menu()
{
	//displays the menu to the user
	cout << endl;
	cout << "Please select from the following choices:" << endl;
	cout << "\t " << "(1) Schedule a new delivery." << endl;
	cout << "\t " << "(2) Remove a delivery." << endl;
	cout << "\t " << "(3) Load deliveries from a file." << endl;
	cout << "\t " << "(4) Save deliveries to file." << endl;
	cout << "\t " << "(5) Display all scheduled deliveries." << endl;
	cout << "\t " << "(6) Display deliveries by transportation type." << endl;
	cout << "\t " << "(7) Sort Deliveries." << endl;
	cout << "\t " << "(8) Shuffle Deliveries."<< endl;
	cout << "\t " << "(9) Quit." << endl;
}

size_t get_selection()
{
	//gets the user selection and returns the selection to main
	size_t selection;
	cout << "Selection: ";
	cin >> selection;

	if (selection > 9 || selection < 1)
	{
		cout << endl;
		cout << "Invalid Selection.Please select a number between 1 and 9 " << endl << endl;
	}

	return selection;
}

void schedule_new_delivery(vector<Delivery*> &ptr_list)
{
	char choice;									//variable that stores user chouice
	double weight;									//variable that stores the weight
	cout << endl;
	cout << "Schedule a new delivery" << endl;
	cout << "-----------------------" << endl;
	string input;
	// input user's name

	cout << "\t " << "Please enter the sender's name: ";
	cin.ignore();
	getline(cin, input);

	do
	{
		cout << "\t " << "Enter Weight (kgs): ";
		cin >> weight;

		if (weight <= 0)
		{
			cout << endl << "\t" << " " << "Invalid Selection.Please enter a valid weight." << endl << endl;
		}

	} while (weight <= 0);

	//asks and validates the shipping type 
	do
	{
		cout << "\t " << "Standard Shipping (Y/N)? ";
		cin >> choice;

		choice = tolower(choice);						// converting uppercase to lowercase
											
		if (choice != 'y' && choice != 'n')
		{
			cout << endl << "\t" << " " << "Invalid Selection.Please select Y for Yes and N for No." << endl << endl;
		}

	} while (choice != 'y' && choice != 'n');

	//asks and validates the weight

	if (choice == 'y'&& weight <= 1.58)
	{
		int type = 2;					//setting a type for Owl	
		string id;
		string time_stamp = timestamp();		//stores the thimestamp

		do
		{
			id = generate_id(type);			//stores the unique id
		} while (check_duplicate_id(ptr_list, id) == true);

		Owl* object = new Owl(input, time_stamp, weight, id);				//storing the information of the object
		ptr_list.push_back(object);							// storing the address in the array
	}

	else if (choice == 'y' && weight > 1.58)
	{
		int type = 3;					//setting a type for Griffin
		string id;
		string time_stamp = timestamp();		//stores the thimestamp

		do
		{
			id = generate_id(type);			//stores the unique id
		} while (check_duplicate_id(ptr_list, id) == true);

		Griffin* object = new Griffin(input, time_stamp, weight, id);			// storing the information of the object
		ptr_list.push_back(object);							// storing the address in the array
	}

	else
	{
		int type = 1;                           //setting a type for Vanishing Cabinet
		string time_stamp = timestamp();        //stores the thimestamp
		string id;

		do
		{
			id = generate_id(type);         //stores the unique id
		} while (check_duplicate_id(ptr_list, id) == true);

		VanishingCabinet* object = new VanishingCabinet(input, time_stamp, weight, id);         //storing the information of the object
		ptr_list.push_back(object);                                                     // storing the address in the array

	}


	cout << endl << "\t " << "New Delivery Scheduled Successfully" << endl;
}

string generate_id(int type)
{
	// receives the type and returns id accordingly based on the type

	if (type == 2)
	{
		string ret = "o";
		for (int i = 0;i < 3;i++)
		{

			int rand1 = rand() % 10;
			stringstream rand_id;
			rand_id << rand1;
			string final_id = rand_id.str();
			ret.append(final_id);
		}

		return ret;
	}

	else if (type == 3)
	{
		string ret = "g";
		for (int i = 0;i < 7;i++)
		{
			int rand1 = rand() % 10;
			stringstream rand_id;
			rand_id << rand1;
			string final_id = rand_id.str();
			ret.append(final_id);
		}
		return ret;
	}

	else
	{
		string ret = "-";
		string final_id;
		for (int i = 0;i < 8;i++)
		{
			int rand1 = rand() % 10;
			stringstream rand_id;
			rand_id << rand1;
			string first_part = rand_id.str();
			final_id.append(first_part);
		}

		final_id.append(ret);

		for (int i = 0;i < 8;i++)
		{
			int rand1 = rand() % 10;
			stringstream rand_id;
			rand_id << rand1;
			string second_part = rand_id.str();
			final_id.append(second_part);
		}
		return final_id;
	}
}

bool check_duplicate_id(vector<Delivery*> ptr_list, string id)
{
	//checks for duplicate ID

	for (int i = 0;i < ptr_list.size();i++)
	{
		if (id == (*ptr_list[i]).get_id())
		{
			return true;
		}
	}
	return false;
}

void display_all(vector<Delivery*> ptr_list)
{
	//displays all the deliveries

	cout << endl;
	cout << "All Deliveries " << endl;
	cout << "----------------" << endl;

	if (ptr_list.size() == 0)
	{
		cout << "\t" << "Nothing Scheduled" << endl;
		return;
	}

	// displays all the deliveries
	for (int i = 0;i < ptr_list.size();i++)
	{
		cout << "[" << i << "]";
		(*ptr_list[i]).print_info();
	}
}

void display_type(vector<Delivery*> ptr_list)
{

	//displays deliveries by type
	
	int type;								// gets user input
	cout << endl;
	cout << "All Deliveries " << endl;
	cout << "----------------" << endl;
	;
	if (ptr_list.size() == 0)						//if nothing is scheduled
	{
		cout << "\t" << "Nothing Scheduled" << endl;
		return;;
	}

	cout << endl;

	// user input and input validation
	do
	{
		cout << "Which type (1) Griffin, (2) Owl, (3) Vanishing Cabinet? ";
		cin >> type;

		if (type != 1 && type != 2 && type != 3)
		{
			cout << "\t" << "Invalid selection. Please select 1, 2 or 3." << endl << endl;
		}

	} while (type != 1 && type != 2 && type != 3);

	//displaying output based on user input

	if (type == 1)
	{
		for (int i = 0;i < ptr_list.size();i++)
		{
			if ((*ptr_list[i]).get_id()[0] == 'g')
			{
				cout << "[" << i << "]";
				(*ptr_list[i]).print_info();
			}
		}
	}

	else if (type == 2)
	{
		for (int i = 0;i < ptr_list.size();i++)
		{
			if ((*ptr_list[i]).get_id()[0] == 'o')
			{
				cout << "[" << i << "]";
				(*ptr_list[i]).print_info();
			}
		}
	}

	else
	{
		for (int i = 0;i < ptr_list.size();i++)
		{
			if (((*ptr_list[i]).get_id())[0] != 'o' && (((*ptr_list[i]).get_id())[0] != 'g'))
			{
				cout << "[" << i << "]";
				(*ptr_list[i]).print_info();
			}
		}
	}
	cout << endl;
}

void remove_delivery(vector<Delivery*> &ptr_list)
{
	cout << endl << "Remove a Delivery" << endl;
	cout << "------------------" << endl;

	if (ptr_list.size() == 0)
	{
		cout << "\t" << "Error: Nothing to remove" << endl;
		return;
	}

	display_all(ptr_list);

	int index;		// gets the index that has to be removed from the user

				//asks and validates the user
	do
	{
		cout << "\t" << "Which would you like to remove(enter the index) : ";
		cin >> index;

		if (index < 0 || index >(ptr_list.size()) - 1)			//printing error message
		{
			cout << endl << "\t" << "Invalid selection. Please enter a valid index from 0 to " << (ptr_list.size()) - 1 << endl << endl;
		}


	} while (index < 0 || index > (ptr_list.size()) - 1);

	//removing deliveries
	
	for (int i = index;i < (ptr_list.size()-1);i++)
	{
		ptr_list[i] = ptr_list[i + 1];
	}

	ptr_list.erase ( ptr_list.begin()+ptr_list.size()-1);
	
	cout << endl << "\t " << "Delivery Removed Successfully" << endl;
}

void load_delivery(vector<Delivery*> &ptr_list)
{
	cout << endl << "Load Deliveries From File" << endl;
	cout << "---------------------------" << endl << endl;

	ifstream myfile;							// declaring myfile(an object of type ifstream)
	string filename;							// gets the filename from the user

	cout << "\t" << "Name the .txt file from which you'd like to load the delivery information: ";
	cin.ignore();
	getline(cin, filename);

	myfile.open(filename.c_str());						// opening the file entered by user

	if (myfile.fail())							//display error message if file does not exist
	{
		cout << endl << "\t" << "The file does not exist." << endl;
		return;
	}

	string  everything;							//string that stores information from the file
	string  delimeter = ",";						//declaring a delimiter	
	size_t  pos = 0;							//initializing position of the delimiter
	string  name;								//string that stores name of sender 
	string  id;								// string that stores the ID
	string weight;								// string that stores the weight
	string timestamp;							// string that stores the timestamp
	while (!myfile.eof())							// loop that runs until the end the file
	{
		getline(myfile, everything);					//stores each line of infortmation from the file in the string everytime
		
		//declaring position of delimiter and running a loop that goes through the entire content of file
		while ((pos = everything.find(delimeter)) != string::npos)
		{


			id = everything.substr(0, pos);				// storing first part of the information,i.e.ID 				
			everything.erase(0, pos + delimeter.length());		// erasing the information that was stored
			pos = everything.find(delimeter);			// finding the next delimiter and storing its position

			
			name = everything.substr(0, pos);			// storing next part of the information,i.e.name
			everything.erase(0, pos + delimeter.length());		// erasing the information that was stored
			pos = everything.find(delimeter);			// finding the next delimiter and storing its position
			weight = everything.substr(0, pos);			// storing next part of the information,i.e. weight
			double result;						// declaring a double that stores the weight

						//converting the string token to double and storing it to result

			stringstream ss;					// copies information from weight(string) and stores it in result(double)
			ss << weight;						// taking information from weight
			ss >> result;						// copying information to result
			
			everything.erase(0, pos + delimeter.length());		// erasing the information that was stored
			pos = everything.find(delimeter);			// finding the next delimiter and storing its position
			everything.erase(0, pos + delimeter.length());		// erasing the information that was stored
			pos = everything.find(delimeter);			// finding the next delimiter and storing its position
		
			
			timestamp = everything.substr(0, pos);			// storing next part of the information,i.e. timestamp
			
			everything.erase(0, pos + delimeter.length());		// erasing the information that was stored


				//storing information based on ID
			if (id[0] == 'o')
			{
				Owl* object = new Owl(name, timestamp, result, id);
				ptr_list.push_back(object);
			}

			else if (id[0] == 'g')
			{
				Griffin* object = new Griffin(name, timestamp, result, id);
				ptr_list.push_back(object);
			}

			else
			{
				VanishingCabinet* object = new VanishingCabinet(name, timestamp, result, id);
				ptr_list.push_back(object);
			}

			 				// increasing the number of deliveries

		}
	}
	myfile.close();								// closes the file

	cout<<endl<<"All deleveries loaded successfully."<<endl;
}

void save_delivery(vector<Delivery*> ptr_list)
{
	cout << endl << "Save Deliveries To File" << endl;
	cout << "-------------------------" << endl << endl;
	ofstream myfile;							// declaring myfile(an object of type ofstream)
	string filename;							// gets the filename from the user
	cout << endl << "\t " << "Name of the .txt file where you'd like to save delivery information: ";
	cin.ignore();
	getline(cin, filename);

	myfile.open(filename.c_str());						// opening the file entered by user


						// storing all the information to the file entered by the user



	for (int i = 0;i < ptr_list.size();i++)
	{
		if ((*ptr_list[i]).get_id()[0] == 'g')
		{
			myfile << (*ptr_list[i]).get_id();
			myfile << "," << (*ptr_list[i]).get_sender_name() << ",";
			myfile << (*ptr_list[i]).get_weight() << ",";
			myfile << "Standard-Griffin" << ",";
			myfile << (*ptr_list[i]).get_time_stamp()<<endl;
		}

		else if ((*ptr_list[i]).get_id()[0] == 'o')
		{
			myfile << (*ptr_list[i]).get_id();
			myfile << "," << (*ptr_list[i]).get_sender_name() << ",";
			myfile << (*ptr_list[i]).get_weight() << ",";
			myfile << "Standard-Owl" << ",";
			myfile << (*ptr_list[i]).get_time_stamp()<<endl;

		}

		else
		{
			myfile << (*ptr_list[i]).get_id();
			myfile << "," << (*ptr_list[i]).get_sender_name() << ",";
			myfile << (*ptr_list[i]).get_weight() << ",";
			myfile << "Vanishing Cabinet" << ",";
			myfile << (*ptr_list[i]).get_time_stamp()<<endl;
		}
	}
	myfile.close();									// closing the file
	cout << "\t " << "Deliveries Successfully Saved" << endl;			// displaying confirmation msg

}

string timestamp()
{
	//creates a timestamp and returns it
	time_t rawtime;
	tm * timeinfo;

	time(&rawtime);
	timeinfo = localtime(&rawtime);
	string time_stamp = asctime(timeinfo);
	return time_stamp.substr(0, time_stamp.length() - 1);			//to avoid the new line at the end
}

void sort_deliveries(vector<Delivery*> &ptr_list)
{
	//bubble sorts the deliveries

	int j=0;
	int k;
	
	for(int i=0;i<ptr_list.size();i++)
	{
		char id= (*ptr_list[i]).get_id()[0];
		
		if(id=='o')
		{
			swap(j,i,ptr_list);
					
			if(j>0)
			{
				for(k=0;k<j;k++)
				{
					if((*ptr_list[j]).get_id()<(*ptr_list[k]).get_id())
					{
						swap(j,k,ptr_list);
					}

				}
			}
			j++;				
		}
	}
	int c=j;
	for(int i=0;i<ptr_list.size();i++)
	{
		char id=(*ptr_list[i]).get_id()[0];
		
		if(id=='g')
		{
			swap(j,i,ptr_list);
			if(j>c)
			{
				for(k=c;k<j;k++)
				{
					if((*ptr_list[j]).get_id()<(*ptr_list[k]).get_id())
					{
						swap(j,k,ptr_list);
					}
				}
			}
			j++;				
		}
	}
	
	c=j;
	for(int i=0;i<ptr_list.size();i++)
	{
		char id= (*ptr_list[i]).get_id()[0];

		if(id!='o'&& id!='g')
		{
			swap(j,i,ptr_list);
			if(j>c)
			{
				for(k=c;k<j;k++)
				{
					if((*ptr_list[j]).get_id()<(*ptr_list[k]).get_id())
					{
						swap(j,k,ptr_list);
					}
				}
			}
			j++;
		}
	}
	cout<<endl<<"\tDeliveries Sorted Successfully"<<endl;
}

void shuffle_deliveries(vector<Delivery*> &ptr_list)
{
	//randomly shuffles all the deliveries
	
	for (int i=0; i<ptr_list.size(); i++)
	{
        	int r = rand() % (ptr_list.size());  // generate a random position
            	Delivery* temp = ptr_list[i];
		ptr_list[i] = ptr_list[r];
		ptr_list[r] = temp;
	}
	 cout<<endl<<"\tDeliveries Shuffled Successfully"<<endl;
}

void swap(int i, int j,vector<Delivery*> &ptr_list)
{
	//swaps two elements of the vector
	Delivery* temp;	
	temp=ptr_list[i];
        ptr_list[i]=ptr_list[j];
        ptr_list[j]=temp;
}
