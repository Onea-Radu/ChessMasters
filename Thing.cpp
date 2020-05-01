#include "Thing.h"

ostream& operator<<(ostream& out, const Thing& t)
{

	out << t.c;
	return out;
}
