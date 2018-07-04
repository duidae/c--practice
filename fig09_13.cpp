#include <iostream>
using std::cout;
using std::endl;

#include "CreateAndDestroy.h"

void create(void);

CreateAndDestroy first(1, "(global before main)");

int main()
{
	CreateAndDestroy second(2, "(local automatic in main)");
	static CreateAndDestroy third(3, "(local static in main)");

	create();

	return 0;
}

void create()
{
	CreateAndDestroy fifth(5,"(local automatic in create)");
	static CreateAndDestroy sixth(6,"(local static in create)");
	CreateAndDestroy seventh(7,"(local automatic in create)");

}
