#pragma once

/**
* Funkcja pobiera od u�ytkownika znak/znaki, a nast�pnie sprawdza, czy jest to liczba ca�kowita z przedzia�u [a,b]. Je�li podany znak jest niepoprawny, informuje
* o b��dzie i pobiera znak ponownie.
*
* \param [in] a - dolna granica przedzia�u, w kt�rym ma si� mie�ci� podana przez u�ytkownika liczba
* \param [in] b - g�rna granica przedzia�u, w kt�rym ma si� mie�ci� podana przez u�ytkownika liczba
* \param [in] x - numer kolumny konsoli, w kt�rej ma si� zacz�� wypisywany komunikat
* \param [in] y - numer wiersza konsoli, w kt�rym ma si� zacz�� wypisywany komunikat
* \return Zwraca podan� przez u�ytkownika liczb�.
*/
int check_intvalue(int a, int b, int x, int y);

/**
* Funkcja pobiera od u�ytkownika znak/znaki, a nast�pnie sprawdza, czy jest to litera "M". Je�li podany znak/znaki s� niepoprawne, informuje
* o b��dzie i pobiera znak ponownie.
*
* \param [in] x - numer kolumny konsoli, w kt�rej ma si� zacz�� wypisywany komunikat
* \param [in] y - numer wiersza konsoli, w kt�rym ma si� zacz�� wypisywany komunikat
* \return Zwraca podan� przez u�ytkownika liter�.
*/
char check_charvalue(int x, int y);

/**
* Funkcja pobiera od u�ytkownika znak/znaki, a nast�pnie sprawdza, czy jest to kombinacja znakow postaci: litera liczba ca�kowita (bez spacji pomi�dzy znakami)
* oraz czy podana litera jest z przedzia�u [a,i], a cyfra z przedzia�u [1,9]. Je�li podana kombinacja znak�w jest niepoprawna, informuje o b��dzie i pobiera znaki ponownie.
*
* \param[out] &l - adres, pod kt�ry ma zosta� wpisana poprawnie podana litera
* \param[out] &c - adres, pod kt�ry ma zosta� wpisana poprawnie podana cyfra
* \param [in] x - numer kolumny konsoli, w kt�rej ma si� zacz�� wypisywany komunikat
* \param [in] y - numer wiersza konsoli, w kt�rym ma si� zacz�� wypisywany komunikat
*/
void check_charintvalue(char& l, int& c, int x, int y);