#pragma once
#include "ChessPiece.h"
class SloppyBishop :
	public ChessPiece
{
public:
	SloppyBishop();
	vector<pair<int, int>> possibleMovements(pair<int, int>);
};
