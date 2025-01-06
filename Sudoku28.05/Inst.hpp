#pragma once
#include"letters.hpp"

/**
* Klasa obiektów umo¿liwiaj¹ca obs³uge graficzn¹ instrukcji gry.
*/
class Inst
{
public:
	/** 
	* Kontruktor automatyczny inicjalizuj¹cy wspó³rzêdne lewego górnego rogu napisu "INSTRUKCJA" w konsoli.
	*/
	Inst() { start.x = (Columns - 46) / 2; start.y = 9; } 

	/**
	* Metoda wypisuj¹ca ca³y ekran intrukcji przy u¿yciu pozosta³ych metod klasy.
	*/
	void print_inst(void);

private:
	/** Struktura przechowuj¹ca wspó³rzêdne lewego górnego rogu napisu "INSTRUKCJA" w konsoli */
	coordinates start;

	/**
	* Metoda wypisuj¹ca graficznie napis "INSTRUKCJA" w odpowiednim miejscu w konsoli.
	*/
	void print_instheader(void);

	/**
	* Metoda wypisuj¹ca dwie pionowe linie ograniczaj¹ce treœæ instrukcji w odpowiednim miejscu w konsoli.
	*/
	void print_lines(void);

	/**
	* Metoda wypisuj¹ca tekst instrukcji w odpowiednim miejscu w konsoli.
	*/
	void print_text(void);

	/**
	* Metoda wypisuj¹ca ramkê z miejscem na wpisanie litery powoduj¹cej powrót do menu gry.
	*/
	void print_box(void);

};