#pragma once

#include <iostream>

using namespace std;

namespace CovidRecommendationApp 
{

	class PatientDetailsInputService
	{
	public:
		void enterDetails();
	private:
		bool isNumber(string str);
		void recommendation();
	};

}