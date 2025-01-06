#pragma once

/**
* Funkcja pobiera od u¿ytkownika znak/znaki, a nastêpnie sprawdza, czy jest to liczba ca³kowita z przedzia³u [a,b]. Jeœli podany znak jest niepoprawny, informuje
* o b³êdzie i pobiera znak ponownie.
*
* \param [in] a - dolna granica przedzia³u, w którym ma siê mieœciæ podana przez u¿ytkownika liczba
* \param [in] b - górna granica przedzia³u, w którym ma siê mieœciæ podana przez u¿ytkownika liczba
* \param [in] x - numer kolumny konsoli, w której ma siê zacz¹æ wypisywany komunikat
* \param [in] y - numer wiersza konsoli, w którym ma siê zacz¹æ wypisywany komunikat
* \return Zwraca podan¹ przez u¿ytkownika liczbê.
*/
int check_intvalue(int a, int b, int x, int y);

/**
* Funkcja pobiera od u¿ytkownika znak/znaki, a nastêpnie sprawdza, czy jest to litera "M". Jeœli podany znak/znaki s¹ niepoprawne, informuje
* o b³êdzie i pobiera znak ponownie.
*
* \param [in] x - numer kolumny konsoli, w której ma siê zacz¹æ wypisywany komunikat
* \param [in] y - numer wiersza konsoli, w którym ma siê zacz¹æ wypisywany komunikat
* \return Zwraca podan¹ przez u¿ytkownika literê.
*/
char check_charvalue(int x, int y);

/**
* Funkcja pobiera od u¿ytkownika znak/znaki, a nastêpnie sprawdza, czy jest to kombinacja znakow postaci: litera liczba ca³kowita (bez spacji pomiêdzy znakami)
* oraz czy podana litera jest z przedzia³u [a,i], a cyfra z przedzia³u [1,9]. Jeœli podana kombinacja znaków jest niepoprawna, informuje o b³êdzie i pobiera znaki ponownie.
*
* \param[out] &l - adres, pod który ma zostaæ wpisana poprawnie podana litera
* \param[out] &c - adres, pod który ma zostaæ wpisana poprawnie podana cyfra
* \param [in] x - numer kolumny konsoli, w której ma siê zacz¹æ wypisywany komunikat
* \param [in] y - numer wiersza konsoli, w którym ma siê zacz¹æ wypisywany komunikat
*/
void check_charintvalue(char& l, int& c, int x, int y);