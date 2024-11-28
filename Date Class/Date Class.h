//
#pragma once

#include <iostream>

using namespace std;

const int NumMonths = 12;

ostream& operator<<(ostream&, Date&);
istream& operator>>(istream&, Date&);

class Date
{
public:
	//Constructor
	
	Date(int m = 1, int d = 1, int y = 1930) : monthnumb(m), day(d), year(y) {}

	//Functions

	//Takes the int x (1-12) for months, y(1-31) for days, z for years and stores them
	void setDate(int x, int y, int z)
	{
		monthnumb = x;
		day = y;
		year = z;
	}
	
	//Returns the day variable as an int
	int returnDay()
	{
		return day;
	}
	
	//Returns the month variable as an int
	int returnMonthNum()
	{
		return monthnumb;
	}

	//Returns the month variable as a string
	string returnMonthStr()
	{
		int index = monthnumb - 1;

		return month[index];
	}

	//Returns the year variable as an int
	int returnYear()
	{
		return year;
	}
	
	//Checks to make sure that the month variable is 1-12, then checks to make sure that they day variable resides within the amount of days within the months.
	void variableChecker();
	//outputs an error message and exits the program if the variables do not work
	
	//Check if year is divided by 400 without a decimal
	//If year isn't divisible by 400, see if it is divisible by 4 without a decimal
	//If divisible by 400 or 4 without a decimal, it is a leap year
	bool leapYear();
	//If leap year, return true, if not a leap year return false

	//Checks the flags for the current month and determines whether it is a 31 day, 27/28 day month, and a 30 day month
	int daysInMonth();
	//returns the amount of days in the current month

	//Takes the day, month, and year and outputs it in this format: 12/25/2021
	void printNumber();

	//Takes the day, month, and year and outputs it in this format: December 25, 2021
	void printMDY();

	//Takes the day, month, and year and outputs it in this format: 25 December 2021
	void printDMY();

	//Operator Overloads

	Date operator++();
	Date operator++(int);
	Date operator --();
	Date operator --(int);
	friend ostream& operator <<(ostream&, Date&);
	friend istream& operator >>(istream&, Date&);


private:

	int day;

	int monthnumb;

	string month[NumMonths] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "November", "December" };

	int days[NumMonths] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int year;

};