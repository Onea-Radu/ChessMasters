#include "Table.h"

Table::Table(int ms) :size(ms)
{
}

vector<vector<Cell>>& Table::Cells()
{
	return cells;
}


ostream& operator<<(ostream& out, const Table& t)
{

	for (auto linie : t.cells)
	{
		out << '|';
		for (auto cell : linie)
			out << cell;
		out << '|';
		out << endl;

	}
	out << endl;
	return out;
}
