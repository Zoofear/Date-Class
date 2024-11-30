//
#pragma once

#include <iostream>

using namespace std;

//Coonstant for the number of months in a year
const int NumMonths = 12;

class Date;
ostream& operator<<(ostream&, Date&);
istream& operator>>(istream&, Date&);

class Date
{
public:
	//Constructor
	
	Date();

	Date(int x, int y, int z);

	//Functions

	//Takes the int x (1-12) for months, y(1-31) for days, z for years and stores them
	void setDate(int x, int y, int z)
	{
		monthnumb = x--;
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

	//This function will update the array on the selected month using the int x and change the days of that month using the int y
	void setMonthDays(int x, int y)
	{
		daysinmonth[x] = y;
	}
	//This function will check the month, and the amount of days in the month
	//It will check to see if the current day is the 31st/30th
	//If it is, it will increment to the next month.
	//If the month is december(12), it will add a year to the year variable and set the month variable to january(1)
	void dateContinuityPlus();

	//This one functions exactly like the function daateContinuityPlus, except it only checks for the 1st of each month and if it is january(1) to subtract a year
	void dateContinuityMinus();

	//Checks to make sure that the month variable is 1-12, then checks to make sure that they day variable resides within the amount of days within the months.
	void variableChecker();
	//outputs an error message and exits the program if the variables do not work
	
	//Runs the function leapYear()
	//If true sets updates the days[1] value (febuary's days) to 29
	//If false updates the days[1] value (febuary's days) to 28
	void leapYearUpdater();

	//Check if year is divided by 400 without a decimal
	//If year isn't divisible by 400, see if it is divisible by 4 without a decimal
	//If divisible by 400 or 4 without a decimal, it is a leap year
	bool leapYear();
	//If leap year, return true, if not a leap year return false
	//Takes the day, month, and year and outputs it in this format: 12/25/2021
	void printNumber();

	//Takes the day, month, and year and outputs it in this format: December 25, 2021
	void printMDY();

	//Takes the day, month, and year and outputs it in this format: 25 December 2021
	void printDMY();

	void printDays()
	{
		for (int x = 0; x < 12; x++)
		{
			cout << month[x] << ":" << daysinmonth[x];
		}
		cout << endl;
	}

	//Operator Overloads

	Date operator++();
	Date operator++(int);
	Date operator--();
	Date operator--(int);
	int operator -(const Date&) const;
	friend ostream& operator <<(ostream&, Date&);
	friend istream& operator >>(istream&, Date&);


private:

	int day;

	int monthnumb;

	string month[NumMonths] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "November", "December" };

	int daysinmonth[NumMonths] = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	int year;

};