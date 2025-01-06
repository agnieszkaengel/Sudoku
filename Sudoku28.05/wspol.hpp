#pragma once
/**
* Struktura umo¿liwiaj¹ca przechowywanie wartoœci wspó³rzêdnych.
*/
struct coordinates
{
	/**
	* x - wspó³rzêdna pozioma 
	*/
	int x;
	/**
	* y - wspó³rzêdna pionowa
	*/
	int y;
};

/**
* Funkcja przenosz¹ca kursor w wybrane miejsce w konsoli.
* 
* \param[in] x - numer kolumny konsoli
* \param[in]  y - numer wiersza konsoli
*/
void gotoxy(int x, int y);
