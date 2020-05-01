#include "Cell.h"

ostream& operator<<(ostream& out, const Cell& c)
{
	out << *(c.t);
	return out;
}

bool Cell::visible()
{
	return vis;
}

