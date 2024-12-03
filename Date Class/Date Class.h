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
		monthnumb = x;
		day = y;
		year = z;

		variableChecker();

		monthname = monthnumb - 1;

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
	
	//Checks what the month is
	//If the month is Febuaryr, runs the function leapYear()
	//If leapYear is true, returns 29, if leapyear is false, returns 28
	//If not febuary, returns the amount of days in that month
	int returnDaysInMonth();

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

	//Operator Overloads

	//This operator will check the month, and the amount of days in the month
	//It will check to see if the current day is the 31st/30th
	//If it is, it will increment to the next month.
	//If the month is december(12), it will add a year to the year variable and set the month variable to january(1)
	Date operator++();
	Date operator++(int);

	//This one operator is exactly like the operator ++, except it only checks for the 1st of each month and if it is january(1) to subtract a year
	Date operator--();
	Date operator--(int);

	//increments downwards and counts how many times it does that to see how many days between the dates
	int operator -(Date& x);

	//prints the object
	friend ostream& operator <<(ostream&, Date&);
 
	//inputs the parameters of the object from user inputted data
	friend istream& operator >>(istream&, Date&);


private:

	//The current day
	int day;

	//The current month, used for iterating and outputting
	int monthnumb;
	
	//A place to store how many days in the month
	int monthdays;

	//A place to store the name of the month
	string monthname;

	string month[NumMonths] = { "January", "Febuary", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	//Extra 0 value so that the number of days in the month lines up with 1-12
	int daysinmonth[NumMonths + 1] = {0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };

	//The current year
	int year;

};