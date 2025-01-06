#pragma once
#include"wspol.hpp"
/**
* Klasa obiektów umo¿liwiaj¹ca obs³ugê graficzn¹ menu gry.
*/
class Menu
{
public:
	/**
	* Kontruktor automatyczny inicjalizuj¹cy wspó³rzêdne lewego górnego rogu napisu "MENU" w konsoli.
	*/
	Menu() { start.x = (Columns - 27) / 2; start.y = 11; }

	/**
	* Metoda wypisuj¹ca ca³y ekran menu przy u¿yciu pozosta³ych metod klasy.
	*/
	void print_menu(void);

	/**
	* Metoda wypisuj¹ca ca³y ekran poboru nicków graczy w zale¿noœci od liczby graczy bior¹cych udzia³ w rozgrywce.
	* 
	* \param[in] n - liczba graczy bior¹cych udzia³ w grze
	*/
	void print_graczemenu(int n);

private:

	/** Struktura przechowuj¹ca wspó³rzêdne lewego górnego rogu napisu "MENU" w konsoli */
	coordinates start;

	/**
	* Metoda wypisuj¹ca nag³ówek "MENU" w odpowednim miejscu w konsoli.
	*/
	void print_menuheader(void);

	/**
	* Metoda wypisuj¹ca dwie pionowe linie w odpowiednim miejscu w konsoli.
	*/
	void print_lines(void);

	/**
	* Metoda wypisuj¹ca menu wyboru w odpowiednim miejscu w konsoli.
	*/
	void print_choices(void);

	/**
	* Metoda wypisuj¹ca ramkê z miejscem na podanie wyboru opcji z menu.
	*/
	void print_box(void);

	/**
	* Metoda wypisuj¹ca nag³ówek "GRACZE" w odpowiednim miejscu w konsoli.
	*/
	void print_graczeheader(void);

};