#pragma once
#include "Table.h"
#include "ChessPiece.h"
#include <iostream>
using namespace std;
class ChessMaster
{
	static Table* tab;
	static ChessPiece* piece;
	bool verbosity;
	bool gameGoing;
	pair<int, int> finalPlace;
public:
	ChessMaster();
	void runGame(bool);
	void hasEnded();
	static Table* getTable();
	static ChessPiece* getPiece();

	friend istream& operator>> (istream&, ChessMaster&);
};
