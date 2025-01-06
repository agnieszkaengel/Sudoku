#pragma once
#include"letters.hpp"

/**
* Klasa obiekt�w umo�liwiaj�ca obs�uge graficzn� instrukcji gry.
*/
class Inst
{
public:
	/** 
	* Kontruktor automatyczny inicjalizuj�cy wsp�rz�dne lewego g�rnego rogu napisu "INSTRUKCJA" w konsoli.
	*/
	Inst() { start.x = (Columns - 46) / 2; start.y = 9; } 

	/**
	* Metoda wypisuj�ca ca�y ekran intrukcji przy u�yciu pozosta�ych metod klasy.
	*/
	void print_inst(void);

private:
	/** Struktura przechowuj�ca wsp�rz�dne lewego g�rnego rogu napisu "INSTRUKCJA" w konsoli */
	coordinates start;

	/**
	* Metoda wypisuj�ca graficznie napis "INSTRUKCJA" w odpowiednim miejscu w konsoli.
	*/
	void print_instheader(void);

	/**
	* Metoda wypisuj�ca dwie pionowe linie ograniczaj�ce tre�� instrukcji w odpowiednim miejscu w konsoli.
	*/
	void print_lines(void);

	/**
	* Metoda wypisuj�ca tekst instrukcji w odpowiednim miejscu w konsoli.
	*/
	void print_text(void);

	/**
	* Metoda wypisuj�ca ramk� z miejscem na wpisanie litery powoduj�cej powr�t do menu gry.
	*/
	void print_box(void);

};