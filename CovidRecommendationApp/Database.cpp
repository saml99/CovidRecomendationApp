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
			datafile << headers[i] << '\t';
		}
		datafile << endl;
	}

	datafile.close();
}