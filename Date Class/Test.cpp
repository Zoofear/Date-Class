
#include <iostream>
#include "Date Class.h"

using namespace std;

int main()
{

Date Test3;

Date Test(5, 3, 1930);

Date Test2(12, 2, 14);

Test.printNumber();

Test2.printNumber();

int month = Test2.returnMonthNum();
cout << month << endl;

string monthname = Test2.returnMonthStr();

cout << monthname << endl;

Test2.printDMY();
Test2.printMDY();

Test2.setDate(3, 5, 1931);

int y = Test2.returnMonthNum();

Test2++;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2--;
Test2.printNumber();
Test2++;
Test2.printNumber();
Test2++;
Test2.printNumber();
Test2++;
Test2.printNumber();
Test2++;

int x = Test - Test2;

cout << x << endl;

}