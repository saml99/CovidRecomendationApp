#pragma once
#include <string>

using namespace std;

namespace CovidRecommendationApp {

	class Menu 
	{
	
	public:
		char displayMenu();
		string menuSelect(char selection);
	};
}