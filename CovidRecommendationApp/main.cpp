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

	//map<string, string> values1{ {"ID", "1"}, {"Description", "Auburn Train Station"} };
	//map<string, string> values2{ {"ID", "2"}, {"Description", "Royal Hotel"} };
	//database.insertRow("Locations.txt", values1);
	//database.insertRow("Locations.txt", values2);

	//map<string, string> valuesToUpdate{ {"Status", "Alive"} };
	//map<string, string> map = database.getRow("PatientDetails.txt", "9");

	//database.updateRow("PatientDetails.txt", "1", valuesToUpdate);

	Menu menu;
	char selection = 0;
	while (selection != '6')
	{
		menu.displayMenu();
		cin >> selection;
		menu.menuSelect(selection);
	}
	
	return 0;
}