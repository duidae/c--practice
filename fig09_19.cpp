#include <iostream>
using std::cout;
using std::endl;

#include "Date.h"

int main()
{
	Date date1(7, 4, 2004);
	Date date2;

	cout << "date1 = ";
	date1.print();
	cout << "date2 = ";
	date2.print();

	date2 = date1;
	
	cout << "\n\nAfter default memberwise assignment, date2 = ";
	date2.print();
	cout << endl;

	return 0;
}
