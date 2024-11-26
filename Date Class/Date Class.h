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
	
	Date(int m = 1, int d = 1, int y = 1930) : month(m), day(d), year(y) {}

	//Functions

	void setDate(int x, int y, int z);

	void printNumber();

	void printMDY();

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

	string monthday[11];

	int year;

};