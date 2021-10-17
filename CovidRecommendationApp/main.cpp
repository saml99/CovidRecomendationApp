#include "Menu.h"
#include "Database.h"

#include <iostream>

using namespace CovidRecommendationApp;

int main() {

	Database database;
	vector<string> patientDetails = { "PatientID", "Name", "Date of Birth", "Address", "LocationID", "Date/Time", "Last Overseas Travel", "Covid Test", "Status" };
	vector<string> symptoms = { "Low Risk", "Medium Risk", "High Risk" };
	vector<string> locations = { "ID", "Description" };
	database.createTable("PatientDetails.txt", patientDetails);
	database.createTable("Symptoms.txt", symptoms);
	database.createTable("Locations.txt", locations);

	map<string, string> values{ {"PatientID", "1"}, {"Name", "Sam"}, {"Date of Birth", "26/08/1999"}, {"Address", "some st"}, {"LocationID", "1"}, {"Date/Time", "16/10/2021 22:32:26"}, {"Last Overseas Travel", "No"}, {"Covid Test", "Negative"} };
	database.insertTable("PatientDetails.txt", values);

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