#pragma once
#include "ChessPiece.h"
class SloppyRook :
	public ChessPiece
{
public:
	SloppyRook();
	vector<pair<int, int>> possibleMovements(pair<int, int>);

};
