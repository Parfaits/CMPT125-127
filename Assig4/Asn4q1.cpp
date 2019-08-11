#include <iostream>

#include "Frog.h"


int main()
{
	Frog Bob;
	Bob.report();
	for (int i = 0; i < 3; ++i)
	{
		Bob.eat();
	}
	Bob.report();
	for (int j = 0; j < 3; ++j)
	{
		Bob.grow();
	}
	Bob.report();
	return 0;
}