#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include<stdlib.h>
#include<string>
#include<fstream>
#include"wspol.hpp"
#include"Board.hpp" 
#include"frame.hpp"
using namespace std;


//funkcja wypisuje górną część planszy do gry w sudoku, uwzględniając grubsze linie na zewnętrznych krawędziach oraz na krawędziach pól 3x3
// %12 == 0 -> gruba linia z grubym odgałęzieniem w dół, %4==0 && %12!=0 -> gruba linia z cienkim odgałęzieniem w dół, krańce -> rogi, pozostałe -> grupe poziome
// ╦ -> \u2566
// ═ -> \u2550
// ╤ -> \u2564
// ╔ -> \u2554
// ╗ -> \u2557
// ║ -> \u2551
// │ -> \u2502



void Board::print_top(void)
{
	gotoxy(start.x, start.y);
	for (int j = 0; j < 37; j++)
	{
		if (j % 4 == 0 && j != 0 && j != 36 && j % 12 != 0)
			cout << "\x1B[94m" << char(209);
		else if (j == 0)
			cout << "\x1B[94m" <<LGR;
		else if (j == 36)
			cout << "\x1B[94m" << PGR;
		else if (j % 12 == 0 && j != 0 && j != 36)
			cout << "\x1B[94m" << char(203);
		else
			cout << "\x1B[94m" << DH;
	}

	start.y++; // przejscie wiersz w dół

	for (int j = 0; j < 37; j = j + 4)
	{
		gotoxy(start.x + j, start.y);
		if (j % 12 == 0)
			cout << "\x1B[94m" << DP;
		else
			cout << "\x1B[94m" << SP;
	}
}
void Board::print_middle()
{
	start.y++;
	gotoxy(start.x, start.y);
	for (int j = 0; j < 37; j++)
	{
		if (j % 4 == 0 && j != 0 && j != 36 && j % 12 != 0)
			cout << "\x1B[94m" << char(197); // ┼
		else if (j == 0)
			cout << "\x1B[94m" << char(199); // ╟
		else if (j == 36)
			cout << "\x1B[94m" << char(182); // ╢
		else if (j % 12 == 0 && j != 0 && j != 36)
			cout << "\x1B[94m" << char(215);// ╫
		else
			cout << "\x1B[94m" << SH; //━
	}
	start.y++; // przejście wiersz w dół

	for (int j = 0; j < 37; j = j + 4)
	{
		gotoxy(start.x + j, start.y);
		if (j % 4 == 0 && j % 12 != 0)
			cout << "\x1B[94m" << SP;
		else
			cout << "\x1B[94m" << DP;
	}
}
void Board::print_middlebold(void)
{
	start.y++;
	gotoxy(start.x, start.y);
	for (int j = 0; j < 37; j++)
	{
		if (j % 4 == 0 && j != 0 && j != 36 && j % 12 != 0)
			cout << "\x1B[94m" << char(216); // ╪
		else if (j == 0)
			cout << "\x1B[94m" << char(204); // ╠
		else if (j == 36)
			cout << "\x1B[94m" << char(185); // ╣
		else if (j % 12 == 0 && j != 0 && j != 36)
			cout << "\x1B[94m" << char(206);// ╬
		else
			cout << "\x1B[94m" << DH; //═
	}
	start.y++; // przejście wiersz w dół

	for (int j = 0; j < 37; j = j + 4)
	{
		gotoxy(start.x + j, start.y);
		if (j % 4 == 0 && j % 12 != 0)
			cout << "\x1B[94m" << SP;
		else
			cout << "\x1B[94m" << DP;
	}
}
void Board::print_bottom(void)
{
	start.y++;
	gotoxy(start.x, start.y);
	for (int j = 0; j < 37; j++)
	{
		if (j % 4 == 0 && j != 0 && j != 36 && j % 12 != 0)
			cout << "\x1B[94m" << char(207); // ╧
		else if (j == 0)
			cout << "\x1B[94m" << LDR; // ╚
		else if (j == 36)
			cout << "\x1B[94m" << PDR; // ╝
		else if (j % 12 == 0 && j != 0 && j != 36)
			cout << "\x1B[94m" << char(202); // ╩
		else
			cout << "\x1B[94m" << DH;
	}
}

string Board::draw_board(void)
{
	int n = 1 + rand() % 10;
	string number = to_string(n);
	return ("sudokuboard" + number + ".txt");
}

void Board::read_board(string filename, int &s1, int &s2)
{
	fstream boarddata;
	boarddata.open(filename, ios::in);
	if (boarddata.good() != true)
	{
		cout << "Blad otwarcia pliku danych." << endl;
	}

	for (int i = 0; i < P; i++)
	{
		for (int j = 0; j < P; j++)
		{
			boarddata >> board[i][j];
			if (board[i][j] < 0)
				emptycount++;
		}
	}
	boarddata >> s1 >> s2;
	boarddata.close();
}

int Board::get_value(int x, int y) //obnizone argumenty do 0 oba
{
	return board[x][y];
}

int Board::convert(char x)
{
	int l = x - 'a';
	return l;
}
void Board::put(int x, int y, int v)
{
	board[x][y-1] = v;
	emptycount--;
}
bool Board::isSolved(void)
{
	if (emptycount != 0)
		return false;
	else
		return true;
}
bool Board::isCorrect(int x, int y, int v)//argumenty takie jak podal uzytkownik (x od 0 przekonwertowany)
{
	return (v * -1) == get_value(x, y-1);
}
void Board::print_coordinates(void)
{
	for (int i = 0; i < 37 - 1; i = i + 4)
	{
		gotoxy(start.x + 2 + i, 9);
		cout << char(49 + i / 4);
	}
	for (int j = 0; j < 19 - 1; j = j + 2)
	{
		gotoxy(25, 11 + j);
		cout << char(97 + j / 2);
	}
}

void Board::print_box(void)
{
	print_frame(33, 2, start.x + 2, start.y + 3);
	gotoxy(start.x + 2 + 2, start.y + 4);
	cout << "\x1B[94m" << "Podaj wspolrzedne pola: ";
	gotoxy(start.x + 2 + 2, start.y + 5);
	cout << "\x1B[94m" << "Podaj cyfre: ";


}
void Board::print_lines(int n)
{
	vertical_edge(5, 4, start.y + 4);
	vertical_edge(5, 24, start.y + 4); 

	gotoxy(5, start.y + 4); 
	cout << "\x1B[94m" << " GRACZ 1";
	gotoxy(5, start.y + 6);
	cout << "\x1B[94m" << " nick:";
	gotoxy(5, start.y + 7);
	cout << "\x1B[94m" << " punkty:";

	if (n == 2)
	{
		vertical_edge(5, Columns - 4, start.y + 4);
		vertical_edge(5, Columns - 24, start.y + 4);
		gotoxy(Columns - 23, start.y + 4);
		cout << "\x1B[94m" << " GRACZ 2";
		gotoxy(Columns - 23, start.y + 6);
		cout << "\x1B[94m" << " nick:";
		gotoxy(Columns - 23, start.y + 7);
		cout << "\x1B[94m" << " punkty:";
	}


}

void Board::print_filledboard(void)
{
	print_SUDOKU();
	for (int i = 0; i < 10; i++)
	{
		if (i == 0)
			print_top();
		else if (i == 9)
			print_bottom();
		else if (i % 3 == 0 && i != 9)
			print_middlebold();
		else
			print_middle();
	}

	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			gotoxy(start.x + 2 + (4 * j), 11 + (2 * i));
			if (board[i][j] >= 0)
				cout << "\x1B[95m" << board[i][j];
		}
	}
	print_coordinates();

	print_frame(33, 1, start.x + 2, start.y + 7);
	gotoxy(start.x + 2 + 2, start.y + 8);
	cout << "\x1B[94m" << "Aby zakonczyc gre, wpisz K";

}

bool Board:: isFree(int x, int y)
{
	if (get_value(x, y-1) < 0)
		return true;
	else
		return false;
} 


void Board::print_board_2players(void)
{
	print_filledboard();
	print_box();
	print_lines(2);
}

void Board::print_board_1player(void)
{
	print_filledboard();
	print_box();
	print_lines(1);
}