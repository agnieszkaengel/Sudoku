#pragma once
#include<iostream>
#include<string>
#include "Board.hpp"
#include "Player.hpp"

/**
* Funkcja sprawdzaj¹ca czy plik o podanej nazwie jest pusty.
* 
* \param[in] filename - nazwa pliku do sprawdzenia
* \return true jeœli plik jest pusty lub false jeœli nie jest pusty
*/
bool check_ifempty(string filename);

/**
* Funkcja tworz¹ca nazwê pliku sk³adaj¹c¹ siê z nicków graczy u³o¿onych alfabetycznie.
*
* \param[in] nick1 - nick pierwszego gracza
* \param[in] nick2 - nick drugiego gracza
*/
string create_filename(string nick1, string nick2);

/**
* Funkcja sprawdzaj¹ca czy plik o podanej nazwie istnieje.
*
* \param[in] filename - nazwa pliku do sprawdzenia
* \return true jeœli plik istnieje lub false jeœli nie istnieje
*/
bool check_ifexists(string filename);

/**
* Funkcja wpisuje w plik aktualny stan wype³nienia planszy sudoku oraz aktualn¹ liczbê punktów graczy (wed³ug kolejnoœci alfabetycznej ich nicków).
* 
* \param[in] filename - nazwa pliku do zapisu danych
* \param[in] board - obiekt klasy Board obs³uguj¹cy planszê sudoku
* \param[in] player1 - obiekt klasy Player obs³uguj¹cy gracza 1
* \param[in] player2 - obiekt klasy Player obs³uguj¹cy gracza 2
*/
void write_infile(string filename, Board board, Player* player1, Player* player2);



/**
* Funkcja daje u¿ytkownikowi mo¿liwoœæ wyboru kontynuacji poprzedniej gry, je¿eli istnieje niepusty plik z jej zapisem.
*
* \param[in] filename - nazwa pliku do sprawdzenia
*/
bool continue_choice(string filename);
	
