// Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Date Class.h"

using namespace std;

Date::Date()
{
	setDate(1, 1, 1930);

	leapYearUpdater();
}


void Date::dateContinuityPlus()
{

}