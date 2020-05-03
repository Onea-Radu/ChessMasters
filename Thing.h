#pragma once
#include <iostream>
using namespace std;
class Thing
{
	char c;
	bool block;
public:
	Thing(char, bool);
	virtual void doThing() = 0;
	bool blocks() const;
	friend ostream& operator<<(ostream&, const Thing&);
};
