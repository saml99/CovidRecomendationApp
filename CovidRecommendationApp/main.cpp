#include "Menu.h"
#include "Database.h"

#include <iostream>

using namespace CovidRecommendationApp;

int main() {

	Database database;
	vector<string> patientDetails = { "PatientID", "Name", "Date of Birth", "Address", "Visited Location", "Date/Time", "Last Overseas Travel", "Covid Test", "Status" };
	vector<string> symptoms = { "Low Risk", "Medium Risk", "High Risk" };
	vector<string> locations = { "ID", "Description" };
	database.createTable("PatientDetails.txt", patientDetails);
	database.createTable("Symptoms.txt", symptoms);
	database.createTable("Locations.txt", locations);

	Menu menu;
	char selection = 0;
	while (selection != '6')
	{
		menu.displayMenu();
		cin >> selection;
		cout << menu.menuSelect(selection);
	}
	
	return 0;
}