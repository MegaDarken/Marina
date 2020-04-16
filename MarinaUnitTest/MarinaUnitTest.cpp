#include "pch.h"
#include "CppUnitTest.h"

//Project includes
#include "../Marina/List.h"
#include "../Marina/Booking.h"
#include "../Marina/Watercraft.h"
#include "../Marina/Data.h"
#include "../Marina/userInput.h"

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

		//Test intToChar
		TEST_METHOD(TestIntToChar)
		{
			char charOut[] = { '4', '5', '1' };
			int intIn = 451;

			char* result = new char;

			TypeConvert::intToChar(intIn, result);

			Assert::AreEqual(result, charOut);
		}
	};
}
