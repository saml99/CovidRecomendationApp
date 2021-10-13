#include "Menu.h"
#include <iostream>

using namespace CovidRecommendationApp;
using namespace std;

char Menu::displayMenu()
{
	cout << "Enter your choice" << endl;
	cout << "1. Enter user covid information" << endl;
	cout << "2. Enter covid test results" << endl;
	cout << "3. Update high risk location" << endl;
	cout << "4. Update positive patient details" << endl;
	cout << "5. Display positive patient details" << endl;
	cout << "6. Close" << endl;
	char selection;
	cin >> selection;
	return selection;
}

string Menu::menuSelect(char selection)
{
	switch (selection)
	{
	case 1:
		return "User info";
	case 2:
		return "Test results";
	case 3:
		return "High resk locations";
	case 4:
		return "Update positive patient";
	case 5:
		return "Display positive patient";
	case 6:
		return "Goodbye";
	default:
		return "Unknown selection, please try again";
	}
}