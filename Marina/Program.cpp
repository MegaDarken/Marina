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

#include "MotorBoat.h"
#include "NarrowBoat.h"
#include "SailingBoat.h"
#endif // !MARNIA_H

#include "Data.h"
#include "userInput.h"

using namespace std;

//Constants
const char ExitMenuCharacter = '4';

const char RecordBookingCharacter = '1';
const char DeleteBookingCharacter = '2';
const char DisplayRecordsCharacter = '3';

const char SaveRecordsCharacter = 's';
const char LoadRecordsCharacter = 'l';

const char ViewMarinaCharacter = 'm';
const char ViewHoldingCharacter = 'h';

const char DebugMoveMarinaToHoldingCharacter = '>';
const char DebugMoveHoldingBackCharacter = '<';
const char DebugMoveMarinaEjectCharacter = '^';

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
	cout << "l) Load Booking Records" << endl;

	cout << "m) View Marina craft" << endl;
	cout << "h) View Holding craft" << endl;

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
		int tempInt = 0;

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
			userInput::userRecordBooking(Data::getBookingRecords(), Data::getMarinaCraftList());
			break;
		case DeleteBookingCharacter:
			cout << "Deleting a record..." << endl;
			//Deleting a record
			userInput::userRecordDelete(Data::getBookingRecords());
			break;
		case DisplayRecordsCharacter:
			cout << "Displaying all records..." << endl;
			//Displaying all records
			userInput::viewRecords(Data::getBookingRecords());
			//Data::showBookingRecords();
			//Areas of Marina
			userInput::viewMarina(Data::getMarinaCraftList());
			userInput::viewHolding(Data::getHoldingCraftList());
			break;
		//Debug options
		case SaveRecordsCharacter:
			cout << "Saving Bookings to File..." << endl;
			//Saveing bookings to file
			Data::saveBookingRecords();
			break;
		case LoadRecordsCharacter:
			cout << "Loading Bookings from File..." << endl;
			//Loading bookings from file
			Data::loadBookingRecords();
			break;
		case ViewMarinaCharacter:
			userInput::viewMarina(Data::getMarinaCraftList());
			break;
		case ViewHoldingCharacter:
			userInput::viewHolding(Data::getHoldingCraftList());
			break;
		case DebugMoveMarinaToHoldingCharacter:
			cout << "DEBUG: moving Marina to Holding..." << endl;
			userInput::takeInputInt("Crafts number moving:", &tempInt);
			Data::moveBackCraftsToHolding(tempInt);
			break;
		case DebugMoveHoldingBackCharacter:
			cout << "DEBUG: returning Holding to Marina..." << endl;
			Data::moveCraftsFromHoldingToBack();
			break;
		case DebugMoveMarinaEjectCharacter:
			cout << "DEBUG: Ejecting craft from Marina..." << endl;
			Data::ejectFrontCraftFromMarina();
			break;
		}
	}
}



int main(void)
{
	//Load in Booking Records
	//Data::loadBookingRecords();

	runMenu();//Menu is displayed to the user and traverced

	//Pausing Before Closing

	//cout << "Press any key..."
	//char exitChar = ' ';
	//cin >> exitChar;//system("pause");//Windows

	return 0;
}
