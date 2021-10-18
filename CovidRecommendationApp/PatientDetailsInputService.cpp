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
		map<string, string> row = database.getRow("Symptoms.txt", input_text);
		if (row.at("Symptom") == input_text)
		{
			if (row.at("Risk Level") == "High Risk")
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
	cout << "Have you visited any of the following locations?" << endl;
	vector < map<string, string> > rows = database.getRows("Locations.txt");
	for (int i = 0; i < rows.size(); i++)
	{
		cout << rows[i].at("Description") << endl;
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