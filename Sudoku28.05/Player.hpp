#pragma once
#include "Board.hpp"
#include"Inst.hpp"
#include"Menu.hpp"
#include<iostream>
#include <string>

using namespace std;

/**
* Klasa umo¿³iwiaj¹ca obs³ugê gracza podczas rozgrywki.
*/
class Player {
public:
    /**
    * Kontruktor z argumentami inicjalizuj¹cy nick gracza oraz wskaŸnik do obiektu klasy Board na podane wartoœci, a tak¿e liczbê punktów automatycznie na 0.
    * 
    * \param[in] nick - podany nick gracza
    * \param[in] *b - wskaŸnik do obiektu klasy Board 
    */
    Player(string nick, Board* b) : score{ 0 }, nick{ nick }, board{ b } {}

    /**
    * Metoda wirtualna pobieraj¹ca ruch gracza.
    * 
    * \param[out] &x - adres, pod który zostanie wpisana podana wspó³rzêdna wiersza planszy sudoku.
    * \param[out] &y - adres, pod który zostanie wpisana podana wspó³rzêdna kolumny planszy sudoku.
    * \param[out] &v - adres, pod który zostanie wartoœæ do umieszczenia na polu (*x,*y) planszy sudoku.
    */
    virtual void getMove (char& x, int& y, int& v) = 0;

    /**
    * Getter nicku gracza.
    * 
    * \return nick - nick gracza
    */
    string get_nick() const { return nick; }

    /**
    * Metoda modyfikuj¹ca liczbê punktów gracza o podan¹ wartoœæ.
    * 
    * \param[in] v - wartoœæ, o któr¹ ma siê zmieniæ liczba punktów gracza
    */
    void modify_score(int v) { score += v; }

    /**
    * Getter liczby punktów gracza.
    * 
    * \return score - liczba punktów gracza
    */
    int get_score() const { return score; }
private:
    /**
    * Pole przechowuj¹ce liczbê punktów gracza.
    */
    int score;

    /**
    * Pole przechowuj¹ce nick gracza.
    */
    string nick;
protected:
    /**
    * WskaŸnik do obiektu klasy Board.
    */
    Board* board = NULL;

};

/**
* Klasa dziedzicz¹ca po klasie Player umo¿liwiaj¹ca obs³ugê gracza ludzkiego podczas rozgrywki.
*/
class HumanPlayer : public Player {
public:
    /**
  * Kontruktor z argumentami inicjalizuj¹cy nick gracza oraz wskaŸnik do obiektu klasy Board na podane wartoœci, a tak¿e liczbê punktów automatycznie na 0.
  *
  * \param[in] nick - podany nick gracza
  * \param[in] *b - wskaŸnik do obiektu klasy Board
  */
    HumanPlayer(string nick, Board* b) :Player(nick, b) {};
    /**
    * Metoda wirtualna pobieraj¹ca ruch od gracza ludzkiego.
    *
    * \param[out] &x - adres, pod który zostanie wpisana podana wspó³rzêdna wiersza planszy sudoku.
    * \param[out] &y - adres, pod który zostanie wpisana podana wspó³rzêdna kolumny planszy sudoku.
    * \param[out] &v - adres, pod który zostanie wartoœæ do umieszczenia na polu (*x,*y) planszy sudoku.
    */
    void getMove(char& x, int& y, int& v);
};

/**
* Klasa dziedzicz¹ca po klasie Player, umo¿liwiaj¹ca obs³ugê gracza automatycznego podczas rozgrywki.
*/
class AutoPlayer : public Player {
public:
    /**
  * Kontruktor inicjalizuj¹cy nick gracza na "gracz autom.", liczbê punktów na 0 oraz wskaŸnik do obiektu klasy Board na podan¹ wartoœæ. Inicjalizuje tak¿e wszystkie pola tablicy tab na true.
  *
  * \param[in] nick - podany nick gracza
  * \param[in] *b - wskaŸnik do obiektu klasy Board
  */
    AutoPlayer(Board* b) : Player("gracz autom.", b) {
        for (int i = 0; i < P; i++)
            for (int j = 0; j < P; j++)
                for (int k = 0; k < P; k++)
                    tab[i][j][k] = true;
    }
    /**
    * Metoda wirtualna generuj¹ca ruch gracza automatycznego za pomoc¹ algorytmu wype³niaj¹cego tablicê trójwymiarow¹ wartoœciami informuj¹cymi o mo¿liwoœci
    * postawienia danej wartoœci na danym polu, przy wykorzystaniu ju¿ wype³nionych pól.
    *
    * \param[out] &x - adres, pod który zostanie wpisana podana wspó³rzêdna wiersza planszy sudoku.
    * \param[out] &y - adres, pod który zostanie wpisana podana wspó³rzêdna kolumny planszy sudoku.
    * \param[out] &v - adres, pod który zostanie wartoœæ do umieszczenia na polu (*x,*y) planszy sudoku.
    */
    void getMove(char& x, int& y, int& v);

private:
    /**
    * Tablica trójwymiarowa przechowuj¹ca informacje na temat mo¿liwych do wstawienia na danym polu planszy cyfr.
    */
    bool tab[P][P][P];
};



