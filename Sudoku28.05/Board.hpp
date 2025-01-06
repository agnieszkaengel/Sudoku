#pragma once
#include<string>
#include"letters.hpp"
#include"wspol.hpp"
using namespace std;

/**
* Sta³a okreœlaj¹ca wysokoœæ planszy sudoku.
*/
#define BHeight 19

/**
* Sta³a okreœlaj¹ca szerokoœæ planszy sudoku.
*/
#define BWidth 37

/**
* Sta³a okreœlaj¹ca liczbê wierszy oraz kolumn w tablicy przechowuj¹cej planszê sudoku.
*/
#define P 9


/**
* Klasa obiektów umo¿liwiaj¹ca obs³ugê planszy sudoku.
*/
class Board
{
public:
	/**
	* Konstruktor automatyczny inicjalizuj¹cy wspó³rzêdne lewego górnego rogu planszy na wartoœci zale¿ne od wymiarów planszy oraz konsoli
	oraz wszystkie pola planszy sudoku na 0 .
	*/
	Board() {
		start.x = (Columns - BWidth) / 2; start.y = 10;
		for (int i = 0; i < P; i++)
			for (int j = 0; j < P; j++)
				board[i][j] = 0;
	}
	
	/** Struktura przechowuj¹ca wspó³rzêdne lewego górnego rogu planszy w konsoli */
	coordinates start;

	/**
	* Metoda losuj¹ca numer planszy sudoku, która zostanie wyœwietlona.
	* 
	* \return nazwa pliku, z którego wczytywana bêdzie plansza
	*/
	string draw_board(void);

	/**
	* Metoda wczytuj¹ca w planszê sudoku u³o¿enie cyfr oraz liczbê punktów graczy z danego pliku.
	* 
	* \param[in] filename - nazwa pliku, z którego wczytywana jest plansza
	* \param[out] &s1 - adres, pod który ma zostaæ wpisana liczba punktów pierwszego gracza
	* \param[out] &s2 - adres, pod który ma zostaæ wpisana liczba punktów drugiego gracza
	*/
	void read_board(string filename, int &s1, int&s2);

	/**
	* Metoda przygotowuj¹ca graficznie ekran pod rozgrywkê dla dwóch graczy.
	*/
	void print_board_2players(void);

	/**
	* Metoda przygotowuj¹ca graficznie ekran pod rozgrywkê dla jednego gracza.
	*/
	void print_board_1player(void);

	/**
	* Metoda znajduj¹ca wartoœæ danego pola planszy.
	* 
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (0-8)
	* 
	* \return liczba stoj¹ca na polu o wspó³rzêdnych (x,y)
	*/
	int get_value(int x, int y);

	/**
	* Metoda sprawdzaj¹ca czy plansza sudoku zosta³a ju¿ rozwi¹zana.
	* 
	* \return true, jeœli plansza zosta³a rozwi¹zana lub false, jeœli nie zosta³a rozwi¹zana
	*/
	bool isSolved(void);

	/**
	* Metoda wstawiaj¹ca podan¹ wartoœæ w pole o wspó³rzêdnych (x,y-1).
	*
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (1-9)
	* \param[in] v - podana wartoœæ
	*/
	void put(int x, int y, int v);
	
	/**
	* Metoda konwertuj¹ca wspó³rzêdn¹ planszy, w postaci litery, na numer wiersza, który jest przez ni¹ reprezentowany w tablicy zawieraj¹cej planszê.
	* 
	* \param[in] x - litera do przekonwertowania
	* 
	* \return numer wiersza
	*/
	int convert(char x);

	/**
	* Metoda sprawdza czy wstawiana na dane pole planszy cyfra jest poprawnym rozwi¹zaniem.
	* 
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (1-9)
	* \param[in] v - podana wartoœæ
	* 
	* \return true, jeœli rozwi¹zanie jest poprawne lub false, jeœli nie jest poprawne.
	*/
	bool isCorrect(int x, int y, int v);

	/**
	* Metoda sprawdza czy wybrane przez u¿ytkownika pole (do wstawienia cyfry) jest puste.
	* 
	* \param[in] x - numer wiersza planszy (0-8)
	* \param[in] y - numer kolumny planszy (1-9)
	* 
	* \return true, jeœli pole jest puste lub false, jeœli pole nie jest puste.
	*/
	bool isFree(int x, int y); 

private:
	/**<Pole przechowuj¹ce liczbê pól, które nale¿y uzupe³niæ w planszy podczas gry. */
	int emptycount = 0;

	/**<Tablica 9x9 przechowuj¹ca planszê sudoku */
	int board[P][P]; 


	/**
	* Metoda wypisuj¹ca napis sudoku, wype³nion¹ planszê oraz ramkê z informacj¹ co nale¿y zrobiæ, aby zakoñczyæ grê.
	*/
	void print_filledboard(void);

	/**
	* Metoda wypisuj¹ca górn¹ czêœæ ramki planszy sudoku uwzglêdniaj¹c jej po³o¿enie w konsoli.
	*/
	void print_top(void);

	/**
	* Metoda wypisuj¹ca œrodkow¹ czêœæ ramki planszy sudoku z uwzglêdnieniem jej po³o¿enia w konsoli oraz pogrubionych pionowych linii wyznaczaj¹cych
	* kwadraty 3x3 w planszy.
	*/
	void print_middle(void);

	/**
	* Metoda wypisuj¹ca œrodkow¹ czêœæ ramki planszy sudoku z uwzglêdnieniem jej po³o¿enia w konsoli oraz pogrubionych pionowych i poziomych linii
	* wyznaczaj¹cych kwadraty 3x3 w planszy.
	*/
	void print_middlebold(void);

	/**
	* Metoda wypisuj¹ca doln¹ czêœæ ramki planszy sudoku uwzglêdniaj¹c jej po³o¿enie w konsoli.
	*/
	void print_bottom(void);

	/**
	* Metoda wypisuj¹ca oznaczenie wierszy oraz kolumn planszy z uwzglêdnieniem jej po³o¿enia w konsoli: poziomo cyfry (od 1 do 9) nad ni¹ oraz pionowo litery
	* od (a do i) po jej lewej stronie.
	*/
	void print_coordinates(void);

	/**
	* Metoda wypisuj¹ca pionowe linie z miejscem na nick gracza oraz zdobyte przez niego punkty w zale¿noœci od iloœci graczy.
	*
	* \param[in] n - iloœæ graczy
	*/
	void print_lines(int n);

	/**
	* Metoda wypisuj¹ca prostok¹t z miejscem na podanie przez u¿ytkownika wspó³rzêdnych wybranego pola oraz wartoœci, któr¹ chce w nie wpisaæ.
	*/
	void print_box(void);
};