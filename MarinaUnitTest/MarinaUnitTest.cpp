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


	};
}
