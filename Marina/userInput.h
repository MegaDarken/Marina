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
#endif // !MARNIA_H

class userInput
{
private:


public:
	//Common utility
	static void  takeInputChar(const char* prompt, char* out);
	static void  takeInputCharString(const char* prompt, std::string* out);
	static void  takeInputString(const std::string* prompt, std::string* out);
	static void  takeInputInt(const std::string* prompt, int* out);

	//Menu

	//1) record a new booking
	static void userRecordBooking(BookingList& bookingRecords);

	//2) delete a record
	static void userRecordDelete(BookingList& bookingRecords);

	//3) display all records (and available marina space)
	static void viewRecords(BookingList& bookingRecords);

};

