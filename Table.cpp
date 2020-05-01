#include "Table.h"

Table::Table(int ms):size(ms)
{
}

vector<vector<Cell>>& Table::Cells()
{
	return cells;
}


ostream& operator<<(ostream& out, const Table& t)
{
	
	for (auto linie : t.cells)
		for (auto cell : linie)
			if(cell.visible())
			out << cell;
	return out;
}
