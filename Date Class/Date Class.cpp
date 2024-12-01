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

void Date::variableChecker()
{
	if (monthnumb >= 1 && monthnumb <= 12 )
	{
		if (day > 0 && day <= daysinmonth[monthnumb])
		{
			if (year < 0)
			{
				cout << "Your year must be 0 or greater" << endl;
				setDate(monthnumb, day, 0);
			}
			else
			{
				return;
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
		setDate(1, 1, 0);
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
	double x = year / static_cast<double>(400);
	if (x == floor(x))
	{
		return true;
	}
	else
	{
		x = year / static_cast<double>(4);
		if (x == floor(x))
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
	cout << monthnumb << "/" << right << setw(2) << setfill('0') << day << "/" << setw(4) << year << setfill(' ') << left << endl;
}

void Date::printMDY()
{
	monthnumb = 12;
	monthname = month[monthnumb - 1];
	cout << monthname << " " << right << setw(2) << setfill('0') << day << setfill(' ') << ", " << setw(4) << setfill('0') << year << left << endl;
}

void Date::printDMY()
{
	monthname = month[monthnumb - 1];
	cout << right << setw(2) << setfill('0') << day << left << setfill(' ') << " " << monthname << " " << right << setw(4) << setfill('0') << year << left << endl;
}

Date Date::operator++()
{
	if (day == daysinmonth[monthnumb - 1])
	{
		if (monthnumb == 12)
		{
			year++;
			setDate(1, 1, year);
			leapYearUpdater();
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
	Date temp(monthnumb, day, year);

	if (day == daysinmonth[monthnumb - 1])
	{
		if (monthnumb == 12)
		{
			year++;
			setDate(1, 1, year);
			leapYearUpdater();
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
	if (year >= 0)
	{
		if (day == 1)
		{
			if (monthnumb == 1)
			{
				year--;
				setDate(12, daysinmonth[monthnumb - 1], year);
				leapYearUpdater();
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
				setDate(12, daysinmonth[monthnumb - 1], year);
				leapYearUpdater();
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
	
	int count = 0;

	cout << temp.day << " " << temp.monthnumb << " " << temp.year << endl;

	while (temp.day > x.day || temp.monthnumb > x.monthnumb || temp.year > x.year)
	{
		if (temp.year >= 0)
		{
			if (temp.day == 1)
			{
				if (temp.monthnumb == 1)
				{
					temp.year--;
					temp.setDate(12, temp.daysinmonth[monthnumb - 1], temp.year);
					temp.leapYearUpdater();

					cout << temp.daysinmonth[monthnumb - 1] << " " << temp.year << endl;
				}
				else
				{
					temp.monthnumb--;
				}

			}
			else
			{
				temp.day--;

				cout << count << endl;

			}

			count++;
			
		}
		else
		{
			cout << "your year cannot go negative" << endl;

			exit(2);
		}
	}
	cout << temp.day << " " << temp.monthnumb << " " << temp.year << endl;
	
	return count;
}

ostream& operator<<(ostream& stream, Date& dates)
{
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