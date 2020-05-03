#include "Knight.h"
#include "ChessMaster.h"
Knight::Knight() :ChessPiece('k')
{
}

vector<pair<int, int>> Knight::possibleMovements(pair<int, int> p)
{
	auto map = ChessMaster::getTable();
	int siz = map->Cells().size();
	int x = p.second;
	int y = p.first;
	vector<int> s;
	vector<pair<int, int>> v;
	s.push_back(-2);
	s.push_back(-1);
	s.push_back(1);
	s.push_back(2);
	for (auto i : s)
		for (auto j : s)
			if (abs(i) != abs(j))
			{

				if (y + i < siz && y + i >= 0 && x + j < siz && x + j >= 0 && (map->Cells()[y + i][x + j].seeThing() == 0 || !map->Cells()[y + i][x + j].seeThing()->blocks()))
					v.push_back({ y + i,x + j });


			}
	return v;

}
