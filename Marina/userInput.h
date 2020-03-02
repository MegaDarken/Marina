#pragma once

#ifndef MARNIA_H
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <vector>

#include "List.h"
#include "Booking.h"
#include "Watercraft.h"
#endif // !MARNIA_H

class userInput
{
private:


public:
	//Menu

	//1) record a new booking
	static void userRecordBooking();

	//2) delete a record
	static void userRecordDelete();

	//3) display all records (and available marina space)
	static void viewRecords(std::vector<Booking> &bookingRecords);

};

