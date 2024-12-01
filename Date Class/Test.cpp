
#include <iostream>
#include "Date Class.h"

using namespace std;

int main()
{

Date Test;

Date Test2(12, 2, 14);

Test.printDays();
Test.printNumber();

Test2.printNumber();

int month = Test2.returnMonthNum();
cout << month << endl;

string monthname = Test2.returnMonthStr();

cout << monthname << endl;

Test2.printDMY();
Test2.printMDY();

Test2.setDate(1, 5, 1931);

int y = Test2.returnMonthNum();

Test2++;

Test2.printNumber();
Test2--;
Test2.printNumber();

int x = Test - Test2;

cout << x << endl;

}