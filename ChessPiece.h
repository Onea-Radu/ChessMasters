#pragma once
#include <set>
using namespace std;
class ChessPiece
{
	int mapsize;
	pair<int, int> position;
	bool goingSomewhere;
public:
	ChessPiece(int,pair<int,int>);
	virtual set<pair<int,int>> possibleMovements() = 0;
	bool going();
};

