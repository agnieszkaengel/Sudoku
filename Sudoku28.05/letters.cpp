#include <iostream>
#include <stdlib.h>
#include <Windows.h>
#include "letters.hpp"

#include "Board.hpp"
#include "player.hpp"
#include "frame.hpp"

using namespace std;

void create_S(bool S[LHeight][LWidth])
{
	for (int i = 0; i < LHeight; i++)
	{
		for (int j = 0; j < LWidth; j++)
		{
			if (i == 1 && (j != 0 && j != 1))
				S[i][j] = false;
			else if (i == 3 && (j != LWidth - 2 && j != LWidth - 1))
				S[i][j] = false;
			else
				S[i][j] = true;
		}
	}
}

void create_U(bool U[LHeight][LWidth])
{
	for (int i = 0; i < LHeight; i++)
	{
		for (int j = 0; j < LWidth; j++)
		{
			if (i < LHeight - 1 && (j != 0 && j != 1 && j != LWidth - 1 && j != LWidth - 2))
				U[i][j] = false;
			else
				U[i][j] = true;
		}
	}
}

void create_D(bool D[LHeight][LWidth])
{
	for (int i = 0; i < LHeight; i++)
	{
		for (int j = 0; j < LWidth; j++)
		{
			if (i < LHeight - 1 && i>0 && (j > 1 && j < LWidth - 2))
				D[i][j] = false;
			else  if ((i == 0 || i == LHeight - 1) && (j == LWidth - 1 || j == LWidth - 2))
				D[i][j] = false;
			else
				D[i][j] = true;
		}
	}
}

void create_O(bool O[LHeight][LWidth])
{
	for (int i = 0; i < LHeight; i++)
	{
		for (int j = 0; j < LWidth; j++)
		{
			if (i < LHeight - 1 && i>0 && (j > 1 && j < LWidth - 2))
				O[i][j] = false;
			else
				O[i][j] = true;
		}
	}
}

void create_K(bool K[LHeight][LWidth])
{
	for (int i = 0; i < LHeight; i++)
	{
		for (int j = 0; j < LWidth; j++)
		{
			if ((i != 2 && (j == 2 || j == 3)) || (i == 2 && (j == 5 || j == 4)))
				K[i][j] = false;
			else
				K[i][j] = true;
		}
	}
}

void print_letter(bool letter[LHeight][LWidth], int position)
{
	for (int i = 0; i < LHeight; i++)
	{
		gotoxy(position, i + 2);
		for (int j = 0; j < LWidth; j++)
		{
			if (letter[i][j])
				cout << "\x1B[95m" << K;
			else
				cout << "\x1B[30m" << K;

		}
		cout << endl;
	}
	cout << endl;
}


void print_SUDOKU(void)
{
	print_frame(Columns, Rows, 0, 0);
	bool S[LHeight][LWidth], U[LHeight][LWidth], D[LHeight][LWidth], O[LHeight][LWidth], K[LHeight][LWidth];
	create_S(S);
	create_U(U);
	create_D(D);
	create_O(O);
	create_K(K);
	int C = (Columns - Stringlen) / 2; //numer kolumny w ktorej zaczyna sie napis
	print_letter(S, C); 
	print_letter(U, C + 7);
	print_letter(D, C + 14);
	print_letter(O, C + 21);
	print_letter(K, C + 28);
	print_letter(U, C + 35);
}