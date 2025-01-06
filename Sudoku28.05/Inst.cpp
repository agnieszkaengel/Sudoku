#include <iostream>
#include"wspol.hpp"
#include"frame.hpp"
#include"Inst.hpp"
#include"letters.hpp"

using namespace std;

void Inst::print_instheader(void)
{
	gotoxy(start.x, start.y);
	cout << "\x1B[95m" << " _           _              _         _";
	gotoxy(start.x, start.y + 1);
	cout << "\x1B[95m" << "(_)_ __  ___| |_ _ __ _   _| | _____ (_) __ _";
	gotoxy(start.x, start.y + 2);
	cout << "\x1B[95m" << "| | '_ " << char(92) << "/ __| __ |'__| | | | |/ / __|| |/ _` |";
	gotoxy(start.x, start.y + 3);
	cout << "\x1B[95m" << "| | | | " << char(92) << " __" << char(92) << " |_| |  | |_| |   < (__ | | (_| |";
	gotoxy(start.x, start.y + 4);
	cout << "\x1B[95m" << "|_|_| |_|___/" << char(92) << "__|_|   " << char(92) << "__,_|_|" << char(92) << "_" << char(92) << "___|/ |" << char(92) << "__,_|";
	gotoxy(start.x, start.y + 5);
	cout << "\x1B[95m" << "                                  |__ /";
}

void Inst::print_lines(void)
{
	vertical_edge(30, start.x - 9, start.y + 1);
	vertical_edge(30, start.x + 45 + 9, start.y + 1);
}

void Inst::print_text(void)
{
	gotoxy(start.x - 2, start.y + 7);
	cout << "\x1B[94m" << char(254) << " Gra dla jednego gracza: gracz wybiera pola na";
	gotoxy(start.x-2, start.y + 8);
	cout << "\x1B[94m" << "  planszy, w ktore kolejno wpisuje wybrane cyfry.";

	gotoxy(start.x - 2, start.y + 10);
	cout << "\x1B[94m" << char(254) << " Gra z automatem: najpierw ruch wykonuje automat.";
	gotoxy(start.x - 2, start.y + 11);
	cout << "\x1B[94m" << "  Nastepnie gracz wybiera pola na planszy, w ktore";
	gotoxy(start.x - 2, start.y + 12);
	cout << "\x1B[94m" << "  kolejno wpisuje wybrane cyfry, nastepnie otrzymuje";
	gotoxy(start.x - 2, start.y + 13);
	cout << "\x1B[94m" << "  informacje, czy wpisana cyfra jest prawidlowa.";


	gotoxy(start.x - 2, start.y + 15);
	cout << "\x1B[94m" << char(254) << " Gra dla dwoch graczy: gracze wykonuja ruchy na";
	gotoxy(start.x - 2, start.y + 16);
	cout << "\x1B[94m" << "  zmiane. Po kazdym ruchu otrzymuja informacje, czy";
	gotoxy(start.x - 2, start.y + 17);
	cout << "\x1B[94m" << "  wpisana cyfra jest poprawna. Wygrywa ten, ktory";
	gotoxy(start.x - 2, start.y + 18);
	cout << "\x1B[94m" << "  otrzyma wiecej punktow w rozgrywce";


	gotoxy(start.x - 2, start.y + 20);
	cout << "\x1B[94m" << char(254) << " PUNKTACJA: gracz otrzymuje za kazda poprawna";
	gotoxy(start.x - 2, start.y + 21);
	cout << "\x1B[94m" << "  odpowiedz 2 punkty, a za kazda niepoprawna";
	gotoxy(start.x - 2, start.y + 22);
	cout << "\x1B[94m" << "  -1 punkt.";

	gotoxy(start.x - 2, start.y + 24);
	cout << "\x1B[94m" << char(254) << " UWAGA: wpolrzedne pola nalezy wpisywac ciagiem np.";
	gotoxy(start.x - 2, start.y + 25);
	cout << "  a2, g9 (najpierw litera potem cyfra). Kazde wpisanie";
	gotoxy(start.x - 2, start.y + 26);
	cout << "  danych nalezy zatwierdzic ENTEREM.";
}

void Inst::print_box(void)
{
	print_frame(44, 1, start.x + 1, start.y + 28);
	gotoxy(start.x + 1 + 6, start.y + 29);
	cout << "\x1B[94m" << "Wpisz M, aby wrocic do menu:  ";
}

void Inst::print_inst(void)
{
	print_SUDOKU();
	print_lines();
	print_instheader();
	print_text();
	print_box();
}