//Data.cpp	 Stores and Handles the program's data.
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



using namespace std;

const char* defaultRecordsFileName = "bookingRecords.txt";


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
void saveBookingRecords(const char* fileName)
{
    //Open file
    ofstream currentFile;
    currentFile.open(fileName);

    //Input data
    for (size_t index = 0; index < bookingRecords.size(); index++)
    {
        //cast object into file
        currentFile.write((char*)&bookingRecords[index], sizeof(bookingRecords[index]));
    }
    

    //Close file
    currentFile.close();
}

void saveBookingRecords()
{
    saveBookingRecords(defaultRecordsFileName);
}

//Load From Files
void loadBookingRecords(const char* fileName)
{
    //Open file
    ifstream currentFile;
    currentFile.open(fileName);

    //Input data
    while (!currentFile.eof())
    {
        currentFile.read((char*)& bookingRecords.push_back, sizeof(bookingRecords.begin));
    }

    //Close file
    currentFile.close();
}

void loadBookingRecords()
{
    loadBookingRecords(defaultRecordsFileName);
}

//--Data (Boat) Deletion--