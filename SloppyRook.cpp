#include "SloppyRook.h"
#include "ChessMaster.h"

SloppyRook::SloppyRook() :ChessPiece('r')
{
}

vector<pair<int, int>> SloppyRook::possibleMovements(pair<int, int> p)
{

	auto map = ChessMaster::getTable();
	int siz = map->Cells().size();
	int x = p.second;
	int y = p.first;

	vector<pair<int, int>> v;
	if (x)
	{
		if (map->Cells()[y][x - 1].seeThing() == 0 || !map->Cells()[y][x - 1].seeThing()->blocks())
			v.push_back({ y,x - 1 });
	}
	if (y)
	{
		if (map->Cells()[y - 1][x].seeThing() == 0 || !map->Cells()[y - 1][x].seeThing()->blocks())
			v.push_back({ y - 1,x });
	}
	if (x < siz - 1)
	{
		if (map->Cells()[y][x + 1].seeThing() == 0 || !map->Cells()[y][x + 1].seeThing()->blocks())
			v.push_back({ y, x + 1 });
	}
	if (y < siz - 1)
	{
		if (map->Cells()[y + 1][x].seeThing() == 0 || !map->Cells()[y + 1][x].seeThing()->blocks())
			v.push_back({ y + 1,x });
	}

	return v;
}
