//This is the "Program.cpp" file
//Include(s) 
#include <iostream>
#include <cstdlib>

using namespace std;

const char ExitMenuCharacter = '4';

//Menu Methods
void showMenu(void)
{
	//Title
	cout << "MARINA BERTH BOOKING SYSTEM" << endl;

	//Print out options
	cout << "1) record a new booking" << endl;
	cout << "2) delete a record" << endl;
	cout << "3) display all records (and available marina space)" << endl;
	cout << "4) exit the program" << endl;
};

void runMenu(void)
{
	char userInput;

	//Loop until exiting

	while (userInput != ExitMenuCharacter)
	{
		//display Menu
		showMenu();

		//Indicate that user can input now
		cout << ">";

		//Get new user input
		cin >> userInput;

		switch (userInput)
		{
		default:
			break;
		case 1:
			break;
		case 2:
			break;
		case 3:
			break;
		}
	}
}



int main(void)
{


	//Pausing Before Closing
	system("pause");

	return 0;
}
