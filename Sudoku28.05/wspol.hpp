#pragma once
/**
* Struktura umo�liwiaj�ca przechowywanie warto�ci wsp�rz�dnych.
*/
struct coordinates
{
	/**
	* x - wsp�rz�dna pozioma 
	*/
	int x;
	/**
	* y - wsp�rz�dna pionowa
	*/
	int y;
};

/**
* Funkcja przenosz�ca kursor w wybrane miejsce w konsoli.
* 
* \param[in] x - numer kolumny konsoli
* \param[in]  y - numer wiersza konsoli
*/
void gotoxy(int x, int y);
