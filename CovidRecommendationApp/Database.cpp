#include "Database.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace CovidRecommendationApp;
using namespace std;

void Database::createTable(string file, vector<string> headers)
{
	fstream createfile;
	createfile.open(file, fstream::in | fstream::out);

	if (!createfile) 
	{
		ofstream datafile;
		datafile.open(file);

		for (int i = 0; i < headers.size(); i++)
		{
			datafile << headers[i] << ',';
		}
		datafile << endl;
		datafile.close();
	}
}

void Database::insertTable(string file, map<string, string> values)
{
	ofstream datafile;
	ifstream readfile;
	datafile.open(file, ios::app);
	readfile.open(file);
	string headers;

	if (!datafile)
	{
		cout << "Issue connecting to database" << endl;
	}
	else
	{
		getline(readfile, headers);
		string delimiter = ",";
		int start = 0;
		int end = headers.find(delimiter);
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

map<string, string> Database::getRow(string file, string ID)
{
	ifstream datafile;
	string line;
	map<string, string> map;
	vector<string> keys;
	datafile.open(file);
	if (datafile.is_open())
	{
		getline(datafile, line);
		string delimiter = ",";
		int start = 0;
		int end = line.find(delimiter);
		for (int i = 0; i < end; i++)
		{
			string key = line.substr(start, end - start);
			keys.push_back(key);
			map.insert(pair<string, string>(key, ""));
			start = end + delimiter.size();
			end = line.find(delimiter, start);
		}

		while (getline(datafile, line))
		{
			string delimiter = ",";
			int start = 0;
			int end = line.find(delimiter);
			if (line.substr(start, end - start) == ID)
			{
				for (int i = 0; i < end; i++)
				{
					string value = line.substr(start, end - start);
					map.at(keys[i]) = value;
					start = end + delimiter.size();
					end = line.find(delimiter, start);
				}
			}
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}

	return map;
}