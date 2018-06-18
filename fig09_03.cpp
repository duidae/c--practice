#include <iostream>
using std::cout;
using std::endl;

#include "Time.h"

int main()
{
	Time t;

	cout << "universal time:";
	t.printUniversal();
	cout << "standard time:";
	t.printStandard();

	t.setTime(13, 27, 6);

	cout << "universal time:";
	t.printUniversal();
	cout << "standard time:";
	t.printStandard();

	t.setTime(99, 99, 99);

	cout << "universal time:";
	t.printUniversal();
	cout << "standard time:";
	t.printStandard();

	cout << endl;
	return 0;
}
