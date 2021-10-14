#pragma once
#include <string>

using namespace std;

namespace CovidRecommendationApp {

	class Database
	{

	public:
		void createTable(string file, string headers[]);
	};
}