#pragma once

#ifndef MARNIA_L
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>
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
	static void  takeInput(const char* prompt, char* out);

	//Menu

	//1) record a new booking
	static void userRecordBooking(std::vector<Booking>& bookingRecords);

	//2) delete a record
	static void userRecordDelete(std::vector<Booking>& bookingRecords);

	//3) display all records (and available marina space)
	static void viewRecords(std::vector<Booking> &bookingRecords);

};

