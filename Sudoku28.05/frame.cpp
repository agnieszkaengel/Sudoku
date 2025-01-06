#include <iostream>
#include "frame.hpp"
#include "wspol.hpp"

using namespace std;

void horizontal_edge(int len, int x, int y, bool up)
{
	gotoxy(x, y);
	for (int i = 0; i < len; i++)
	{
		if (i == 0)
		{
			if (!up)
				cout << "\x1B[95m" << LDR;
			else
			{
				cout << "\x1B[95m" << LGR;
			}
		}
		else if (i == len - 1)
		{
			if (!up)
				cout << "\x1B[95m" << PDR;
			else
				cout << "\x1B[95m" << PGR;
		}
		else
			cout << "\x1B[95m" << DH;
	}
}

void vertical_edge(int len, int x, int y)
{
	for (int i = 0; i < len; i++)
	{
		gotoxy(x, y + i);
		cout << "\x1B[95m" << DP;
	}
}

void print_frame(int lenhor, int lenver, int x, int y)
{
	int a = x;
	int b = y;
	horizontal_edge(lenhor, x, y, true);
	y += 1;
	vertical_edge(lenver, x, y);
	y += lenver;
	horizontal_edge(lenhor, x, y, false);
	x += lenhor - 1;
	y = b + 1;
	vertical_edge(lenver, x, y);

	x = a;
	y = b;
}