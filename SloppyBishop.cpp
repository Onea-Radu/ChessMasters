#include "SloppyBishop.h"
#include "ChessMaster.h"

SloppyBishop::SloppyBishop() :ChessPiece('b')
{
}

vector<pair<int, int>> SloppyBishop::possibleMovements(pair<int, int> p)
{
	auto map = ChessMaster::getTable();
	int siz = map->Cells().size();
	int x = p.second;
	int y = p.first;

	vector<pair<int, int>> v;
	if (x && y)
	{
		if (map->Cells()[y - 1][x - 1].seeThing() == 0 || !map->Cells()[y - 1][x - 1].seeThing()->blocks())
			v.push_back({ y - 1,x - 1 });
	}
	if (x && y < siz - 1)
	{
		if (map->Cells()[y + 1][x - 1].seeThing() == 0 || !map->Cells()[y + 1][x - 1].seeThing()->blocks())
			v.push_back({ y + 1,x - 1 });
	}
	if (y && x < siz - 1)
	{
		if (map->Cells()[y - 1][x + 1].seeThing() == 0 || !map->Cells()[y - 1][x + 1].seeThing()->blocks())
			v.push_back({ y - 1, x + 1 });
	}
	if (x < siz - 1 && y < siz - 1)
	{
		if (map->Cells()[y + 1][x + 1].seeThing() == 0 || !map->Cells()[y + 1][x + 1].seeThing()->blocks())
			v.push_back({ y + 1,x + 1 });
	}

	return v;


}
