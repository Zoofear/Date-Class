
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

	Test.setDate(2, 29, 2000);

	cout << endl;

	

	

}