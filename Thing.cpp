#include "Thing.h"

ostream& operator<<(ostream& out, const Thing& t)
{
	out << t.c;
	return out;
}

Thing::Thing(char c, bool blocker) :c(c), block(blocker)
{
}

bool Thing::blocks() const
{

	return block;
}
