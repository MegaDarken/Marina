#include "pch.h"
#include "CppUnitTest.h"

//Project includes
#include "../Marina/List.h"
#include "../Marina/WatercraftList.cpp"
#include "../Marina/BookingList.cpp"

#include "../Marina/Booking.h"
#include "../Marina/Booking.cpp"

#include "../Marina/Watercraft.h"
#include "../Marina/Watercraft.cpp"

#include "../Marina/MotorBoat.h"
#include "../Marina/MotorBoat.cpp"

#include "../Marina/NarrowBoat.h"
#include "../Marina/NarrowBoat.cpp"

#include "../Marina/SailingBoat.h"
#include "../Marina/SailingBoat.cpp"


#include "../Marina/Data.h"
#include "../Marina/Data.cpp"

#include "../Marina/userInput.h"
#include "../Marina/userInput.cpp"

#include "../Marina/TypeConvert.h"
#include "../Marina/TypeConvert.cpp"

using namespace Microsoft::VisualStudio::CppUnitTestFramework;

namespace MarinaUnitTest
{
	TEST_CLASS(MarinaUnitTest)
	{
	public:
		
		TEST_METHOD(TestAlwaysTrue)
		{
			Assert::IsTrue(true);
		}

		//Convert
		//Test intToChar
		TEST_METHOD(TestIntToChar)
		{
			char charOut[] = { '4', '5', '1', NULL };
			int intIn = 451;

			char* result = new char;

			TypeConvert::intToChar(intIn, result);

			Assert::AreEqual(charOut, result);
		}

		//Watercraft
		TEST_METHOD(TestConstructWatercraft)
		{
			//Attributes
			std::string inputOwnerName = "Jane Doe";
			std::string inputBoatName = "Seawave";
			int inputLength = 10;
			int inputDraft = 2;

			Watercraft* testWatercraft = new Watercraft(inputOwnerName, inputBoatName, inputLength, inputDraft);

			Assert::AreEqual(inputOwnerName, *testWatercraft->getOwnerName());
			Assert::AreEqual(inputBoatName, *testWatercraft->getBoatName());
			Assert::AreEqual(inputLength, testWatercraft->getLength());
			Assert::AreEqual(inputDraft, testWatercraft->getDraft());

			//Cleanup
			delete testWatercraft;
		}


		//Booking

		TEST_METHOD(TestConstructBooking)
		{
			//Attributes
			int inputCost = 175;
			std::string inputOwnerName = "Clements Volta";
			std::string inputBoatName = "Seawave";
			int inputLength = 10;
			int inputDraft = 2;

			Booking* testBooking = new Booking(inputCost, inputOwnerName, inputBoatName, inputLength, inputDraft);

			Assert::AreEqual(inputCost, testBooking->getTotalCost());
			Assert::AreEqual(inputOwnerName, *testBooking->getBookedCraft()->getOwnerName());
			Assert::AreEqual(inputBoatName, *testBooking->getBookedCraft()->getBoatName());
			Assert::AreEqual(inputLength, testBooking->getBookedCraft()->getLength());
			Assert::AreEqual(inputDraft, testBooking->getBookedCraft()->getDraft());

			//Cleanup
			delete testBooking;
		}


		//List(s)
		TEST_METHOD(TestWatercraftListAdd)
		{
			//Attributes
			std::string inputOwnerName = "Orville Simmons";
			std::string inputBoatName = "Toothy";
			int inputLength = 10;
			int inputDraft = 4;

			//Craft
			Watercraft* tempInstance = new Watercraft(inputOwnerName, inputBoatName, inputLength, inputDraft);

			//Setup List
			WatercraftList* testList = new WatercraftList();

			//Add Instance
			testList->InsertEntry(tempInstance);
			//testList->InsertEntry(tempInstance);

			Assert::IsTrue(testList->VerifyIntegrity());
			Assert::IsTrue(testList->Contains(*tempInstance));

			//Cleanup
			delete testList;
		}

		TEST_METHOD(TestWatercraftListAddRemove)
		{
			//Attributes
			std::string inputOwnerName = "Locke Pharel";
			std::string inputBoatName = "Vickers";
			int inputLength = 8;
			int inputDraft = 1;

			//Craft
			Watercraft* tempInstance = new Watercraft(inputOwnerName, inputBoatName, inputLength, inputDraft);

			//Setup List
			WatercraftList* testList = new WatercraftList();

			//Add Instance
			testList->InsertEntry(tempInstance);
			testList->InsertEntry(tempInstance);

			//Assert::IsTrue(testList->VerifyIntegrity());
			//Assert::AreEqual(tempInstance, testList->GetEntry(0));

			testList->RemoveEntry(0);//Remove Instance
			testList->RemoveEntry(*tempInstance);//Remove Empty

			Assert::AreEqual(0, testList->GetCount());

			//Cleanup
			delete testList;
		}


		TEST_METHOD(TestBookingListAdd)
		{
			//Attributes
			int inputCost = 100;
			std::string inputOwnerName = "Orville Simmons";
			std::string inputBoatName = "Toothy";
			int inputLength = 10;
			int inputDraft = 4;

			//Craft
			Booking* tempInstance = new Booking(inputCost, inputOwnerName, inputBoatName, inputLength, inputDraft);

			//Setup List
			BookingList* testList = new BookingList();

			//Add Instance
			//testList->InsertEntry(tempInstance);
			//testList->InsertEntry(tempInstance);

			Assert::IsTrue(testList->VerifyIntegrity());
			Assert::IsTrue(testList->Contains(*tempInstance));

			//Cleanup
			delete testList;
		}

		TEST_METHOD(TestBookingListAddRemove)
		{
			//Attributes
			int inputCost = 210;
			std::string inputOwnerName = "Frank Miller";
			std::string inputBoatName = "Bottles";
			int inputLength = 11;
			int inputDraft = 3;

			//Booking
			Booking* tempInstance = new Booking(inputCost, inputOwnerName, inputBoatName, inputLength, inputDraft);

			//Setup List
			BookingList* testList = new BookingList();

			//Add Instance
			testList->InsertEntry(tempInstance);
			testList->InsertEntry(tempInstance);

			//Assert::IsTrue(testList->VerifyIntegrity());
			//Assert::AreEqual(tempInstance, testList->GetEntry(0));

			testList->RemoveEntry(0);//Remove Instance
			testList->RemoveEntry(*tempInstance);//Remove Empty

			Assert::AreEqual(0, testList->GetCount());

			//Cleanup
			delete tempInstance;
			delete testList;

		}

		TEST_METHOD(TestWatercraftTypeRecall)
		{
			Watercraft* testCraft;

			testCraft = new Watercraft();
			Assert::AreEqual(Watercraft::getCraftType(), testCraft->getCraftType());

			testCraft = new MotorBoat();
			Assert::AreEqual(MotorBoat::getCraftType(), testCraft->getCraftType());

			testCraft = new NarrowBoat();
			Assert::AreEqual(NarrowBoat::getCraftType(), testCraft->getCraftType());

			testCraft = new SailingBoat();
			Assert::AreEqual(SailingBoat::getCraftType(), testCraft->getCraftType());

			delete testCraft;
		}
	};
}
