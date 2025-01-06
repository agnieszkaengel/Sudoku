
#include"Player.hpp"
#include"wspol.hpp"
#include "Board.hpp"
#include"control.hpp"
#include<iostream>
using namespace std;

void HumanPlayer::getMove(char& x, int& y, int& v)
{
	check_charintvalue(x, y, 56, 32);
	if (x == 'K')
		return;

	gotoxy(46, 33);
	v = check_intvalue(1,9,45,33);
}

void AutoPlayer::getMove(char& x, int& y, int& v)
{
	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < P; j++)
		{
			if (board->get_value(i,j) > 0)
			{
				for (int k = 0; k < P; k++)
				{
					tab[k][j][board->get_value(i,j) - 1] = false;
					tab[i][k][board->get_value(i,j) - 1] = false;
					tab[i][j][k] = false;
				}
				for (int k = 0; k < P/3; k++)
					for (int m = 0; m < P/3; m++)
						tab[3*(i / (P/3)) + k][(P/3)*(j / (P/3)) + m][board->get_value(i, j) - 1] = false;
			}
		}
	}
	
	int ile[P][P];
	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++)
			ile[i][j] = 0;

	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++)
			for (int k = 0; k < P; k++)
				if (tab[i][j][k])
					ile[i][j]++;

	int min = 10; 
	int min_i, min_j;
	for (int i = 0; i < P; i++)
		for (int j = 0; j < P; j++)
			if (ile[i][j] < min && ile[i][j] > 0)
			{
				min = ile[i][j];
				min_i = i;
				min_j = j;
			}

	int m = 0;

	if(min!=0)
		m = 1 + rand() % min;

	int i = 0;
	while (i < P)
	{
		if (tab[min_i][min_j][i])
		{
			m--;
			if (m == 0)
				break;
		}
		i++;
	}
	tab[min_i][min_j][i] = false;

	x = 'a' + min_i;
	y = min_j  + 1;
	v = i + 1;

	gotoxy(56, 32);
	cout << x;
	gotoxy(57, 32);
	cout << y;
	gotoxy(45, 33);
	cout << v;
	gotoxy(30, 39);
	system("pause");
}