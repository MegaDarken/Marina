//This is the "Program.cpp" file
//Include(s) 
#ifndef MARNIA_L
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
#include <string>
#include <sstream>
#endif // !MARNIA_L

#ifndef MARNIA_H
#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

#include "Data.h"
#include "userInput.h"

using namespace std;

//Constants
const char ExitMenuCharacter = '4';

const char RecordBookingCharacter = '1';
const char DeleteBookingCharacter = '2';
const char DisplayRecordsCharacter = '3';

const int MarinaLengthMeters = 150;//As defined in brief

//Menu Methods
void showMenu(void)
{
	//Title
	cout << "MARINA BERTH BOOKING SYSTEM" << endl;

	//Print out options
	cout << "1) record a new booking" << endl;
	cout << "2) delete a record" << endl;
	cout << "3) display all records (and available marina space)" << endl;

	//Debug options
	cout << "s) Save Booking Records" << endl;
	cout << "l) Save Booking Records" << endl;

	cout << ExitMenuCharacter << ") exit the program" << endl;
};

void runMenu(void)
{
	char userInput = ' ';

	//Loop until exiting

	while (userInput != ExitMenuCharacter)
	{
		//display Menu
		showMenu();

		//Indicate that user can input now
		cout << ">";

		//Get new user input
		cin >> userInput;

		switch (userInput)
		{
		default:
			cout << "Invalid Input, Please try again..." << endl;
			break;
		case ExitMenuCharacter:
			cout << "Exiting...";
			break;
		case RecordBookingCharacter:
			cout << "Recording new booking..." << endl;
			//Recording new booking
			userInput::userRecordBooking(Data::getBookingRecords());
			break;
		case DeleteBookingCharacter:
			cout << "Deleting a record..." << endl;
			//Deleting a record
			userInput::userRecordDelete(Data::getBookingRecords());
			break;
		case '3':
			cout << "Displaying all records..." << endl;
			//Displaying all records
			userInput::viewRecords(Data::getBookingRecords());
			//Data::showBookingRecords();
			break;

		case 's':
			cout << "Saving Bookings to File..." << endl;
			//Saveing bookings to file
			Data::saveBookingRecords();
			break;
		case 'l':
			cout << "Loading Bookings from File..." << endl;
			//Loading bookings from file
			Data::loadBookingRecords();
			break;
		}
	}
}



int main(void)
{
	Data::getBookingRecords()->InsertEntry(Booking());
	Data::getBookingRecords()->InsertEntry(Booking());
	Data::getBookingRecords()->InsertEntry(Booking());

	runMenu();//Menu is displayed to the user and traverced

	//Pausing Before Closing

	//cout << "Press any key..."
	//char exitChar = ' ';
	//cin >> exitChar;//system("pause");//Windows

	return 0;
}
