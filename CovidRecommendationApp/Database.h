#pragma once

#include <string>
#include <vector>
#include <map>

using namespace std;

namespace CovidRecommendationApp {

	class Database
	{

	public:
		void createTable(string file, vector<string> headers);
		void insertRow(string file, map<string, string> values);
		map<string, string> getRow(string file, string ID);
		vector<map<string, string>> getRows(string file);
		void updateRow(string file, string ID, map<string, string> valuesToUpdate);
	};
}