#pragma once
#include "wspol.hpp"

/**
* Sta³a okreœlaj¹ca wysokoœæ litery w napisie "SUDOKU".
*/
#define LHeight 5
/**
* Sta³a okreœlaj¹ca szerokoœæ litery w napisie "SUDOKU".
*/
#define LWidth 6 
/**
* Sta³a okreœlaj¹ca liczbê wierszy w ekranie rozgrywki w konsoli.
*/
#define Rows 41 
/**
* Sta³a okreœlaj¹ca liczbê kolumn w ekranie rozgrywki w konsoli.
*/
#define Columns 93 
/**
* Sta³a okreœlaj¹ca d³ugoœæ ca³ego napisu "SUDOKU".
*/
#define Stringlen 41 

/**
* Funkcja uzupe³niaj¹ca pola tablicy dwuwymiarowej wartoœciami typu enum : true lub false, tworz¹c kszta³t litery S.
* 
* param[in] S - tablica dwuwymiarowa do uzupe³nienia
*/
void create_S(bool S[LHeight][LWidth]);

/**
* Funkcja uzupe³niaj¹ca pola tablicy dwuwymiarowej wartoœciami typu enum : true lub false, tworz¹c kszta³t litery S.
*
* \param[in] U - tablica dwuwymiarowa do uzupe³nienia
*/
void create_U(bool U[LHeight][LWidth]);

/**
* Funkcja uzupe³niaj¹ca pola tablicy dwuwymiarowej wartoœciami typu enum : true lub false, tworz¹c kszta³t litery S.
*
* \param[in] D - tablica dwuwymiarowa do uzupe³nienia
*/
void create_D(bool D[LHeight][LWidth]);

/**
* Funkcja uzupe³niaj¹ca pola tablicy dwuwymiarowej wartoœciami typu enum : true lub false, tworz¹c kszta³t litery S.
*
* \param[in] O - tablica dwuwymiarowa do uzupe³nienia
*/
void create_O(bool O[LHeight][LWidth]);

/**
* Funkcja uzupe³niaj¹ca pola tablicy dwuwymiarowej wartoœciami typu enum : true lub false, tworz¹c kszta³t litery S.
*
* \param[in] K - tablica dwuwymiarowa do uzupe³nienia
*/
void create_K(bool K[LHeight][LWidth]);

/**
* Funkcja wypisuj¹ca (przy u¿yciu odpowiedniego znaku i koloru w polach wype³nionych wartoœci¹ false) tablicê przedstawiaj¹c¹ literê z uwzglêdnieniem
* jej po³o¿enia w konsoli.
*
* \param[in] letter - tablica przedstawiajaca literê
* \param[in] position - numer kolumny konsoli, w której rozpocznie siê wypisywanie tablicy
*/
void print_letter(bool letter[LHeight][LWidth], int position);

/**
* Funkcja wypisuj¹ca nag³ówek "SUDOKU" za pomoc¹ tablic liter oraz obramowanie ekranu rozgrywki, w odpowiednim miejscu w konsoli.
*/
void print_SUDOKU(void);