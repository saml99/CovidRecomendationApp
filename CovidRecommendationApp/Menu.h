#pragma once
#include <string>

using namespace std;

namespace CovidRecommendationApp {

	class Menu 
	{
	
	public:
		void displayMenu();
		string menuSelect(char selection);
	};
}