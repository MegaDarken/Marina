//Data.cpp	 Stores and Handles the program's data.
#pragma once

#ifndef MARNIA_H
#include <iostream>
#include <cstdlib>
#include <vector>

#include "List.h"
#include "Booking.h"
#endif // !MARNIA_H



using namespace std;




//List of Records
vector<Booking> bookingRecords;

//Boat Data Storage

//Marina Area
 //First List
List* MarinaCraftList = new List();

//Holding Bay
 //Second List
List* HoldingBayCraftList = new List();

//External File Storage (I/O)


//Save To Files


//Load From Files



//--Data (Boat) Deletion--