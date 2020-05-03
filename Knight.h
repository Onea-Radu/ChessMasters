#pragma once
#include "ChessPiece.h"

class Knight :
	public ChessPiece
{
public:
	Knight();
	vector<pair<int, int>> possibleMovements(pair<int, int>);
};
