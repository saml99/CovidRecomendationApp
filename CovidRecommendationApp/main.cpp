#include "Menu.h"

using namespace CovidRecommendationApp;

int main() {

	Menu menu;
	char selection = 0;
	while (selection != 6)
	{
		selection = menu.displayMenu();
		menu.menuSelect(selection);
	}
	
	return 0;
}