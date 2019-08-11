#include <iostream>

#include "Frog.h"
using namespace std;

void Frog::eat()
{
	age++;
}

void Frog::grow()
{
	length++;
}

void Frog::report()
{
	cout << "age: " << age << "months old" << endl;
	cout << "length: " << length << "mm" << endl;
	if (age < 3)
	{
		tadpole = true;
		cout << "tadpole? " << "Yes" << endl;
	} else
	{
		tadpole = false;
		cout << "tadpole? " << "No" << endl;
	}
	//cout << tadpole << endl; //test
}