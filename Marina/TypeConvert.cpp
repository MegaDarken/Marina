#include "TypeConvert.h"


//Conversion
void TypeConvert::intToChar(int input, char* output)
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

		//std::cout << "!";//Interation notifier

		charIndex++;
	}

	//End of char
	output[charIndex] = NULL;//null char
}

