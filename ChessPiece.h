#pragma once
#include "Thing.h"
#include <vector>

using namespace std;
class ChessPiece :public Thing
{
	pair<int, int> position;
	vector<pair<int, int>> goingSomewhere;
public:
	void doThing();
	ChessPiece(char);
	void setPosition(pair<int, int>);
	virtual vector<pair<int, int>> possibleMovements(pair<int, int>) = 0;
	void go(pair<int, int>);
	pair<int, int> nextPosition();
	pair<int, int> getPosition();

	bool going();
	void stop();
};
