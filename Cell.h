#pragma once
#include<iostream>
class Thing;
class Wall;
using namespace std;
class Cell
{
	Thing* t;
	bool vis;
	bool visi;

public:
	Cell();
	bool visible() const;
	bool visited() const;
	void visit();
	void see();
	void put(Thing*);
	Thing* take();
	Thing* move(Cell&);
	Thing* seeThing();
	friend ostream& operator<<(ostream& out, const Cell& c);
};
