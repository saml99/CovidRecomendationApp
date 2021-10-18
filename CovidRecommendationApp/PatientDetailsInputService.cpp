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

	//Checks that ID is a number
	while (!isNumber(ID))
	{
		cout << "Patient ID must be a number. Please try agian." << endl;
		cin >> ID;
	}

	//check if patient id exists
	while (database.getRow("PatientDetails.txt", ID).at("PatientID") == ID)
	{
		cout << "Patient ID already exists" << endl;
		cin >> ID;
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
	database.insertRow("PatientDetails.txt", patientDetails); //Inserts the maped user inputs into the database text file
	recommendation(); //Recommends COVID Test
}

void PatientDetailsInputService::covidResult()
{
	Database database;
	map<string, string> patientDetails;
	map<string, string> locations;
	string ID;
	string TestStatus;
	string VisitedLocation;

	cout << "Enter Patient ID:" << endl;
	cin >> ID;

	//Check that ID is a number
	while (!isNumber(ID))
	{
		cout << "Patient ID must be a number. Please try agian." << endl;
	}
	cout << "Enter test Status: (Positive/Negative)" << endl;
	cin >> TestStatus;
	patientDetails.insert({ "Covid Test", TestStatus });
	database.updateRow("PatientDetails.txt", ID, patientDetails); //Updates the row with the new test results

	if (TestStatus == "Positive") //Prompst for visited locations if the test result is positive
	{
		cout << "Enter the locations you have visited: (type done when all locations are entered)" << endl;
		cin.ignore();
		getline(cin, VisitedLocation);
		while (VisitedLocation != "done") 
		{
			locations.insert({ "Description", VisitedLocation });
			database.insertRow("Locations.txt", locations); //Inserts all user intered locations into the locations database
			getline(cin, VisitedLocation);
		}
	}
	else (TestStatus == "Negative");
	{
		cout << "You can return to the main menu." << endl;
	}

}

//Checks to see if a string only contains numbers
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
	vector < map<string, string> > rows = database.getRows("Symptoms.txt"); //Gets all the symptoms rows
	for (int i = 0; i < rows.size(); i++)
	{
		cout << rows[i].at("Symptom") << endl; //Writes all symptoms to the console
	}
	string input_text;
	bool highRisk = false;
	getline(cin, input_text);
	while (input_text != "0")
	{
		map<string, string> symptoms = database.getRow("Symptoms.txt", input_text); //Checks database file for inputted text
		if (symptoms.at("Symptom") == input_text) //If symptom is in the database
		{
			if (symptoms.at("Risk Level") == "High Risk") //Check if symptom is high risk
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
	vector < map<string, string> > locations = database.getRows("Locations.txt"); //Gets all the location rows
	for (int i = 0; i < locations.size(); i++)
	{
		cout << locations[i].at("Description") << endl; //Writes all symptoms to the console
	}
	bool visitedLocation = false;
	getline(cin, input_text);
	while (!(input_text == "yes") || !(input_text == "no")) //Check for yes or no inputs
	{
		cout << "Please enter yes or no" << endl;
		getline(cin, input_text);
	}
	if (input_text == "yes")
	{
		visitedLocation = true;
	}

	if (visitedLocation || highRisk) //If the user has been to a high risk location or has high risk symptoms then recommend a COVID test
	{
		cout << "We recommend you get tested for COVID-19" << endl;
	}
	else
	{
		cout << "COVID-19 test not recommended. Isolate yourself at home." << endl;
	}
}