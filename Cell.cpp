#include "Cell.h"
#include "Thing.h"
ostream& operator<<(ostream& out, const Cell& c)
{
	if (c.vis)
		if (c.t)
			out << *(c.t);
		else
			out << ' ';
	else
		out << '#';
	return out;
}

Cell::Cell() :t(0), vis(false), visi(false)
{
}



bool Cell::visible() const
{
	return vis;
}

bool Cell::visited() const
{
	return visi;
}

void Cell::visit()
{
	if (visi == false && t)
		t->doThing();

	visi = true;
}

void Cell::see()
{
	vis = true;
}

void Cell::put(Thing* thing)
{
	t = thing;
}


Thing* Cell::take()
{
	auto aux = t;
	t = 0;
	return aux;
}

Thing* Cell::move(Cell& c)
{
	auto x = c.t;
	c.t = this->t;
	return x;

}

Thing* Cell::seeThing()
{
	see();
	return t;
}
