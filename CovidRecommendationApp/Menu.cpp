#include "Menu.h"
#include <iostream>

using namespace CovidRecommendationApp;
using namespace std;

void Menu::displayMenu()
{
	cout << "Enter your choice" << endl;
	cout << "1. Enter your detail for COVID test recommendation" << endl;
	cout << "2. Submit your COVID test status & update the Location database" << endl;
	cout << "3. Display the updated location (High risk for COVID)" << endl;
	cout << "4. Update COVID patient details" << endl;
	cout << "5. Display the COVID positive patient detail" << endl;
	cout << "6. Quit" << endl;
}

string Menu::menuSelect(char selection)
{
	switch (selection)
	{
	case '1':
		return "User info";
	case '2':
		return "Test results";
	case '3':
		return "High resk locations";
	case '4':
		return "Update positive patient";
	case '5':
		return "Display positive patient";
	case '6':
		return "Goodbye";
	default:
		return "Unknown selection, please try again";
	}
}