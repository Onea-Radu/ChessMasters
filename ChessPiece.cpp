#include "ChessPiece.h"

void ChessPiece::doThing()
{
}

void ChessPiece::setPosition(pair<int, int> pos)
{
	position = pos;
}

void ChessPiece::go(pair<int, int> p)
{
	goingSomewhere.push_back(p);
}

pair<int, int> ChessPiece::nextPosition()
{
	auto aux = goingSomewhere[0];
	goingSomewhere.erase(goingSomewhere.begin());
	return aux;
}

pair<int, int> ChessPiece::getPosition()
{
	return position;
}

ChessPiece::ChessPiece(char c) : Thing(c, false)
{
}
bool ChessPiece::going()
{
	return goingSomewhere.size() != 0;
}

void ChessPiece::stop()
{
	goingSomewhere.clear();
}
