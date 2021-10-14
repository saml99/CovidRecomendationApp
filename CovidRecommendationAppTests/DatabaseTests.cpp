#include "pch.h"
#include "CppUnitTest.h"
#include "../CovidRecommendationApp/Database.h"

#include <string>
#include <fstream>

using namespace Microsoft::VisualStudio::CppUnitTestFramework;
using namespace CovidRecommendationApp;
using namespace std;

namespace CovidRecommendationAppTests
{
	TEST_CLASS(DatabaseTests)
	{
	public:

		TEST_METHOD(TestCreateTable)
		{
			Database database;
			string actual;
			string expected = "PatientID\tName\tDate of Birth\tAddress\tVisited Location\tDate/Time\tLast Overseas Travel\tCovid Test\tStatus";
			string file = "PatientDetailTable.txt";
			string headers[9] = {"PatientID", "Name", "Date of Birth", "Address", "Visited Location", "Date/Time", "Last Overseas Travel", "Covid Test", "Status"};
			database.createTable(file, headers);
			ifstream myfile(file);
			getline(myfile, actual);
			Assert::IsTrue(myfile.is_open());
			Assert::AreEqual(actual, expected);
			myfile.close();
		}
	};
}