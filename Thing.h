#pragma once
#include <iostream>
using namespace std;
class Thing
{
	char c;
	friend ostream& operator<<(ostream&, const Thing&);
};
