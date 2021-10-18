#include "Menu.h"
#include "PatientDetailsInputService.h"
#include "Database.h"

#include <fstream>
#include <iostream>
#include <map>
#include <string>
#include <vector>

using namespace CovidRecommendationApp;
using namespace std;


void Menu::displayMenu()
{
	ifstream readfile;
	string line;
	readfile.open("PatientDetails.txt");
	
	// check that file exists 
	if (!readfile)
	{
		cout << "Issue connecting to database" << endl;
	}
	
	
	//open the file
	else if (readfile.is_open())
	{
		// reads the data from the patients database
		getline(readfile, line);
		cout << line << '\n';

		//check for no patient data
		if (!getline(readfile, line))
		{
			cout << "[] - the database is empty" << endl;
		}
		else
		{
			//output patient data
			cout << line << '\n';
			while (getline(readfile, line))
			{
				cout << line << '\n';
			}
		}
		
		readfile.close();
	}
	else
	{
		cout << "File could not be opened" << endl;
	}
	cout << endl;

	cout << "Enter your choice" << endl;
	cout << "1. Enter your detail for COVID test recommendation" << endl;
	cout << "2. Submit your COVID test status & update the Location database" << endl;
	cout << "3. Display the updated location (High risk for COVID)" << endl;
	cout << "4. Update COVID patient details" << endl;
	cout << "5. Display the COVID positive patient detail" << endl;
	cout << "6. Quit" << endl;
}

string Menu::menuSelect(char selection)
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
		//Input patient details
		PatientDetailsInputService patientDetailsInputService;
		patientDetailsInputService.enterDetails();
		break;
	case '2':
		//Update covid test status and locations
		patientDetailsInputService.covidResult();
		break;
	case '3':
		//Get the high risk locations
		database.getRows("Locations.txt");
		break;
	case '4':	
		//Update patient details
		cout << "Enter the ID of the patient to update" << endl;
		cin >> patientID;
		//Check for valid ID
		if (database.getRow("PatientDetails.txt", patientID).at("PatientID") != patientID)
		{
			cout << "PatientID " << patientID << " is not valid" << endl;
			break;
		}
		cout << "Enter the field you want to update" << endl;
		cin >> header;

		//Store the values for the patient in a map
		row = database.getRow("PatientDetails.txt", patientID);
		//Iterate through the map to check the field entered by the user is valid
		for (std::map<string, string>::iterator it = row.begin(); it != row.end(); ++it)
		{
			if (it->first == header)
			{
				validheader = true;
			}
		}
		cout << "Enter the new value for the field" << endl;
		cin >> value;
		//update the database if the field is valid
		if (validheader)
		{
			valuesToUpdate.insert({ header, value });
			database.updateRow("PatientDetails.txt", patientID, valuesToUpdate);
		}
		break;
	case '5':
		//Display specific patient details
		cout << "Enter the ID of the patient" << endl;
		cin >> patientID;
		//Get the row of the patient from the database based on ID and store in a map
		row = database.getRow("PatientDetails.txt", patientID);
		//Iterate through the map and print the key value pairs
		for (std::map<string, string>::iterator it = row.begin(); it != row.end(); ++it)
		{
			cout << it->first << ":  " << it->second << endl;
		}
		break;
	case '6':
		return "Goodbye";
		break;
	default:
		return "Unknown selection, please try again";
		break;
	}
	return "";
}

