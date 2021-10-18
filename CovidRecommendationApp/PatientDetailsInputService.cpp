#include "PatientDetailsInputService.h"
#include "Database.h"

#include <map>
#include <vector>

using namespace CovidRecommendationApp;

void PatientDetailsInputService::enterDetails()
{
	Database database;
	map<string, string> patientDetails;
	string ID;
	string firstName;
	string lastName;
	string fullName;
	string dateOfBirth;
	string address;
	string overseas;
	string symptoms;
	cout << "Enter Patient ID:" << endl;
	cin >> ID;
	while (!isNumber(ID))
	{
		cout << "Patient ID must be a number. Please try agian." << endl;
	}
	patientDetails.insert({ "PatientID", ID });
	cout << "Enter first name: " << endl;
	cin >> firstName;
	cout << "Enter family name: " << endl;
	cin >> lastName;
	fullName = firstName + " " + lastName;
	patientDetails.insert({ "Name", fullName });
	cout << "Enter date of birth: (dd/mm/yyyy) " << endl;
	cin >> dateOfBirth;
	patientDetails.insert({ "Date of Birth", dateOfBirth });
	cout << "Enter address: " << endl;
	cin >> address;
	patientDetails.insert({ "Address", address });
	cout << "Have you traveled overseas recently? yes/no" << endl;
	cin >> overseas;
	patientDetails.insert({ "Last Overseas Travel", overseas });
	database.insertRow("PatientDetails.txt", patientDetails);
	recommendation();
}

void PatientDetailsInputService::covidResult()
{
	Database database;
	map<string, string> patientDetails;
	string ID;
	string TestStatus;
	string VisitedLocations;

	cout << "Enter Patient ID:" << endl;
	cin >> ID;
	while (!isNumber(ID))
	{
		cout << "Patient ID must be a number. Please try agian." << endl;
	}
	patientDetails.insert({ "PatientID", ID });
	cout << "Enter test Status: (Positive/Negative)" << endl;
	cin >> TestStatus;
	patientDetails.insert({ "Test Status", TestStatus });
	database.insertRow("PatientDetails.txt", patientDetails);

	if (TestStatus == "Positive")
	{
		cout << "Enter the locations you have visited:" << endl;
		cin >> VisitedLocations;

		patientDetails.insert({ "Updated high risk locations", VisitedLocations });
		database.insertRow("Locations.txt", patientDetails);
	}
	else (TestStatus == "Negative");
	{
		cout << "You can return to the main menu." << endl;
	}

}

bool PatientDetailsInputService::isNumber(string str)
{
	for (char c : str)
	{
		if (isdigit(c) == 0)
		{
			return false;
		}
	}
	return true;
}

void PatientDetailsInputService::recommendation()
{
	Database database;
	cout << "Which of the following symptoms are you experiencing? Type 0 when finished entering symptoms" << endl;
	vector < map<string, string> > rows = database.getRows("Symptoms.txt");
	for (int i = 0; i < rows.size(); i++)
	{
		cout << rows[i].at("Symptom") << endl;
	}
	string input_text;
	bool highRisk = false;
	getline(cin, input_text);
	while (input_text != "0")
	{
		map<string, string> symptoms = database.getRow("Symptoms.txt", input_text);
		if (symptoms.at("Symptom") == input_text)
		{
			if (symptoms.at("Risk Level") == "High Risk")
			{
				highRisk = true;
			}
		}
		else
		{
			cout << "Entry is not a valid symptom" << endl;
		}
		getline(cin, input_text);
	}
	cout << "Have you visited any of the following locations? yes/no" << endl;
	vector < map<string, string> > locations = database.getRows("Locations.txt");
	for (int i = 0; i < locations.size(); i++)
	{
		cout << locations[i].at("Description") << endl;
	}
	bool visitedLocation = false;
	getline(cin, input_text);
	while (!(input_text == "yes") || !(input_text == "no"))
	{
		cout << "Please enter yes or no" << endl;
		getline(cin, input_text);
	}
	if (input_text == "yes")
	{
		visitedLocation = true;
	}

	if (visitedLocation || highRisk)
	{
		cout << "We recommend you get tested for COVID-19" << endl;
	}
	else
	{
		cout << "COVID-19 test not recommended. Isolate yourself at home." << endl;
	}
}