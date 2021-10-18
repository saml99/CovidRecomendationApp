#include "Menu.h"
#include "Database.h"

#include <iostream>

using namespace CovidRecommendationApp;

int main() {

	Database database;
	vector<string> patientDetails = { "PatientID", "Name", "Date of Birth", "Address", "LocationID", "Date/Time", "Last Overseas Travel", "Covid Test", "Status" };
	vector<string> symptoms = { "Symptom", "Risk Level" };
	vector<string> locations = { "ID", "Description" };
	database.createTable("PatientDetails.txt", patientDetails);
	database.createTable("Symptoms.txt", symptoms);
	database.createTable("Locations.txt", locations);

	map<string, string> values1{ {"Symptom", "fever"}, {"Risk Level", "Low Risk"} };
	map<string, string> values2{ {"Symptom", "dry cough"}, {"Risk Level", "Low Risk"} };
	database.insertRow("Symptoms.txt", values1);
	database.insertRow("Symptoms.txt", values2);

	//map<string, string> valuesToUpdate{ {"Status", "Alive"} };
	//map = database.getRow("PatientDetails.txt", "1");

	//database.updateRow("PatientDetails.txt", "1", valuesToUpdate);

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