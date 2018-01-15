/*
HOO Condominium has 3 BBQ pits available for booking by its residents. 
You are tasked to design and develop a program to allow the user to book a pit given a reservation date. 
If there is no available pit on the given reservation date, the user is prompt to re-enter the date or enter “E” to exit the system. 
You are required to use the following given data structures and variables for the program.
*/

#include <iostream>
#include <string>
#include <time.h>
#include <iomanip>

using namespace std;

struct BBQ 
{
	int BBQNumber; //Pit Number
	string cal_date; // calendar date
	bool available; // status of pit - true if available for booking
};

struct Details 
{
	string ID; // Booking ID
	string name; //Name of resident
	string addr; //Address of resident
	string rdate; //Reservation date of pit
	double fees; //$$ charged for the pit
};

struct Booking
{
	Details booking_details; 
	BBQ pit;
};

struct tm time_structure;  you do not need to do this!!

const int CONST_NUMBER_OF_DAYS_PER_YEAR = 365;
const int CONST_NUMBER_OF_MONTHS_PER_YEAR = 12;
const int CONST_SIZE = 3;//represents the number of bbq pits 
const string CONST_SINGLE_BLANK_SPACE = " ";

Booking b; //booking of pit
BBQ pits[CONST_NUMBER_OF_DAYS_PER_YEAR][CONST_SIZE]; //2-D array that store the pits information for the year

void createTMStruct(struct tm &tm) {
	//purpose: to obtain current time and date in the form of struct

	//64bit for time_t using arithmetic to represent time
	__time64_t long_time;
	//in 64bit returns the number of seconds elapsed since midnight (00:00:00), January 1, 1970, Coordinated Universal Time (UTC)
	_time64(&long_time);

	//converts time value and corrects for the local time zone
	//fills in the first param(tm time structure) using the second param as reference point of time
	_localtime64_s(&tm, &long_time);
}

void initialize() {
	//purpose: initialize the values for 2-D array (pits)
	
	int array_calendar_number_of_days_per_month[CONST_NUMBER_OF_MONTHS_PER_YEAR] = {31,28,31,30,31,30,31,31,30,31,30,31};
	string array_calendar_month_name[CONST_NUMBER_OF_MONTHS_PER_YEAR] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	int day_counter = 0;
	//initialize the current date obtain from system
	createTMStruct(time_structure);

	for (int array_month_counter = 0; array_month_counter < CONST_NUMBER_OF_MONTHS_PER_YEAR; array_month_counter++) {
		for (int array_day_counter = 0; array_day_counter < array_calendar_number_of_days_per_month[array_month_counter]; array_day_counter++) {
			//loop for the number of bbq pits
			for (int inner_loop_counter = 0; inner_loop_counter < CONST_SIZE; inner_loop_counter++) {
				//3 bbq pits
				//each time create a new bbq struct object and store into the array
				BBQ struc_bbq_identification = {};
				//initialize the value in bbq struct

				struc_bbq_identification.BBQNumber = inner_loop_counter + 1;
					
				if(array_day_counter > 2){
					struc_bbq_identification.cal_date =  to_string(array_day_counter + 1) + "th" + CONST_SINGLE_BLANK_SPACE + array_calendar_month_name[array_month_counter] + CONST_SINGLE_BLANK_SPACE + to_string((time_structure.tm_year + 1900)) ;
				}
				else if (array_day_counter == 2) {
					struc_bbq_identification.cal_date = to_string(array_day_counter + 1) + "rd" + CONST_SINGLE_BLANK_SPACE + array_calendar_month_name[array_month_counter] + CONST_SINGLE_BLANK_SPACE + to_string((time_structure.tm_year + 1900));
				}
				else if (array_day_counter == 1) {
					struc_bbq_identification.cal_date = to_string(array_day_counter + 1) + "nd" + CONST_SINGLE_BLANK_SPACE + array_calendar_month_name[array_month_counter] + CONST_SINGLE_BLANK_SPACE + to_string((time_structure.tm_year + 1900));
				}
				else if (array_day_counter == 0) {
					struc_bbq_identification.cal_date = to_string(array_day_counter + 1) + "st" + CONST_SINGLE_BLANK_SPACE + array_calendar_month_name[array_month_counter] + CONST_SINGLE_BLANK_SPACE + to_string((time_structure.tm_year + 1900));
				}
				struc_bbq_identification.available = true;
				pits[day_counter][inner_loop_counter] = struc_bbq_identification;
			}
			day_counter++;
		}
	}
	//initialize some data to simulate that the bbq pit has been booked
	pits[0][0].available = false;
	pits[0][1].available = false;
	pits[1][0].available = false;
}

BBQ findBBQ(string reservation_date) {
	//purpose: find the available BBQ pit for booking
	//precondition: using the given reservation_date to do look up BBQ pits dataset
	//postcondition: returns the structure record of type BBQ 

	//use the string class tokenization methods

	int counter_bbq_not_available = 0;

	//starting to look up through pits array, firstly we need to loop through the first dimension
	for (int loop_counter = 0; loop_counter < CONST_NUMBER_OF_DAYS_PER_YEAR; loop_counter++)
	{
		for (int inner_loop_counter = 0; inner_loop_counter < CONST_SIZE; inner_loop_counter++) {
			//retrieve the BBQ data structure stored in pits array 
			BBQ retrieved_bbq_information = pits[loop_counter][inner_loop_counter];
			//compare both strings if identical continue else keep searching
			if (retrieved_bbq_information.cal_date.compare(reservation_date) == 0) {
				if (retrieved_bbq_information.available == true)
				{
			//return the bbq data structure if system have found the bbq pit for this
					//particular date if available
					return retrieved_bbq_information;
				}
				else
				{
					//counter for counting the number of bbq not available
					++counter_bbq_not_available;
				}
				if (counter_bbq_not_available == 3) {
					//when the counter reach 3, new BBQ structure will be created
					BBQ BBQ_Not_Available = {};  this should be done at the start of the function

					//and BBQNumber in the new BBQ Structure will be set to 0
					BBQ_Not_Available.BBQNumber = 0;
					//populate all remaining data for completeness
					BBQ_Not_Available.cal_date = retrieved_bbq_information.cal_date;
					BBQ_Not_Available.available = retrieved_bbq_information.available;
					return BBQ_Not_Available;
				}
			}
		}
	}

} 

void bookBBQ(Details reservation_details, BBQ pit_information) {
	//purpose: Books the BBQ pit and record the BBQ pit status to the system
	//precondition: User will key in personal particular and bbq pit information which system requires 
	//postcondition: System will update the pit array for the updated status of BBQ pit 

	b = {reservation_details, pit_information};
	
	for (int loop_counter = 0; loop_counter < CONST_NUMBER_OF_DAYS_PER_YEAR; loop_counter++)
	{
		for (int inner_loop_counter = 0; inner_loop_counter < CONST_SIZE; inner_loop_counter++) {
			BBQ retrieved_bbq_information = pits[loop_counter][inner_loop_counter];
			//compare both strings if identical continue else keep searching
			if (retrieved_bbq_information.cal_date.compare(b.pit.cal_date) == 0 && retrieved_bbq_information.cal_date.compare(b.booking_details.rdate) == 0) {
				if (retrieved_bbq_information.available == true)
				{
					//set the bbq pit to false
					retrieved_bbq_information.available = false;
					//update the booking struct in main function
					b.pit = retrieved_bbq_information;
					//update pits array with updated bbq pit information
					pits[loop_counter][inner_loop_counter] = retrieved_bbq_information;
				//after all the required task have completed, exit this function
					return;
				}
			}
		}
	}
}

int main() 
{
	initialize();

	string user_input;

	BBQ bbq_data;
	Details user_details;

	while (true) 
	{
		//if user keys in 'E', exit the program

		cout << "Enter the reservation date: ";
		getline(cin, user_input);
		
		//detect any user input for "E", if user input "E" exit this program
		if (user_input == "E")
		{
			return 0;
		}
		
		//system will search for available bbq based on reservation date specified by user
		//a bbq data structure will be returned after a search in pits array
		bbq_data = findBBQ(user_input);
		//if the bbqnumber is not 0 then break out of this while loop
		if (bbq_data.BBQNumber != 0)
		{
			break;
		}
		else if (bbq_data.BBQNumber == 0)
		{
			cout << "No available BBQ pit on selected date, please re-enter another date or 'E' to exit." << endl;
		}
	}

	user_details.rdate = user_input;

	cout << "Enter Booking ID: ";
	cin >> user_details.ID;

	cout <<"Enter name: ";
	cin >> user_details.name;

	cout << "Enter address: ";
	cin >> user_details.addr;

	
	cout << "Enter the fees: ";
	cin >> user_details.fees;
	
	//after user key in booking details and user particulars, system will proceed to book the bbq
	bookBBQ(user_details, bbq_data);
	
	cout << endl << endl;
	//prints out the finalized booking details 
	cout << "Booking ID & Name: " << b.booking_details.ID << "," << "\t" << b.booking_details.name << endl;
	cout << "Pit Number & Date: " << b.pit.BBQNumber << "," << "\t" << b.pit.cal_date << endl;
	return 0;
}