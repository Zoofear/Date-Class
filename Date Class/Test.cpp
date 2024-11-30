
#include <iostream>
#include "Date Class.h"

using namespace std;

int main()
{

Date Test;

Date Test2(1, 2, 14);

Test.printDays();
Test.printNumber();

Test2.printNumber();
Test2.printDMY();
Test2.printMDY();

cout << "add a new date" << endl;
cin >> Test2;

cout << Test2;
}