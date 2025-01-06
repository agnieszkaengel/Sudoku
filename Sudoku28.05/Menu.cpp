#include <iostream>
#include "wspol.hpp"
#include"letters.hpp"
#include"frame.hpp"
#include"Menu.hpp"

using namespace std;

void Menu::print_menuheader(void)
{
	gotoxy(start.x, start.y);
	cout << " _ __ ___   ___ _ __  _   _" << endl;
	gotoxy(start.x, start.y + 1);
	cout << "| '_ ` _ " << char(92) << " / _ " << char(92) << " '_ " << char(92) << "| | | |" << endl;
	gotoxy(start.x, start.y + 2);
	cout << "| | | | | |  __/ | | | |_| |" << endl;
	gotoxy(start.x, start.y + 3);
	cout << "|_| |_| |_|" << char(92) << "___|_| |_|" << char(92) << "__,_| " << endl;
}

void Menu::print_lines(void)
{
	vertical_edge(15, 23, start.y + 1);
	vertical_edge(15, 69, start.y + 1);
}
void Menu::print_choices(void)
{
	gotoxy(start.x - 4, start.y + 6);
	cout << "\x1B[94m" << char(254) << "   1. instrukcja ";
	gotoxy(start.x + 30, start.y + 6);
	cout << "\x1B[94m" << char(254);

	gotoxy(start.x - 4, start.y + 7);
	cout << "\x1B[94m" << char(254) << "   2. gra dla jednego gracza ";
	gotoxy(start.x + 30, start.y + 7);
	cout << "\x1B[94m" << char(254);

	gotoxy(start.x - 4, start.y + 8);
	cout << "\x1B[94m" << char(254) << "   3. gra z automatem ";
	gotoxy(start.x + 30, start.y + 8);
	cout << "\x1B[94m" << char(254);

	gotoxy(start.x - 4, start.y + 9);
	cout << "\x1B[94m" << char(254) << "   4. gra dla dwoch graczy ";
	gotoxy(start.x + 30, start.y + 9);
	cout << "\x1B[94m" << char(254);
}

void Menu::print_box(void)
{
	print_frame(28, 1, start.x, start.y + 12);
	gotoxy(start.x + 3, start.y + 13);
	cout << "\x1B[94m" << "twoj wybor: ";
}
void Menu::print_menu(void)
{
	print_SUDOKU();
	print_menuheader();
	print_lines();
	print_choices();
	print_box();
}

void Menu::print_graczeheader(void) // Funkcja wypisuj�ca graficznie r�owy napis "gracze". 
{
	gotoxy(start.x - 2, start.y);
	cout << "\x1B[95m" << "  __ _ _ __ __ _  ___ _______";
	gotoxy(start.x - 2, start.y + 1);
	cout << "\x1B[95m" << " / _` | '__/ _` |/ __|_  / _ " << char(92);
	gotoxy(start.x - 2, start.y + 2);
	cout << "\x1B[95m" << "| (_| | | | (_| | (__ / /  __/";
	gotoxy(start.x - 2, start.y + 3);
	cout << "\x1B[95m" << " " << char(92) << "__, |_| " << char(92) << "__,_| " << char(92) << "___/__ " << char(92) << "___|";
	gotoxy(start.x - 2, start.y + 4);
	cout << "\x1B[95m" << " |___/";
}

void Menu::print_graczemenu(int n) //Funkcja wy�wietlaj�ca ekran poboru nick�w graczy wraz z grafik� zawieraj�c� ramk� oraz napis sudoku.
{
	print_SUDOKU();
	print_graczeheader();
	print_lines();

	print_frame(28, 2, start.x, start.y + 7);
	gotoxy(start.x + 3, start.y + 8);
	cout << "\x1B[94m" << "podaj nick gracza 1: ";

	if (n == 2)
	{
		print_frame(28, 2, start.x, start.y + 11);
		gotoxy(start.x + 3, start.y + 12);
		cout << "\x1B[94m" << "podaj nick gracza 2: ";
	}
}