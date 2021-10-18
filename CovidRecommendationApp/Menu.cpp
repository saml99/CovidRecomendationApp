#include "Menu.h"
#include "PatientDetailsInputService.h"
#include <iostream>
#include "Database.h"
#include <map>
#include <vector>

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

void Menu::menuSelect(char selection)
{
	switch (selection)
	{
	case '1':
		PatientDetailsInputService patientDetailsInputService;
		patientDetailsInputService.enterDetails();
	case '2':
		patientDetailsInputService.covidResult();

	case '3':

	case '4':

	case '5':

	case '6':
		cout << "Goodbye" << endl;
	default:
		cout << "Unknown selection, please try again" << endl;
	}

}

