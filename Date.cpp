#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

Date::Date(int m, int d, int y)
{
	month = m;
	day = d;
	year = y;
}

void Date::print()
{
	cout << month << "/" << day << "/" << year;
}
