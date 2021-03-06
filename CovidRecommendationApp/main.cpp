#include "Menu.h"
#include "Database.h"

#include <iostream>

using namespace CovidRecommendationApp;
using namespace std;

int main() {

	Database database;
	vector<string> patientDetails = { "PatientID", "Name", "Date of Birth", "Address", "LocationID", "Date/Time", "Last Overseas Travel", "Covid Test", "Status" };
	vector<string> symptoms = { "Symptom", "Risk Level" };
	vector<string> locations = { "Description" };
	database.createTable("PatientDetails.txt", patientDetails);
	database.createTable("Symptoms.txt", symptoms);
	database.createTable("Locations.txt", locations);

	//map<string, string> values{ {"PatientID", "3"}, {"Name", "Sam"}, {"Date of Birth", "26/08/1999"}, {"Address", "some st"}, {"LocationID", "1"}, {"Date/Time", "16/10/2021 22:32:26"}, {"Last Overseas Travel", "No"}, {"Covid Test", "Negative"} };
	//map<string, string> values1{ {"Description", "Auburn Train Station"} };
	//map<string, string> values2{ {"Description", "Royal Hotel"} };
	//database.insertRow("PatientDetails.txt", values);
	//database.insertRow("Locations.txt", values1);
	//database.insertRow("Locations.txt", values2);

	//map<string, string> valuesToUpdate{ {"Statu", "Alive"} };
	//map<string, string> map = database.getRow("PatientDetails.txt", "9");

	//database.updateRow("PatientDetails.txt", "9", valuesToUpdate);

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