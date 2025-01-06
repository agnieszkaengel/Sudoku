#pragma once
#include<iostream>
#include<string>
#include "Board.hpp"
#include "Player.hpp"

/**
* Funkcja sprawdzaj�ca czy plik o podanej nazwie jest pusty.
* 
* \param[in] filename - nazwa pliku do sprawdzenia
* \return true je�li plik jest pusty lub false je�li nie jest pusty
*/
bool check_ifempty(string filename);

/**
* Funkcja tworz�ca nazw� pliku sk�adaj�c� si� z nick�w graczy u�o�onych alfabetycznie.
*
* \param[in] nick1 - nick pierwszego gracza
* \param[in] nick2 - nick drugiego gracza
*/
string create_filename(string nick1, string nick2);

/**
* Funkcja sprawdzaj�ca czy plik o podanej nazwie istnieje.
*
* \param[in] filename - nazwa pliku do sprawdzenia
* \return true je�li plik istnieje lub false je�li nie istnieje
*/
bool check_ifexists(string filename);

/**
* Funkcja wpisuje w plik aktualny stan wype�nienia planszy sudoku oraz aktualn� liczb� punkt�w graczy (wed�ug kolejno�ci alfabetycznej ich nick�w).
* 
* \param[in] filename - nazwa pliku do zapisu danych
* \param[in] board - obiekt klasy Board obs�uguj�cy plansz� sudoku
* \param[in] player1 - obiekt klasy Player obs�uguj�cy gracza 1
* \param[in] player2 - obiekt klasy Player obs�uguj�cy gracza 2
*/
void write_infile(string filename, Board board, Player* player1, Player* player2);



/**
* Funkcja daje u�ytkownikowi mo�liwo�� wyboru kontynuacji poprzedniej gry, je�eli istnieje niepusty plik z jej zapisem.
*
* \param[in] filename - nazwa pliku do sprawdzenia
*/
bool continue_choice(string filename);
	
