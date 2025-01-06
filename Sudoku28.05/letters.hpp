#pragma once
#include "wspol.hpp"

/**
* Sta�a okre�laj�ca wysoko�� litery w napisie "SUDOKU".
*/
#define LHeight 5
/**
* Sta�a okre�laj�ca szeroko�� litery w napisie "SUDOKU".
*/
#define LWidth 6 
/**
* Sta�a okre�laj�ca liczb� wierszy w ekranie rozgrywki w konsoli.
*/
#define Rows 41 
/**
* Sta�a okre�laj�ca liczb� kolumn w ekranie rozgrywki w konsoli.
*/
#define Columns 93 
/**
* Sta�a okre�laj�ca d�ugo�� ca�ego napisu "SUDOKU".
*/
#define Stringlen 41 

/**
* Funkcja uzupe�niaj�ca pola tablicy dwuwymiarowej warto�ciami typu enum : true lub false, tworz�c kszta�t litery S.
* 
* param[in] S - tablica dwuwymiarowa do uzupe�nienia
*/
void create_S(bool S[LHeight][LWidth]);

/**
* Funkcja uzupe�niaj�ca pola tablicy dwuwymiarowej warto�ciami typu enum : true lub false, tworz�c kszta�t litery S.
*
* \param[in] U - tablica dwuwymiarowa do uzupe�nienia
*/
void create_U(bool U[LHeight][LWidth]);

/**
* Funkcja uzupe�niaj�ca pola tablicy dwuwymiarowej warto�ciami typu enum : true lub false, tworz�c kszta�t litery S.
*
* \param[in] D - tablica dwuwymiarowa do uzupe�nienia
*/
void create_D(bool D[LHeight][LWidth]);

/**
* Funkcja uzupe�niaj�ca pola tablicy dwuwymiarowej warto�ciami typu enum : true lub false, tworz�c kszta�t litery S.
*
* \param[in] O - tablica dwuwymiarowa do uzupe�nienia
*/
void create_O(bool O[LHeight][LWidth]);

/**
* Funkcja uzupe�niaj�ca pola tablicy dwuwymiarowej warto�ciami typu enum : true lub false, tworz�c kszta�t litery S.
*
* \param[in] K - tablica dwuwymiarowa do uzupe�nienia
*/
void create_K(bool K[LHeight][LWidth]);

/**
* Funkcja wypisuj�ca (przy u�yciu odpowiedniego znaku i koloru w polach wype�nionych warto�ci� false) tablic� przedstawiaj�c� liter� z uwzgl�dnieniem
* jej po�o�enia w konsoli.
*
* \param[in] letter - tablica przedstawiajaca liter�
* \param[in] position - numer kolumny konsoli, w kt�rej rozpocznie si� wypisywanie tablicy
*/
void print_letter(bool letter[LHeight][LWidth], int position);

/**
* Funkcja wypisuj�ca nag��wek "SUDOKU" za pomoc� tablic liter oraz obramowanie ekranu rozgrywki, w odpowiednim miejscu w konsoli.
*/
void print_SUDOKU(void);