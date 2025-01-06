#pragma once
#include<string>
#include"letters.hpp"
#include"wspol.hpp"
using namespace std;

/**
* Sta�a okre�laj�ca wysoko�� planszy sudoku.
*/
#define BHeight 19

/**
* Sta�a okre�laj�ca szeroko�� planszy sudoku.
*/
#define BWidth 37

/**
* Sta�a okre�laj�ca liczb� wierszy oraz kolumn w tablicy przechowuj�cej plansz� sudoku.
*/
#define P 9


/**
* Klasa obiekt�w umo�liwiaj�ca obs�ug� planszy sudoku.
*/
class Board
{
public:
	/**
	* Konstruktor automatyczny inicjalizuj�cy wsp�rz�dne lewego g�rnego rogu planszy na warto�ci zale�ne od wymiar�w planszy oraz konsoli
	oraz wszystkie pola planszy sudoku na 0 .
	*/
	Board() {
		start.x = (Columns - BWidth) / 2; start.y = 10;
		for (int i = 0; i < P; i++)
			for (int j = 0; j < P; j++)
				board[i][j] = 0;
	}
	
	/** Struktura przechowuj�ca wsp�rz�dne lewego g�rnego rogu planszy w konsoli */
	coordinates start;

	/**
	* Metoda losuj�ca numer planszy sudoku, kt�ra zostanie wy�wietlona.
	* 
	* \return nazwa pliku, z kt�rego wczytywana b�dzie plansza
	*/
	string draw_board(void);

	/**
	* Metoda wczytuj�ca w plansz� sudoku u�o�enie cyfr oraz liczb� punkt�w graczy z danego pliku.
	* 
	* \param[in] filename - nazwa pliku, z kt�rego wczytywana jest plansza
	* \param[out] &s1 - adres, pod kt�ry ma zosta� wpisana liczba punkt�w pierwszego gracza
	* \param[out] &s2 - adres, pod kt�ry ma zosta� wpisana liczba punkt�w drugiego gracza
	*/
	void read_board(string filename, int &s1, int&s2);

	/**
	* Metoda przygotowuj�ca graficznie ekran pod rozgrywk� dla dw�ch graczy.
	*/
	void print_board_2players(void);

	/**
	* Metoda przygotowuj�ca graficznie ekran pod rozgrywk� dla jednego gracza.
	*/
	void print_board_1player(void);

	/**
	* Metoda znajduj�ca warto�� danego pola planszy.
	* 
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (0-8)
	* 
	* \return liczba stoj�ca na polu o wsp�rz�dnych (x,y)
	*/
	int get_value(int x, int y);

	/**
	* Metoda sprawdzaj�ca czy plansza sudoku zosta�a ju� rozwi�zana.
	* 
	* \return true, je�li plansza zosta�a rozwi�zana lub false, je�li nie zosta�a rozwi�zana
	*/
	bool isSolved(void);

	/**
	* Metoda wstawiaj�ca podan� warto�� w pole o wsp�rz�dnych (x,y-1).
	*
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (1-9)
	* \param[in] v - podana warto��
	*/
	void put(int x, int y, int v);
	
	/**
	* Metoda konwertuj�ca wsp�rz�dn� planszy, w postaci litery, na numer wiersza, kt�ry jest przez ni� reprezentowany w tablicy zawieraj�cej plansz�.
	* 
	* \param[in] x - litera do przekonwertowania
	* 
	* \return numer wiersza
	*/
	int convert(char x);

	/**
	* Metoda sprawdza czy wstawiana na dane pole planszy cyfra jest poprawnym rozwi�zaniem.
	* 
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (1-9)
	* \param[in] v - podana warto��
	* 
	* \return true, je�li rozwi�zanie jest poprawne lub false, je�li nie jest poprawne.
	*/
	bool isCorrect(int x, int y, int v);

	/**
	* Metoda sprawdza czy wybrane przez u�ytkownika pole (do wstawienia cyfry) jest puste.
	* 
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (1-9)
	* 
	* \return true, je�li pole jest puste lub false, je�li pole nie jest puste.
	*/
	bool isFree(int x, int y); 

private:
	/**<Pole przechowuj�ce liczb� p�l, kt�re nale�y uzupe�ni� w planszy podczas gry. */
	int emptycount = 0;

	/**<Tablica 9x9 przechowuj�ca plansz� sudoku */
	int board[P][P]; 


	/**
	* Metoda wypisuj�ca napis sudoku, wype�nion� plansz� oraz ramk� z informacj� co nale�y zrobi�, aby zako�czy� gr�.
	*/
	void print_filledboard(void);

	/**
	* Metoda wypisuj�ca g�rn� cz�� ramki planszy sudoku uwzgl�dniaj�c jej po�o�enie w konsoli.
	*/
	void print_top(void);

	/**
	* Metoda wypisuj�ca �rodkow� cz�� ramki planszy sudoku z uwzgl�dnieniem jej po�o�enia w konsoli oraz pogrubionych pionowych linii wyznaczaj�cych
	* kwadraty 3x3 w planszy.
	*/
	void print_middle(void);

	/**
	* Metoda wypisuj�ca �rodkow� cz�� ramki planszy sudoku z uwzgl�dnieniem jej po�o�enia w konsoli oraz pogrubionych pionowych i poziomych linii
	* wyznaczaj�cych kwadraty 3x3 w planszy.
	*/
	void print_middlebold(void);

	/**
	* Metoda wypisuj�ca doln� cz�� ramki planszy sudoku uwzgl�dniaj�c jej po�o�enie w konsoli.
	*/
	void print_bottom(void);

	/**
	* Metoda wypisuj�ca oznaczenie wierszy oraz kolumn planszy z uwzgl�dnieniem jej po�o�enia w konsoli: poziomo cyfry (od 1 do 9) nad ni� oraz pionowo litery
	* od (a do i) po jej lewej stronie.
	*/
	void print_coordinates(void);

	/**
	* Metoda wypisuj�ca pionowe linie z miejscem na nick gracza oraz zdobyte przez niego punkty w zale�no�ci od ilo�ci graczy.
	*
	* \param[in] n - ilo�� graczy
	*/
	void print_lines(int n);

	/**
	* Metoda wypisuj�ca prostok�t z miejscem na podanie przez u�ytkownika wsp�rz�dnych wybranego pola oraz warto�ci, kt�r� chce w nie wpisa�.
	*/
	void print_box(void);
};