// Date Class.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <iomanip>
#include "Date Class.h"

using namespace std;

Date::Date()
{
	setDate(1, 1, 1930);

	leapYearUpdater();
}

Date::Date(int x, int y, int z)
{
	setDate(x, y, z);

	variableChecker();

	leapYearUpdater();
}

void Date::dateContinuityPlus()
{
	if (day == daysinmonth[monthnumb])
	{
		if (monthnumb = 11)
		{
			setDate(1, 1, year++);
		}
		else
		{
			monthnumb++;
		}
	}
	else
	{
		day++;
	}
}

void Date::dateContinuityMinus()
{
	if (day == 1)
	{
		if (monthnumb = 0)
		{
			setDate(12, daysinmonth[monthnumb], year--);
		}
		else
		{
			monthnumb--;
		}
	}
	else
	{
		day--;
	}
	
}

void Date::variableChecker()
{
	if (monthnumb > 0 && monthnumb < 13)
	{
		if (day > 0 && day <= daysinmonth[monthnumb])
		{
			if (year < 0)
			{
				cout << "Your year must be 0 or greater" << endl;
				setDate(monthnumb, day, 0);
			}
		}
		else
		{
			cout << "Your day integer must be greater than 0 and less then the amount of days in that month" << endl;
			setDate(monthnumb, 1, 0);
		}
	}
	else
	{
		cout << "Your month integer must be 1-12" << endl;
		setDate(0, 1, 0);
	}
}

void Date::leapYearUpdater()
{
	bool check = leapYear();

	if (check == true)
	{
		setMonthDays(1, 29);
	}
	else if (check == false)
	{
		setMonthDays(1, 28);
	}
}

bool Date::leapYear()
{
	double x = year / 400;
	if (x == int(x))
	{
		return true;
	}
	else
	{
		x = year / 4;
		if (x == int(x))
		{
			return true;
		}
		else
		{
			return false;
		}
	}
}

void Date::printNumber()
{
	cout << monthnumb + 1 << "/" << right << setw(2) << setfill('0') << day << "/" << setw(4) << year << setfill(' ') << left << endl;
}

void Date::printMDY()
{
	cout << month[monthnumb] << " " << right << setw(2) << setfill('0') << day << setfill(' ') << ", " << setw(4) << setfill('0') << year << left << endl;
}

void Date::printDMY()
{
	cout << right << setw(2) << setfill('0') << day << left << setfill(' ') << " " << month[monthnumb] << " " << right << setw(4) << setfill('0') << year << left << endl;
}

Date Date::operator++()
{
	if (day == daysinmonth[monthnumb])
	{
		if (monthnumb = 11)
		{
			setDate(1, 1, year++);
		}
		else
		{
			monthnumb++;
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
	Date temp(monthnumb + 1, day, year);

	if (day == daysinmonth[monthnumb])
	{
		if (monthnumb = 11)
		{
			setDate(1, 1, year++);
		}
		else
		{
			monthnumb++;
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
	if (day == 1)
	{
		if (monthnumb = 0)
		{
			setDate(12, daysinmonth[monthnumb], year--);
		}
		else
		{
			monthnumb--;
		}
	}
	else
	{
		day--;
	}
	
	return *this;
}

Date Date::operator--(int)
{
	
	Date temp(monthnumb + 1, day, year);
	
	if (day == 1)
	{
		if (monthnumb = 0)
		{
			setDate(12, daysinmonth[monthnumb], year--);
		}
		else
		{
			monthnumb--;
		}
	}
	else
	{
		day--;
	}
	
	return temp;
}

int Date::operator -(const Date&) const
{
	Date temp;
	
	int x = 0;
	int tempday = temp.returnDay();
	int tempmonth = temp.returnMonthNum();
	int tempyear = temp.returnYear();

	while (tempday != day && tempmonth != monthnumb && tempyear != year)
	{
		--temp;
		x++;
	}

	return x;
}

ostream& operator<<(ostream& stream, Date& dates)
{
	int x = dates.returnMonthNum();
	stream << dates.month[x]  << " " << right << setw(2) << setfill('0') << dates.day << setfill(' ') << ", " << setw(4) << setfill('0') << dates.year << left << endl;
	return stream;
}
 
istream& operator >>(istream& stream, Date& dates)
{
	stream >> dates.monthnumb >> dates.day >> dates.year;
	dates.monthnumb = dates.monthnumb - 1;
	dates.variableChecker();
	return stream;
}