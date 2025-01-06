#include"Board.hpp"
#include"Player.hpp"
/**
* Klasa umo�liwiaj�ca obs�ug� rozgrywki.
*/
class Game
{
public:
    /**
    * Metoda przeprowadzaj�ca rozgrywk� przy wykorzystaniu pozosta�ych metod klasy Game: wypisuje menu, pobiera wyb�r opcji gry i dopasowuje do niego ekran
    * rozgrywki. Pobiera nicki od odpowiedniej ilo�ci graczy i sprawdza czy istnieje mo�liwo�� kontynuacji poprzedniej rozgrywki. Ustala kolejno�� poboru 
    * ruch�w od graczy (gdy jest ich wi�cej ni� jeden i pobiera od nich na zmian� ruchy. Jednocze�nie sprawdza ich poprawno�� i modyfikuje plansz� sudoku oraz
    * liczb� punkt�w graczy. Po wykonaniu ka�dego ruchu gracza wpisuje aktualny stan rozgrywki w plik, s�u��cy potem do ewetualnego wznowienia rozgrywki.
    * 
    */
    void play(void);

private:

    /**
    * Metoda pobieraj�ca od u�ytkownika wyb�r opcji z menu i sprawdzaj�ca jego poprawno��.
    * 
    * \return cyfra przedstawiaj�ca wybran� przez grcza opcj� z menu 
    */
    int get_selection(void);

    /**
    * Metoda wy�wietlaj�ca odpowiedni ekran w stosunku do wyboru opcji z menu.
    * 
    * \param[in] w - cyfra przedstawiajaca wybran� przez gracza opcj� z menu 
    */
    void prepare_screen(int w);

    /**
    * Metoda pobieraj�ca od graczy nicki oraz tworz�ca nazw� pliku do zapisu danych rozgrywki graczy o podanych nickach.
    * 
    * \param[in] w - opcja rozgrywki wybrana przez gracza z menu
    * \param[in] &filename - adres, pod kt�ry zostanie wpisana utworzona nazwa pliku
    */
    void get_nicks(int w, string& filename);

    /**
    * Metoda wy�wietlaj�ca ekran informuj�cy o zako�czeniu oraz wyniku gry.
    */
    void end_of_game(void);

    /**
    * Obiekt klasy Board umo�liwiaj�cy obs�ug� planszy sudoku podczas rozgrywki.
    */
    Board board;

    /**
    * Wska�nik do obiektu klasy Player.
    */
    Player* player1 = NULL, * player2 = NULL;

    /**
    * Obiekt klasy Menu umo�liwiaj�cy wy�wietlenie menu podczas rozgrywki.
    */
    Menu menu;

    /**
    * Obiekt klasy Inst umo�liwiaj�cy wy�wietlenie instrukcji podczas rozgrywki.
    */
    Inst inst;

};