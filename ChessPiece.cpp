#include "ChessPiece.h"

ChessPiece::ChessPiece(int ms = 0, pair<int, int> pos = {0,0}) :mapsize(ms), position(pos)
{
	goingSomewhere = false;
}

bool ChessPiece::going()
{
	return goingSomewhere;
}
