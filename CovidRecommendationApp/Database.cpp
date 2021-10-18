#include "Database.h"

#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <stdio.h>

using namespace CovidRecommendationApp;
using namespace std;

void Database::createTable(string file, vector<string> headers)
{
	ifstream readfile;
	string line;
	readfile.open(file);

	if (!readfile) 
	{
		cout << "Could not connect to database." << endl;
	}
	getline(readfile, line);
	if (line == "")
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

void Database::insertRow(string file, map<string, string> values)
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

vector<map<string, string>> Database::getRows(string file)
{
	ifstream datafile;
	string line;
	vector<map<string, string>> rows;
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
			for (int i = 0; i < end; i++)
			{
				string value = line.substr(start, end - start);
				map.at(keys[i]) = value;
				start = end + delimiter.size();
				end = line.find(delimiter, start);
			}
			rows.push_back(map);
		}
	}
	else
	{
		cout << "Unable to open file" << endl;
	}
	return rows;
}

void Database::updateRow(string file, string ID, map<string, string> valuesToUpdate)
{
	ifstream readfile;
	readfile.open(file);
	ofstream datafile;
	datafile.open("temp.txt");
	string headers;
	string oldrow;
	string newrow;
	map<string, string> map = getRow(file, ID);
	for (std::map<string, string>::iterator it = valuesToUpdate.begin(); it != valuesToUpdate.end(); ++it)
	{
		map.at(it->first) = it->second;
	}

	getline(readfile, headers);
	datafile << headers << endl;
	string delimiter = ",";
	int start = 0;
	int end = headers.find(delimiter);
	for (int i = 0; i < end; i++)
	{
		string header = headers.substr(start, end - start);
		if (map.find(header) == map.end())
		{
			newrow = newrow + ",";
		}
		else
		{
			newrow = newrow + map.at(header) + ",";
		}

		start = end + delimiter.size();
		end = headers.find(delimiter, start);
	}
	
	while (getline(readfile, oldrow))
	{
		string delimiter = ",";
		int start = 0;
		int end = oldrow.find(delimiter);
		if (oldrow.substr(start, end - start) == ID)
		{
			oldrow.replace(oldrow.find(oldrow), oldrow.length(), newrow);
			datafile << oldrow << endl;
		}
		else
		{
			datafile << oldrow << endl;
		}
	}

	readfile.close();
	datafile.close();
	remove(file.c_str());
	rename("temp.txt", file.c_str());
}