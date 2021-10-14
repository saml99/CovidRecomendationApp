#pragma once

#include <string>
#include <vector>

using namespace std;

namespace CovidRecommendationApp {

	class Database
	{

	public:
		void createTable(string file, vector<string> headers);
	};
}