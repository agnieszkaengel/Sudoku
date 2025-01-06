#include"Board.hpp"
#include"Player.hpp"
/**
* Klasa umo¿liwiaj¹ca obs³ugê rozgrywki.
*/
class Game
{
public:
    /**
    * Metoda przeprowadzaj¹ca rozgrywkê przy wykorzystaniu pozosta³ych metod klasy Game: wypisuje menu, pobiera wybór opcji gry i dopasowuje do niego ekran
    * rozgrywki. Pobiera nicki od odpowiedniej iloœci graczy i sprawdza czy istnieje mo¿liwoœæ kontynuacji poprzedniej rozgrywki. Ustala kolejnoœæ poboru 
    * ruchów od graczy (gdy jest ich wiêcej ni¿ jeden i pobiera od nich na zmianê ruchy. Jednoczeœnie sprawdza ich poprawnoœæ i modyfikuje planszê sudoku oraz
    * liczbê punktów graczy. Po wykonaniu ka¿dego ruchu gracza wpisuje aktualny stan rozgrywki w plik, s³u¿¹cy potem do ewetualnego wznowienia rozgrywki.
    * 
    */
    void play(void);

private:

    /**
    * Metoda pobieraj¹ca od u¿ytkownika wybór opcji z menu i sprawdzaj¹ca jego poprawnoœæ.
    * 
    * \return cyfra przedstawiaj¹ca wybran¹ przez grcza opcjê z menu 
    */
    int get_selection(void);

    /**
    * Metoda wyœwietlaj¹ca odpowiedni ekran w stosunku do wyboru opcji z menu.
    * 
    * \param[in] w - cyfra przedstawiajaca wybran¹ przez gracza opcjê z menu 
    */
    void prepare_screen(int w);

    /**
    * Metoda pobieraj¹ca od graczy nicki oraz tworz¹ca nazwê pliku do zapisu danych rozgrywki graczy o podanych nickach.
    * 
    * \param[in] w - opcja rozgrywki wybrana przez gracza z menu
    * \param[in] &filename - adres, pod który zostanie wpisana utworzona nazwa pliku
    */
    void get_nicks(int w, string& filename);

    /**
    * Metoda wyœwietlaj¹ca ekran informuj¹cy o zakoñczeniu oraz wyniku gry.
    */
    void end_of_game(void);

    /**
    * Obiekt klasy Board umo¿liwiaj¹cy obs³ugê planszy sudoku podczas rozgrywki.
    */
    Board board;

    /**
    * WskaŸnik do obiektu klasy Player.
    */
    Player* player1 = NULL, * player2 = NULL;

    /**
    * Obiekt klasy Menu umo¿liwiaj¹cy wyœwietlenie menu podczas rozgrywki.
    */
    Menu menu;

    /**
    * Obiekt klasy Inst umo¿liwiaj¹cy wyœwietlenie instrukcji podczas rozgrywki.
    */
    Inst inst;

};