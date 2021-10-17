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
		void updateRow(string file, string ID, map<string, string> valuesToUpdate);
	};
}