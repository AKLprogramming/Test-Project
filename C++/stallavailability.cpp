/*

Examine the given 2-Dimensional array, information and answer questions that follows.
Mr. Lim has 3 hawker stalls that are expected to operate from Monday to Saturday. Some stalls are closed due to cleaning or renovation. You are tasked to design and develop a program that display a menu, allows the user to select their menu choice and invoke the respective function for each menu choice. See Part (a) to (d) for more details.
The status of the respective stall is as shown in Table 3.1. The 2-D array below is used to convey this information.
Int stalls [3][6]  = {1,0,0,0,1,1,
		    1,1,1,1,1,1,
		    0,0,0,1,1,1};

*/


#include <iostream>
#include <iomanip>
#include <string>
#include <limits>

using namespace std;

//for code readability, a name has been given for these digit
//for defining the status of the store
#define OPEN 1
#define CLOSE 0
//definition of the maximum value for array
#define MAX_NUMBER_OF_STALLS 3
#define MAX_NUMBER_OF_WORKING_DAYS_PER_WEEK 6

int stalls[MAX_NUMBER_OF_STALLS][MAX_NUMBER_OF_WORKING_DAYS_PER_WEEK] = { 1,0,0,0,1,1,
																		  		        1,1,1,1,1,1,
																		  			0,0,0,1,1,1 };

string day_array[MAX_NUMBER_OF_WORKING_DAYS_PER_WEEK] = { "Mon","Tues","Wed","Thurs","Fri","Sat" };


int displayMenu() {
//purpose: Display menu of options and validate user input within the range of 1 - 3
	
	int user_menu_input;

	while(true){
		cout << "1. Display all stalls" << endl;
		cout << "2. Display the stalls opened on given day" << endl;
		cout << "3. Exit" << endl;
		cout << "Enter your choice: " ;
		cin >> user_menu_input;
		
		if (user_menu_input >= 1 && user_menu_input <= 3){
			return user_menu_input;
		}
		else {
			cout << "Valid choices are 1 to 3, please re-enter.." << endl;
		}
	}
} 

void displayStalls() {
	//purpose: displays the result of all stalls' status whether they are open or closed
	
	for (int start_counter = 0; start_counter < (MAX_NUMBER_OF_STALLS + 1); start_counter++) {

		//leaving blank on the first box on first row
		if (start_counter == 0) {
			cout << "\t";
		}
		else {
			//print out the label for stall identification
			cout << "Stall " << start_counter << "\t";
		}

		//after the first row have been taken care of, we will proceed to populate the rest of the data
		for (int loop_counter = 0; loop_counter < (MAX_NUMBER_OF_WORKING_DAYS_PER_WEEK); loop_counter++) {
			//to populate the first column of data with day of the week
			if (start_counter == 0) {
				cout << day_array[loop_counter] << "\t";
			}
			else {
				//a constant 'OPEN' is represented by integer 1 
				//which means the stall is open based on the data on stalls array 
				//and 'CLOSE' is represented by integer 0
				if (stalls[(start_counter - 1)][(loop_counter)] == OPEN) {
					cout << "open";
				}
				else {
					cout << "close";
				}
				cout << "\t"; //for each column of data added, append \t :tab to make the alignment 
			}
		}
		//at this point, this means that system have printed all necessary data from one row in array
		//therefore, system should add a new row on GUI
		cout << endl;
	}
} 

void findStalls(int d) {
	//purpose: to find out the stall status for the particular day specified by user
	
	//this variable was declared for the sake of clarity 
	int user_selection = d;

	//to display result only stalls that are opened on that day specified by user
	for (int start_counter = 0; start_counter < MAX_NUMBER_OF_STALLS; start_counter++) {
		//the array starts with initial value of 0 therefore 
		if (stalls[start_counter][(user_selection - 1)] == 1) {
			cout << "Stall " << (start_counter + 1) << " is open. " << endl;
		}
	}
} 


int main() {

	int user_input;
	user_input = displayMenu();

	if (user_input == 3) {
		return 0;
	}
	else if (user_input == 1) {
		displayStalls();
	}
	else if (user_input == 2) {
		while(true){
			cout << "Enter 1 - 6 : ";
			cin >> user_input;

			if(user_input >= 1 && user_input <= 6){
				findStalls(user_input);
				break;
			}
			cout << "Please key in a value within (1 - 6)" << endl;
		}
	}
	return 0;
}