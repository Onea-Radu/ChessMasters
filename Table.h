#pragma once
#include <vector>
#include <iostream>
#include "Cell.h"
using namespace std;
class Table
{
	int size;
	vector<vector<Cell>> cells;
public:
	Table(int);
	friend ostream& operator<< (ostream&, const Table&);
	vector<vector<Cell>>& Cells();

};
