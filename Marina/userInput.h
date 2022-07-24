#pragma once
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
#include "TypeConvert.h"

class userInput
{
private:


public:
	
	//Common utility
	static void  takeInputChar(const char* prompt, char* out);
	static void  takeInputCharString(const char* prompt, std::string* out);
	static void  takeInputString(const std::string* prompt, std::string* out);
	static void  takeInputInt(const char* prompt, int* out);
	static void  takeInputIntInRange(const char* prompt, int* out, int upperLimit, int lowerLimit);//Ensures input is within range before returning

	//Menu

	//1) record a new booking
	static void userRecordBooking(BookingList* bookingRecords, WatercraftList* marinaList);

	//2) delete a record
	static void userRecordDelete(BookingList* bookingRecords, WatercraftList* marinaList, WatercraftList* holdingList);

	//3) display all records (and available marina space)
	static void viewRecords(BookingList* bookingRecords);

	static void viewMarina(WatercraftList* currentList);
	static void viewHolding(WatercraftList* currentList);
};

