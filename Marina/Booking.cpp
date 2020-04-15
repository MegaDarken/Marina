
#include "Booking.h"

//Constants
const int DefaultTotalCost = 0;

const int MaximumBoatLength = 15;//As defined in brief
const int MaximumBoatDraft = 5;
const int PoundsPerMeterPerMonth = 10;

const char AttributeSplitChar = ';';
const int AttributeCount = 5;


//Conversion
void intToChar(int input, char *output)
{
	//Converts an interger into a string of characters displaying that value
	int iterations = log10(input);
	int charIndex = 0;

	//Establish output as new pointer
	//output = new char;

	for (int i = iterations; i > 0; i--)
	{
		int currentDigit = input;
		int currentPower = pow(10, iterations);

		currentDigit = currentDigit % (currentPower * 10);
		currentDigit = currentDigit / currentPower;

		output[charIndex] = (char)(currentDigit + '0');

		std::cout << "!";

		charIndex++;
	}
}

//Constructor
Booking::Booking()
{
	this->totalCost = DefaultTotalCost;
	this->bookedCraft = new Watercraft();
}

Booking::Booking(Watercraft* bookedCraft)
{
	//Examine if boat can fit

	this->bookedCraft = bookedCraft;

	//Calculate Cost
	int cost = bookedCraft->getLength();
	this->totalCost = cost * PoundsPerMeterPerMonth;
}

Booking::Booking(int cost, Watercraft* bookedCraft)
{
	//Examine if boat can fit

	this->totalCost = cost;
	this->bookedCraft = bookedCraft;
}

Booking::Booking(char ownerName[], char boatName[], int length, int draft)
{
	//Create watercraft
	this->bookedCraft = new Watercraft(ownerName, boatName, length, draft);

	//Calculate Cost
	int cost = bookedCraft->getLength();
	this->totalCost = cost * PoundsPerMeterPerMonth;
}

Booking::Booking(int cost, std::string ownerName, std::string boatName, int length, int draft)
{
	//Examine if boat can fit


	this->totalCost = cost;

	//Create watercraft
	this->bookedCraft = new Watercraft(ownerName, boatName, length, draft);

}

Booking::~Booking()
{
}


int Booking::getTotalCost()
{
	return totalCost;
}

Watercraft* Booking::getBookedCraft()
{
		return bookedCraft;
}

//std::string Booking::getAsString()
//{
//	std::string outputString;
//
//	//Add parts to string
//	outputString += this->bookedCraft->getOwnerName();
//	outputString += this->bookedCraft->getBoatName();
//
//	return outputString;
//}

 void Booking::getAsString(std::string *outputString)
{
	char *tempString = new char;//Is establisment needed here?

	//Add parts to string
	intToChar(this->totalCost, tempString);
	*outputString = *outputString + *tempString;

	*outputString = *outputString + *this->bookedCraft->getOwnerName();
	*outputString = *outputString + *this->bookedCraft->getBoatName();

	intToChar(this->bookedCraft->getLength(), tempString);
	*outputString = *outputString + *tempString;
	intToChar(this->bookedCraft->getDraft(), tempString);
	*outputString = *outputString + *tempString;
	//strcat(outputString, (char*)this->bookedCraft->getLength);
	//strcat(outputString, (char*)this->bookedCraft->getDraft);

	//delete tempString;
	//return outputString;
}

 void Booking::printAsString()
 {
	 char* tempString = new char;

	 //Add parts to string
	 intToChar(this->totalCost, tempString);
	 std::cout << *tempString << ' ';

	 std::cout << *(this->bookedCraft->getOwnerName()) << ' ';
	 std::cout << *(this->bookedCraft->getBoatName()) << ' ';

	 intToChar(this->bookedCraft->getLength(), tempString);
	 std::cout << *tempString << ' ';
	 intToChar(this->bookedCraft->getDraft(), tempString);
	 std::cout << *tempString << ' ';
	 //strcat(outputString, (char*)this->bookedCraft->getLength);
	 //strcat(outputString, (char*)this->bookedCraft->getDraft);

	 delete tempString;
	 //return outputString;
 }

 void Booking::getAsFileString(std::string* outputString)
 {
	 //vars
	 //char* tempChar = new char();

	 //clear output
	 //outputString = new std::string();
	 outputString = new std::string();
	 
	 //tempChar = (char*)this->getTotalCost();
	 outputString[0] = ((char*)this->getTotalCost()) + AttributeSplitChar;

	 outputString[0] = (*this->bookedCraft->getOwnerName() + AttributeSplitChar);
	 outputString[0] = (*this->bookedCraft->getBoatName() + AttributeSplitChar);

	 outputString[0] = ((char*)this->bookedCraft->getLength()) + AttributeSplitChar;
	 outputString[0] = ((char*)this->bookedCraft->getDraft());
 }

 void Booking::setFromFileString(std::string* inputString)
 {
	 //Instatiate
	 std::stringstream currentStream(*inputString);
	 
	 std::vector<std::string> splitString;// = new std::vector<std::string>();
	 std::string tempString;
	 //char* tempChar = new char;

	 //split string into array
	 while (std::getline(currentStream, tempString, AttributeSplitChar))
	 {
		 //std::strcpy(tempChar, tempString);
		 splitString.push_back(tempString);
	 }
	 
	 if (splitString.size() == AttributeCount)
	 {
		 //std::strcpy(tempChar, splitString[0].c_str());//, splitString[0].size());
		 this->bookedCraft->setUniqueID(*(unsigned int*)splitString[0].c_str());

		 this->bookedCraft->setOwnerName(splitString[1]);
		 this->bookedCraft->setBoatName(splitString[2]);

		 //std::strcpy(tempChar, splitString[3].c_str());//, splitString[3].size());
		 this->bookedCraft->setLength(*(int*)splitString[3].c_str());
		 //std::strcpy(tempChar, splitString[4].c_str());//, splitString[4].size());
		 this->bookedCraft->setDraft(*(int*)splitString[4].c_str());
	 }

	 //Delete
	 //delete splitString;
	 //delete tempChar;
 }

bool Booking::validLength()
{
	return (bookedCraft->getLength() <= MaximumBoatLength);
}

bool Booking::validDraft()
{
	return (bookedCraft->getDraft() <= MaximumBoatDraft);
}

bool Booking::operator==(const Booking& current)
{
	bool result = true;

	if (this->bookedCraft != current.bookedCraft) { result = false; }
	if (this->totalCost != current.totalCost) { result = false; }

	return result;
}

bool Booking::operator!=(const Booking& current)
{
	bool result = false;

	if (this->bookedCraft != current.bookedCraft) { result = true; }
	if (this->totalCost != current.totalCost) { result = true; }

	return result;
}