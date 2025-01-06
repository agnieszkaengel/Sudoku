#pragma once
#include"wspol.hpp"
/**
* Klasa obiekt�w umo�liwiaj�ca obs�ug� graficzn� menu gry.
*/
class Menu
{
public:
	/**
	* Kontruktor automatyczny inicjalizuj�cy wsp�rz�dne lewego g�rnego rogu napisu "MENU" w konsoli.
	*/
	Menu() { start.x = (Columns - 27) / 2; start.y = 11; }

	/**
	* Metoda wypisuj�ca ca�y ekran menu przy u�yciu pozosta�ych metod klasy.
	*/
	void print_menu(void);

	/**
	* Metoda wypisuj�ca ca�y ekran poboru nick�w graczy w zale�no�ci od liczby graczy bior�cych udzia� w rozgrywce.
	* 
	* \param[in] n - liczba graczy bior�cych udzia� w grze
	*/
	void print_graczemenu(int n);

private:

	/** Struktura przechowuj�ca wsp�rz�dne lewego g�rnego rogu napisu "MENU" w konsoli */
	coordinates start;

	/**
	* Metoda wypisuj�ca nag��wek "MENU" w odpowednim miejscu w konsoli.
	*/
	void print_menuheader(void);

	/**
	* Metoda wypisuj�ca dwie pionowe linie w odpowiednim miejscu w konsoli.
	*/
	void print_lines(void);

	/**
	* Metoda wypisuj�ca menu wyboru w odpowiednim miejscu w konsoli.
	*/
	void print_choices(void);

	/**
	* Metoda wypisuj�ca ramk� z miejscem na podanie wyboru opcji z menu.
	*/
	void print_box(void);

	/**
	* Metoda wypisuj�ca nag��wek "GRACZE" w odpowiednim miejscu w konsoli.
	*/
	void print_graczeheader(void);

};