// Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include <cmath>
#include "Date Class.h"

using namespace std;

Date::Date()
{
	setDate(1, 1, 1930);
	
}

Date::Date(int x, int y, int z)
{
	setDate(x, y, z);

}

void Date::variableChecker()
{
	

	if (monthnumb > 0 && monthnumb < 13 )
	{
		
		monthdays = returnDaysInMonth();

		if (day > 0 && day <= monthdays )
		{
			if (year < 0)
			{
				cout << "Your year must be 0 or greater" << endl;
				setDate(1, 1, 1930);
			}
			else
			{
				return;
			}
		}
		else
		{
			cout << "Your day integer must be greater than 0 and less then or equal to the amount of days in that month" << endl;
			setDate(1, 1, 1930);
		}
	}
	else
	{
		cout << "Your month integer must be 1-12" << endl;
		setDate(1, 1, 1930);
	}
}

int Date::returnDaysInMonth()
{
	if (monthnumb == 2)
	{
		//This is in here so it only needs to check for a leap year when it is relevant
		bool check = leapYear();
		if (check == true)
		{
			return 29;
		}
		else if (check == false)
		{
			return 28;
		}
	}
	else
	{
		return daysinmonth[monthnumb];
	}
}

bool Date::leapYear()
{
	//Need to static_cast to make sure the output doesnt get rounded
	double x = year / static_cast<double>(400);	//Gregorian calendar considers century years non divisible by 400 to not be leap years
	if (x == floor(x))	//Floor used to make sure that it doesnt round up and cause a leap year to be false when it is not
	{
		return true;
	}
	else
	{
		//Need to static_cast to make sure the output doesnt get rounded
		x = year / static_cast<double>(4);
		if (x == floor(x))	//Floor used to make sure that it doesnt round up and cause a leap year to be false when it is not
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

int Date::dateValueCalc()
{
	Date temp(monthnumb, day, year);
	int count = 0;

	//This loop will count how many days by checking to see if the temp date is larger and counting down day by day to see how many days it will take to make them equal
	while (temp.day > 1 || temp.monthnumb > 1 || temp.year > 0)
	{
		if (temp.year >= 0)
		{
			if (temp.day == 1)
			{
				if (temp.monthnumb == 1)
				{
					temp.year--;
					temp.setDate(12, temp.daysinmonth[12], temp.year);
				}
				else
				{
					temp.monthnumb--;
					//This makes sure it can go from march-feb
					temp.monthdays = temp.returnDaysInMonth();
					temp.setDate(temp.monthnumb, temp.monthdays, temp.year);
				}

			}
			else
			{
				temp.day--;
			}

			count++;

		}
		else
		{
			cout << "your year cannot go negative" << endl;

			exit(2);
		}
	}

	return count;
}

void Date::printNumber()
{
	cout << right << setw(2) << setfill('0') << monthnumb << "/" << day << "/" << setw(4) << year << setfill(' ') << left << endl;
}

void Date::printMDY()
{
	monthname = month[monthnumb - 1];	//This is used because the array starts from 0 instead of one, so i need to index it all back by a single value to output the correct name
	cout << monthname << " " << right << setw(2) << setfill('0') << day << setfill(' ') << ", " << setw(4) << setfill('0') << year << left << endl;
}

void Date::printDMY()
{
	monthname = month[monthnumb - 1];	//This is used because the array starts from 0 instead of one, so i need to index it all back by a single value to output the correct name
	cout << right << setw(2) << setfill('0') << day << left << setfill(' ') << " " << monthname << " " << right << setw(4) << setfill('0') << year << left << endl;
}

Date Date::operator++()
{
	//Need to make sure it can go between feb - march 
	monthdays = returnDaysInMonth();
	if (day == monthdays)
	{
		if (monthnumb == 12)
		{
			year++;
			setDate(1, 1, year);
			
		}
		else
		{
			monthnumb++;
			setDate(monthnumb, 1, year);
		}
	}
		else
		{
			day++;
		}

	return *this;
}

Date Date::operator++(int)
{
	Date temp(monthnumb, day, year);

	//Need to make sure it can go between feb - march 
	monthdays = returnDaysInMonth();
	if (day == monthdays)
	{
		if (monthnumb == 12)
		{
			year++;
			setDate(1, 1, year);
			
		}
		else
		{
			monthnumb++;
			setDate(monthnumb, 1, year);
		}
	}
	else
	{
		day++;
	}

	return temp;
}

Date Date::operator--()
{
	if (year >= 0)
	{
		if (day == 1)
		{
			if (monthnumb == 1)
			{
				year--;
				setDate(12, daysinmonth[12], year);
				
			}
			else
			{
				monthnumb--;
				//This makes sure it can go from march-feb
				monthdays = returnDaysInMonth();
				setDate(monthnumb, monthdays, year);
			}

		}
		else
		{
			day--;

		}
	}
	else
	{
		cout << "your year cannot go negative" << endl;

		exit(2);
	}
	
	return *this;
}

Date Date::operator--(int)
{
	
	Date temp(monthnumb, day, year);
	
	if (year >= 0)
	{
		if (day == 1)
		{
			if (monthnumb == 1)
			{
				year--;
				setDate(12, daysinmonth[12], year);
				
			}
			else
			{
				monthnumb--;
				//This makes sure it can go from march-feb
				monthdays = returnDaysInMonth();
				setDate(monthnumb, monthdays, year);
			}

		}
		else
		{
			day--;

		}
	}
	else
	{
		cout << "your year cannot go negative" << endl;

		exit(2);
	}

	return temp;
}

int Date::operator -(Date& x)
{
	Date temp(monthnumb, day, year);
	int tempnum = temp.dateValueCalc();
	int xnum = x.dateValueCalc();

	int answer = xnum - tempnum;
	answer = abs(answer);

	return answer;
}

ostream& operator<<(ostream& stream, Date& dates)
{
	//This is used because the array starts from 0 instead of one, so i need to index it all back by a single value to output the correct name
	dates.monthname = dates.month[dates.monthnumb - 1];
	stream << dates.monthname << " " << right << setw(2) << setfill('0') << dates.day << setfill(' ') << ", " << setw(4) << setfill('0') << dates.year << left << endl;
	return stream;
}
 
istream& operator >>(istream& stream, Date& dates)
{
	stream >> dates.monthnumb >> dates.day >> dates.year;
	dates.variableChecker();
	return stream;
}