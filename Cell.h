#pragma once
#include<iostream>
#include "Thing.h"
using namespace std;
class Cell
{
	Thing* t;
	bool vis;

public:
	bool visible();
	friend ostream& operator<<(ostream& out, const Cell& c);
};

