#include "Menu.h"
#include "PatientDetailsInputService.h"
#include "Database.h"

#include <iostream>
#include <map>
#include <string>

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
	Database database;
	string patientID;
	string header;
	bool validheader = false;
	map<string, string> valuesToUpdate;
	map<string, string> row;
	string value;
	

	switch (selection)
	{
	case '1':
		PatientDetailsInputService patientDetailsInputService;
		patientDetailsInputService.enterDetails();
	case '2':
		
	case '3':
		database.getRows("Locations.txt");
		break;
	case '4':	
		cout << "Enter the ID of the patient to update" << endl;
		cin >> patientID;
		if (database.getRow("PatientDetails.txt", patientID).at("PatientID") != patientID)
		{
			cout << "PatientID " << patientID << " is not valid" << endl;
			break;
		}
		cout << "Enter the field you want to update" << endl;
		cin >> header;
		row = database.getRow("PatientDetails.txt", patientID);
		for (std::map<string, string>::iterator it = row.begin(); it != row.end(); ++it)
		{
			if (it->first == header)
			{
				validheader = true;
			}
		}
		cout << "Enter the new value for the field" << endl;
		cin >> value;
		if (validheader)
		{
			valuesToUpdate.insert({ header, value });
			database.updateRow("PatientDetails.txt", patientID, valuesToUpdate);
		}
		break;
	case '5':
		cout << "Enter the ID of the patient" << endl;
		cin >> patientID;
		row = database.getRow("PatientDetails.txt", patientID);
		for (std::map<string, string>::iterator it = row.begin(); it != row.end(); ++it)
		{
			cout << it->first << ":  " << it->second << endl;
		}
		break;
	case '6':
		cout << "Goodbye" << endl;
		break;
	default:
		cout << "Unknown selection, please try again" << endl;
	}
}