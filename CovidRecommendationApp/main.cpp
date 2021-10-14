#include "Menu.h"
#include <iostream>

using namespace CovidRecommendationApp;

int main() {

	Menu menu;
	char selection = 0;
	while (selection != '6')
	{
		menu.displayMenu();
		cin >> selection;
		cout << menu.menuSelect(selection);
	}
	
	return 0;
}