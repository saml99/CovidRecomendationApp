#include "pch.h"
#include "CppUnitTest.h"
#include "../CovidRecommendationApp/Menu.h"

#include <string>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CovidRecommendationApp;
using namespace std;

namespace CovidRecommendationAppTests
{
	TEST_CLASS(CovidRecommendationAppTests)
	{
	public:

		TEST_METHOD(TestUnknownMenuInput)
		{
			Menu menu;
			string actualResult = menu.menuSelect(0);
			string explectedResult = "Unknown selection, please try again";
			Assert::AreEqual(actualResult, explectedResult);
		}

		TEST_METHOD(TestCloseMenu)
		{
			Menu menu;
			string actualResult = menu.menuSelect(6);
			string explectedResult = "Goodbye";
			Assert::AreEqual(actualResult, explectedResult);
		}
	};
}