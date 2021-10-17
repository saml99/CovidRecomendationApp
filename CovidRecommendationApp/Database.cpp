#include "Database.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace CovidRecommendationApp;
using namespace std;

void Database::createTable(string file, vector<string> headers)
{
	ofstream datafile;
	datafile.open(file);

	if (!datafile) 
	{
		cout << "Issue connecting to database" << endl;
	}
	else
	{
		for (int i = 0; i < headers.size(); i++)
		{
			datafile << headers[i] << ',';
		}
		datafile << endl;
	}

	datafile.close();
}

void Database::insertTable(string file, map<string, string> values)
{
	fstream datafile;
	datafile.open(file, ios::in | ios::app);
	string headers;

	if (!datafile)
	{
		cout << "Issue connecting to database" << endl;
	}
	else
	{
		getline(datafile, headers);
		string delimiter = ",";
		int start = 0;
		int end = headers.find(delimiter);
		cout << values.size();
		for (int i = 0; i < end; i++)
		{
			string header = headers.substr(start, end - start);
			if (values.find(header) == values.end())
			{
				datafile << ",";
			}
			else
			{
				datafile << values.at(header) << ",";
			}
			
			start = end + delimiter.size();
			end = headers.find(delimiter, start);
		}
		datafile << endl;
		datafile.close();
	}
}