#pragma once

#include <iostream>

using namespace std;

namespace CovidRecommendationApp
{

	class PatientDetailsInputService
	{
	public:
		void enterDetails();
		void covidResult();
	private:
		bool isNumber(string str);
		void recommendation();
	};

}