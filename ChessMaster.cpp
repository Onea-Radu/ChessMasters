#include "ChessMaster.h"
#include "Final.h"
#include <fstream>
#include "SloppyRook.h"
#include "SloppyBishop.h"
#include "Wall.h"
#include "Knight.h"
Table* ChessMaster::tab = 0;
ChessPiece* ChessMaster::piece = 0;

ChessMaster::ChessMaster() :gameGoing(false), verbosity(false)
{
}

void ChessMaster::runGame(bool v)
{

	verbosity = v;
	gameGoing = true;
	bool first = true;
	bool finality = false;
	cout << "Choose chess piece:\nSloppyRook(r)\nSloppyBishop(b)\nKnight(k)\n";
	char car;
	cin >> car;
	if (car == 'k')
		piece = new Knight();
	if (car == 'r')
		piece = new SloppyRook();
	if (car == 'b')
		piece = new SloppyBishop();

	ifstream f("Map1.txt");
	f >> (*this);
	while (gameGoing)
	{

		auto paux = piece->getPosition();

		tab->Cells()[paux.first][paux.second].visit();
		auto x = piece->possibleMovements(piece->getPosition());
		vector<vector<pair<int, int>>> auxx;
		if (first)
		{

			cout << *tab;
			first = false;
		}
		cout << "Piece is at " << paux.first << " " << paux.second << endl;
		for (int i = 0; i < tab->Cells().size(); i++)
		{
			auxx.push_back(vector<pair<int, int>>());
			for (int j = 0; j < tab->Cells().size(); j++)
			{
				auxx[i].push_back({ -1,-1 });

			}
		}



		if (!piece->going())
		{
			x.clear();
			x.push_back(piece->getPosition());
			for (int i = 0; i < x.size(); i++)
			{
				if (!tab->Cells()[x[i].first][x[i].second].visited())
				{

					auto a = x[i];
					vector<pair<int, int>> v;
					while (a != piece->getPosition())
					{

						v.push_back(a);
						a = auxx[a.first][a.second];
					}
					for (int i = v.size() - 1; i >= 0; i--)
						piece->go(v[i]);
					break;
				}
				else
				{

					auto v = piece->possibleMovements(x[i]);

					for (int sf = 0; sf < v.size(); sf++)
					{


						if (auxx[v[sf].first][v[sf].second] == pair<int, int>({ -1, -1 }))
						{
							x.push_back(v[sf]);
							auxx[v[sf].first][v[sf].second] = x[i];
						}
					}

				}

			}

		}


		auto p = piece->nextPosition();
		cout << "and goes to " << p.first << " " << p.second << endl;
		auto s = tab->Cells()[p.first][p.second].take();
		tab->Cells()[p.first][p.second].put(tab->Cells()[paux.first][paux.second].take());
		if (s)
			s->doThing();
		piece->setPosition(p);
		x = piece->possibleMovements(piece->getPosition());
		for (auto i : x)
		{
			tab->Cells()[i.first][i.second].see();
			if (i == finalPlace)
			{
				cout << "Robot sees finish line\n";
				finality = true;
				piece->stop();
				piece->go(finalPlace);
			}
		}
		cout << *tab;
		cout << endl << endl;
		if (finality)
		{
			paux = piece->getPosition();

			auto p = piece->nextPosition();
			cout << "Piece is at " << paux.first << " " << paux.second << endl;
			cout << "and goes to " << p.first << " " << p.second << endl;
			auto s = tab->Cells()[p.first][p.second].take();
			tab->Cells()[p.first][p.second].put(tab->Cells()[paux.first][paux.second].take());
			if (s)
				s->doThing();
			piece->setPosition(p);
			cout << *tab;
			cout << "Game has ended.";
			return;
		}


		if (verbosity)
		{
			cout << "Continue?(y/n)\n";
			char z;
			cin >> z;
			gameGoing = (z == 'y');
		}
	}


}

void ChessMaster::hasEnded()
{
	gameGoing = false;
}

Table* ChessMaster::getTable()
{
	return tab;
}

ChessPiece* ChessMaster::getPiece()
{
	return piece;
}

istream& operator>>(istream& in, ChessMaster& cm)
{
	int n;
	in >> n;
	cm.tab = new Table(n);
	for (int i = 0; i < n; i++)
	{
		cm.tab->Cells().push_back(vector<Cell>());
		for (int j = 0; j < n; j++)
		{
			char c;
			in >> c;
			Cell cell;
			if (c == '0')
				cell.put(0);
			if (c == 'S')
			{
				cell.see();
				cell.put(ChessMaster::piece);
				ChessMaster::piece->setPosition({ i,j });
			}
			else if (c == 'F')
			{
				cell.put(new Final());
				cm.finalPlace = { i,j };
			}
			else if (c == '%')
			{
				cell.put(new Wall());
			}
			cm.tab->Cells()[i].push_back(cell);
			cell.put(0);
		}
	}
	return in;
}
