#pragma once
#include "Board.hpp"
#include"Inst.hpp"
#include"Menu.hpp"
#include<iostream>
#include <string>

using namespace std;

/**
* Klasa umo��iwiaj�ca obs�ug� gracza podczas rozgrywki.
*/
class Player {
public:
    /**
    * Kontruktor z argumentami inicjalizuj�cy nick gracza oraz wska�nik do obiektu klasy Board na podane warto�ci, a tak�e liczb� punkt�w automatycznie na 0.
    * 
    * \param[in] nick - podany nick gracza
    * \param[in] *b - wska�nik do obiektu klasy Board 
    */
    Player(string nick, Board* b) : score{ 0 }, nick{ nick }, board{ b } {}

    /**
    * Metoda wirtualna pobieraj�ca ruch gracza.
    * 
    * \param[out] &x - adres, pod kt�ry zostanie wpisana podana wsp�rz�dna wiersza planszy sudoku.
    * \param[out] &y - adres, pod kt�ry zostanie wpisana podana wsp�rz�dna kolumny planszy sudoku.
    * \param[out] &v - adres, pod kt�ry zostanie warto�� do umieszczenia na polu (*x,*y) planszy sudoku.
    */
    virtual void getMove (char& x, int& y, int& v) = 0;

    /**
    * Getter nicku gracza.
    * 
    * \return nick - nick gracza
    */
    string get_nick() const { return nick; }

    /**
    * Metoda modyfikuj�ca liczb� punkt�w gracza o podan� warto��.
    * 
    * \param[in] v - warto��, o kt�r� ma si� zmieni� liczba punkt�w gracza
    */
    void modify_score(int v) { score += v; }

    /**
    * Getter liczby punkt�w gracza.
    * 
    * \return score - liczba punkt�w gracza
    */
    int get_score() const { return score; }
private:
    /**
    * Pole przechowuj�ce liczb� punkt�w gracza.
    */
    int score;

    /**
    * Pole przechowuj�ce nick gracza.
    */
    string nick;
protected:
    /**
    * Wska�nik do obiektu klasy Board.
    */
    Board* board = NULL;

};

/**
* Klasa dziedzicz�ca po klasie Player umo�liwiaj�ca obs�ug� gracza ludzkiego podczas rozgrywki.
*/
class HumanPlayer : public Player {
public:
    /**
  * Kontruktor z argumentami inicjalizuj�cy nick gracza oraz wska�nik do obiektu klasy Board na podane warto�ci, a tak�e liczb� punkt�w automatycznie na 0.
  *
  * \param[in] nick - podany nick gracza
  * \param[in] *b - wska�nik do obiektu klasy Board
  */
    HumanPlayer(string nick, Board* b) :Player(nick, b) {};
    /**
    * Metoda wirtualna pobieraj�ca ruch od gracza ludzkiego.
    *
    * \param[out] &x - adres, pod kt�ry zostanie wpisana podana wsp�rz�dna wiersza planszy sudoku.
    * \param[out] &y - adres, pod kt�ry zostanie wpisana podana wsp�rz�dna kolumny planszy sudoku.
    * \param[out] &v - adres, pod kt�ry zostanie warto�� do umieszczenia na polu (*x,*y) planszy sudoku.
    */
    void getMove(char& x, int& y, int& v);
};

/**
* Klasa dziedzicz�ca po klasie Player, umo�liwiaj�ca obs�ug� gracza automatycznego podczas rozgrywki.
*/
class AutoPlayer : public Player {
public:
    /**
  * Kontruktor inicjalizuj�cy nick gracza na "gracz autom.", liczb� punkt�w na 0 oraz wska�nik do obiektu klasy Board na podan� warto��. Inicjalizuje tak�e wszystkie pola tablicy tab na true.
  *
  * \param[in] nick - podany nick gracza
  * \param[in] *b - wska�nik do obiektu klasy Board
  */
    AutoPlayer(Board* b) : Player("gracz autom.", b) {
        for (int i = 0; i < P; i++)
            for (int j = 0; j < P; j++)
                for (int k = 0; k < P; k++)
                    tab[i][j][k] = true;
    }
    /**
    * Metoda wirtualna generuj�ca ruch gracza automatycznego za pomoc� algorytmu wype�niaj�cego tablic� tr�jwymiarow� warto�ciami informuj�cymi o mo�liwo�ci
    * postawienia danej warto�ci na danym polu, przy wykorzystaniu ju� wype�nionych p�l.
    *
    * \param[out] &x - adres, pod kt�ry zostanie wpisana podana wsp�rz�dna wiersza planszy sudoku.
    * \param[out] &y - adres, pod kt�ry zostanie wpisana podana wsp�rz�dna kolumny planszy sudoku.
    * \param[out] &v - adres, pod kt�ry zostanie warto�� do umieszczenia na polu (*x,*y) planszy sudoku.
    */
    void getMove(char& x, int& y, int& v);

private:
    /**
    * Tablica tr�jwymiarowa przechowuj�ca informacje na temat mo�liwych do wstawienia na danym polu planszy cyfr.
    */
    bool tab[P][P][P];
};



