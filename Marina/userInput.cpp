#include "userInput.h"



//const std::string CraftTypeMotorBoat = MotorBoat::getCraftType();
//const std::string CraftTypeNarrowBoat = NarrowBoat::getCraftType();
//const std::string CraftTypeSailingBoat = SailingBoat::getCraftType();


//Taking Input(s)
void userInput::takeInputChar(const char* prompt, char* returnedInput)
{
	//Prompt user
	std::cout << prompt;

	//Remove Prompt from input
	std::cin.clear();

	//Take input
	std::cin.getline(returnedInput,12); //returnedInput;
}

void userInput::takeInputCharString(const char* prompt, std::string* returnedInput)
{
	//Clear non-digits from input buffer
	/*if (std::cin.peek() == '\n')
	{
		std::cin.ignore();
	}*/

	//Prompt user
	std::cout << prompt;

	//Remove Prompt from input
	std::cin.clear();

	if (std::cin.peek() == '\n')
	{
		std::cin.ignore(10000, '\n');
	}
	
	//Take input
	std::getline(std::cin, *returnedInput);

	return;
}

void userInput::takeInputString(const std::string* prompt, std::string* returnedInput)
{
	takeInputCharString((char*)prompt, returnedInput);
}

void userInput::takeInputInt(const char* prompt, int* returnedInput)
{
	//Prompt user
	std::cout << prompt;

	//Remove Prompt from input
	std::cin.clear();

	//Take input
	std::cin >> *returnedInput;

	return;
}

void userInput::takeInputIntInRange(const char* prompt, int* returnedInput, int upperLimit, int lowerLimit)
{
	//if upper is below lower
	if (upperLimit < lowerLimit)
	{
		std::cerr << "takeInputIntInRange upper less than lower - parameters invalid";

		return;
	}

	//set value to outside limit
	int returnedValue = (lowerLimit - 1);

	while (returnedValue < lowerLimit || returnedValue > upperLimit)
	{
		//Prompt user
		std::cout << prompt;

		//Remove Prompt from input
		std::cin.clear();

		//Take input
		std::cin >> *returnedInput;

		if (returnedValue < lowerLimit || returnedValue > upperLimit)
		{
			std::cout << "Input outside of range, number be between " << lowerLimit << " and " << upperLimit << "." << std::endl;
		}
	}

	//temp value pushed to input pointer
	*returnedInput = returnedValue;

	return;
}

//Handle booking
///<summary> Get Booking from user and add to list
void userInput::userRecordBooking(BookingList* bookingRecords, WatercraftList* marinaList)
{
	int tempInt = -1;
	std::string outputString = "";

	//Show user records
	viewRecords(bookingRecords);

	//Initalise Object(s)
	Watercraft* newWatercraft;
	
	//Determine watercraft type
	std::cout << "Select craft type:" << std::endl;//Prompt
	std::cout << MotorBoat::getCraftType() << std::endl;
	std::cout << NarrowBoat::getCraftType() << std::endl;
	std::cout << SailingBoat::getCraftType() << std::endl;
	takeInputCharString("Watercraft type:", &outputString);//Collect inputs

	if ((outputString) == MotorBoat::getCraftType())
	{
		std::cout << "Using MotorBoat..." << std::endl;
		newWatercraft = new MotorBoat();
	}
	else if ((outputString) == NarrowBoat::getCraftType())
	{
		std::cout << "Using Narrow Boat..." << std::endl;
		newWatercraft = new NarrowBoat();
	}
	else if ((outputString) == SailingBoat::getCraftType())
	{
		std::cout << "Using Sailing Boat..." << std::endl;
		newWatercraft = new SailingBoat();
	}
	else
	{
		std::cout << "Craft indeterminate, using generic Watercraft..." << std::endl;
		newWatercraft = new Watercraft();
	}
	std::cout << newWatercraft->getCraftType() << std::endl;

	Booking* newBooking = new Booking(newWatercraft);

	//Promt user for booking details

	takeInputCharString("Owner's Name:", &outputString);//Collect inputs
	newWatercraft->setOwnerName(outputString);

	takeInputCharString("Boat Name:", &outputString);
	newBooking->getBookedCraft()->setBoatName(outputString);
	//std::cout << ownerName;

	takeInputIntInRange("Boat Length:", &tempInt, marinaList->GetMaximumIndividualLength(), 0);
	newWatercraft->setLength(tempInt);

	takeInputIntInRange("Boat Draft:", &tempInt, marinaList->GetMaximumDraft(), 0);
	newWatercraft->setDraft(tempInt);

	//Show 
	
	newBooking->printAsString();
	std::cout << std::endl;

	//Push to list(s)
	bookingRecords->InsertEntry(newBooking);
	//Add craft to Marina
	marinaList->InsertEntry(newWatercraft);

	//Remove Variables
	//delete newBooking;
	//delete outputString;
}

///<summary> Get Booking selection from user and remove from list
void userInput::userRecordDelete(BookingList* bookingRecords)
{
	//Data Inital
	Booking* selectedBooking = new Booking();
	bool matchFound;
	int userSelection = -1;

	//Show user records
	viewRecords(bookingRecords);

	//Select Entry
	//takeInputCharString("Owner's Name:", *(selectedBooking->getBookedCraft()->getOwnerName()));//Collect inputs
	//takeInputCharString("Boat Name:", *(selectedBooking->getBookedCraft()->getBoatName()));
	takeInputInt("Booking Number:", &userSelection);

	selectedBooking = bookingRecords->GetEntry(userSelection);

	//Get matching booking?
	matchFound = bookingRecords->Contains(*selectedBooking);

	//If a match is found
	if (matchFound)
	{
		//Remove Booking
		bookingRecords->RemoveEntry(*selectedBooking);

		//Remove Boat from marina


	}

	//Remove from memory
	//delete selectedBooking;
	//delete matchFound;
}

///<summary> Displays all booking entries in the list in the console
void userInput::viewRecords(BookingList* bookingRecords)
{
	if (bookingRecords == nullptr) {return;}

	//Instantiate output char array
	//std::string *outputString = new std::string;

	//for each of the vector's elements
	for (int index = 0; index < bookingRecords->GetCount(); index++)
	{
		//Display index
		std::cout << index << ':';

		//print record as string
		if (bookingRecords->GetEntry(index) != nullptr)
		{
			Booking *current = bookingRecords->GetEntry(index);

			current->printAsString();
			
		}
		else 
		{
			std::cout << "ERR: Booking nullptr!";
		}
		std::cout << std::endl;
	}

	//Remove the single char array from memory
	//delete outputString;

	return;
}

void userInput::viewMarina(WatercraftList* currentList)
{
	//title
	std::cout << "Marina:" << std::endl;

	//Print list
	currentList->PrintList();

	//Show total length
	std::cout << "Total length: " << currentList->GetCurrentTotalLength() << std::endl;

	std::cout << std::endl;
}

void userInput::viewHolding(WatercraftList* currentList)
{
	//title
	std::cout << "Holding:" << std::endl;

	//Print list
	currentList->PrintList();
	

	std::cout << std::endl;
}