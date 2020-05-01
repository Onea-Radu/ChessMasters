#pragma once
#include "Table.h"
#include "ChessPiece.h"
#include <iostream>
using namespace std;
class ChessMaster
{
	Table t;
	ChessPiece* c;
	bool verbosity;
	static int gamesrun;
public:
	void runGame(bool);
	bool hasEnded();
	static int howManyGames();

};

