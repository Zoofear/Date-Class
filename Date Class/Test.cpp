
#include <iostream>
#include "Date Class.h"

using namespace std;

int main()
{

	//Create a date object using the default constructor and display the date using the first date format.
	Date Test;

	Test.printNumber();

	cout << endl;

	//Create a date object using the constructor with parameters and display the date using the second format

	Date Test2(2, 28, 2023);

	Test2.printDMY();

	cout << endl;

	//Use one of the date objects to test the setDate() function and display the results u8sing the third format

	Test.setDate(4, 23, 1987);

	cout << Test << endl;

	cout << endl;

	//Use setDate( to set the date to 13/45/2018, 4/31/2000, 2/29/2000 to make sure the date isn't accepted

	cout << "error test 1" << endl;

	Test.setDate(13, 45, 2018);
	
	cout << "error test 2" << endl;

	Test.setDate(4, 31, 2000);

	cout << "error test 3" << endl;

	Test.setDate(2, 29, 2009);

	cout << endl;

	//set the first date object to 4/10/2014 and the second to 4/18/2014, subtract the dates, the answer should be 8

	Test.setDate(4, 10, 2014);
	Test2.setDate(4, 18, 2014);

	int x = Test2 - Test;
	
	cout << x << endl;

	//2/2/2006 - 11/10/2003 = 815

	Test.setDate(2, 2, 2006);
	Test2.setDate(11, 10, 2003);

	x = Test2 - Test;

	cout << x << endl;

	//set the date to 2/29/2008 and increment and print

	Test.setDate(2, 29, 2008);

	Test++;

	cout << Test << endl;

	Test--;
	
	cout << Test << endl;

	++Test;

	cout << Test << endl;

	--Test;

	cout << Test << endl;

	cout << endl;

	//set the date to 12/31/2024 and increment and print

	Test2.setDate(12, 31, 2024);

	Test2++;
	
	cout << Test2 << endl;

	Test2--; 
	
	cout << Test2 << endl;

	++Test2;

	cout << Test2 << endl;

	--Test2;

	cout << Test2 << endl;

	

}