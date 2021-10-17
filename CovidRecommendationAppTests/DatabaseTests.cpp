#include "pch.h"
#include "CppUnitTest.h"
#include "../CovidRecommendationApp/Database.h"

#include <string>
#include <fstream>
#include <vector>
#include <map>

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
			string expected = "PatientID,Name,Date of Birth,Address,LocationID,Date/Time,Last Overseas Travel,Covid Test,Status,";
			string file = "PatientDetailTable.txt";
			vector<string> headers = {"PatientID", "Name", "Date of Birth", "Address", "LocationID", "Date/Time", "Last Overseas Travel", "Covid Test", "Status"};
			database.createTable(file, headers);
			ifstream myfile(file);
			getline(myfile, actual);
			Assert::IsTrue(myfile.is_open());
			Assert::AreEqual(actual, expected);
			myfile.close();
		}

		TEST_METHOD(TestInsertTable)
		{
			Database database;
			string actual;
			string expected = "1,Sam,26/08/1999,some st,1,16/10/2021 22:32:26,No,Negative,Alive,";
			string file = "PatientDetailTable.txt";
			map<string, string> values { {"PatientID", "1"}, {"Name", "Sam"}, {"Date of Birth", "26/08/1999"}, {"Address", "some st"}, {"LocationID", "1"}, {"Date/Time", "16/10/2021 22:32:26"}, {"Last Overseas Travel", "No"}, {"Covid Test", "Negative"}, {"Status", "Alive"} };
			vector<string> headers = { "PatientID", "Name", "Date of Birth", "Address", "LocationID", "Date/Time", "Last Overseas Travel", "Covid Test", "Status" };
			database.createTable(file, headers);
			database.insertTable(file, values);
			ifstream myfile(file);
			getline(myfile, actual);
			getline(myfile, actual);
			Assert::AreEqual(actual, expected);
			myfile.close();
		}
	};
}