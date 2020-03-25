*******************************************************************
Saper - etap 1
*******************************************************************

UWAGA: Obowiązuje zakaz wczytywania czegokolwiek z klawiatury. Jedyną funkcją (na tym etapie) której wolno cokolwiek wyświetlić na ekranie jest funkcja `debug_display()`.

Proszę opracować klasę reprezentującą planszę do gry Saper (Minesweeper). Klasa powinna posiadać informacje o:
* rozmiarze planszy (można przyjąć, że nie przekracza pewnego ustalonego maksimum, np. 100x100)
* stanie każdego z pól:
  * ukryte lub odkryte
  * bezpieczne lub z miną
  * ma "flagę" lub jej nie ma

Wskazówka: informacje o pojedynczym polu na planszy możemy przechowywać w strukturze:
```C++
  struct Field
  {
    bool hasMine;
    bool hasFlag;
    bool isRevealed;
  };

  class MinesweeperBoard
  {
    Field board[100][100];
    int width;
    int height;
    public:
      MinesweeperBoard();
      void debug_display() const;
  };
```

Waszym pierwszym zadaniem jest napisanie konstruktora klasy Plansza oraz funkcji `debug_display()`.
Konstruktor ma:
* ustawić wysokosc i szerokosc planszy (na wartość nie większą niż 100x100 - bo taką sobie tablicę przygotowaliśmy). Proponuję coś "rozsądnego", np. 10x10
* ustawić stan początkowy wszystkich pól planszy na: "nie ma miny", "pole zakryte", "nie ma flagi"

Funkcja `debug_display()` ma wyświetlić planszę w celu weryfikacji poprawności przeprowadzanych operacji - każde pole ma być wyświetlone jako ciąg 3 znaków w nawiasach kwadratowych.
* Znak pierwszy informuje czy na polu jest mina - jeśli jest, to wyświetlamy literę 'M'
* Znak drugi - czy pole jest odkryte ('o')
* Znak trzeci - informuje czy na polu jest flaga - 'f'

Jeśli dany znacznik nie jest ustawiony - wyświetlamy kropkę, np:
```
[M..][...][...][M..][.o.]
[.o.][...][M..][...][.o.]
[M.f][...][...][..f][M..]
```
Następnie proszę zmodyfikować konstruktor i umieścić na planszy jakiś konkretny stan, np.:
* pole (0,0) - zawiera minę
* pole (1,1) - jest odkryte
* pole (2,0) - zawiera minę i flagę

Sprawdzić, czy funkcja `debug_display()` poprawnie wyświetli tą planszę, czyli czy zobaczymy:
```
[M..][...][M.f][...][...]
[...][.o.][...][...][...]
[...][...][...][...][...]
```

*******************************************************************
Kilka wskazówek dotyczących realizacji projektów na które będę zwracał uwagę:
*******************************************************************

- cały kod piszemy w języku angielskim,
- usuwamy zakomentowany kod,
- projekt dostarczamy razem z plikiem CMakeList.txt
- rozbijamy plik nagłówkowy od ciała funkcji (hpp, cpp),
- jeden nagłówek to jedna klasa/struktura -> `minesweeperboard.hpp`, `field.hpp`, itp.,
- komentarze w kodzie robimy w języku angielskim,
- nie zostawiamy kodu testowego (w przyszłości tego typu rzeczy mogą wpływać na bezpieczeństwo aplikacji) – do testowania kodu są testy jednostkowe o których będę mówił na zajęciach,
- korzystamy z ułatwień jakie daje nam język c++,
- w metodach klasy staramy się korzystać ze wskaźnika `this` – informujemy jednoznacznie czytającego skąd się bierze dana metoda lub pole:
```C++
void MinesweeperBoard::debugDisplay() const{
    for (unsigned int i = 0; i< this->height; i++) {
            …
    }
}
```
- do ustawiania pól wykorzystujemy tak zwane settery (enkapsulacja) np.:
```C++
void MinesweeperBoard::setField(int width, int height, const Field& field) {
    if (width < this->width && height < this->height) {
      this->board[height][width] = field;
    }
}
```
- nazwy zmiennych, które są przekazywane do metod powinny nazywać się tak samo, ułatwia to czytanie oraz debugowanie kodu:
```C++
MinesweeperBoard::minesweeperBoard(unsigned int width, unsigned int height): width(width), height(height) {}
```
- jeśli mamy klasę, to zawsze najpierw interesuje nas to jaki interfejs udostępnia, czyli w pierwszej kolejności wypisujemy konstruktory oraz metody publiczne:
```C++
class MinesweeperBoard {
  public:
    MinesweeperBoard()
    void debugDisplay() const;
  protected:
    …
  private:
    …
};
```

*******************************************************************
Saper - etap 2 (rozwinięcie etapu 1)
*******************************************************************

Rozbuduj napisaną wcześniej klasę zgodnie z poniższą specyfikacją

Dodawaj po jednej funkcji , testuj, nie próbuj zrobić wszystkiego od razu! Do kolejnej funkcji przechodź dopiero wtedy, gdy wszystko co masz napisane działa poprawnie. Zwróć uwagę na to, że niektóre funkcje są ze sobą powiązane i łatwiej je napisać w odpowiedniej kolejności.

Pamiętaj, że do sprawdzenia działania konstruktora i niektórych innych funkcji możesz wykorzystać napisaną w poprzednim punkcie funkcję debug_display().

Sugeruję, żebyście najpierw napisali konsrtuktor, następnie wszystkie funkcje oznaczone jako "const".

**UWAGA - nadal obowiązuje zakaz wczytywania czegokolwiek z klawiatury !**

Dodatkowo polecam zapoznanie się z:
- https://github.com/isocpp/CppCoreGuidelines/blob/master/CppCoreGuidelines.md lub
- https://google.github.io/styleguide/cppguide.html

```C++
#ifndef MINESBOARD_H__
#define MINESBOARD_H__

enum GameMode  { DEBUG, EASY, NORMAL, HARD };
enum GameState { RUNNING, FINISHED_WIN, FINISHED_LOSS };

// HINT
struct Field
{
	bool hasMine;
	bool hasFlag;
	bool isRevealed;
};


class MinesweeperBoard
{
// this is just a hint; you are free to implement PRIVATE section in any way you want
  Field board[100][100];
  int width;
  int height;
  
public:
  // generate a width*height sized board with the number of mines that depend on GameMode:
  // - EASY   - 10% of game fields with mines (random)
  // - NORMAL - 20% of game fields with mines (random)
  // - HARD   - 30% of game fields with mines (random)
  // - DEBUG  - predefined mine layout (read at the end of file)
  //
  // NOTE: You may assume, that width and height are not larger than 100
  // HINT: It is OK to allocate 100x100 board and only use part of it 
  MinesweeperBoard(int width, int height, GameMode mode ); 

  // simple getters - return appropriate values (passed to or calculated in constructor)
  int getBoardWidth() const;
  int getBoardHeight() const;
  int getMineCount() const;

  // count mines around (x,y) position
  // if the field at (x,y) was not revealed - return -1
  // if either x or y is outside board      - return -1
  // otherwise - return mine count around this field
  // Examples for DEBUG layout (assuming the field is already revealed)
  // - countMines(0,1) should return 4
  // - countMines(9,2) should return 0
  // - countMines(1,2) should return 3
  // - countMines(7,6) should return 1
  int countMines(int x, int y) const;  

  // return true if the field at (x,y) position was marked with flag
  // return false if any of the following is true:
  // - x or y is outside board
  // - there is no flag on the field
  // - field was already revealed
  bool hasFlag(int x, int y) const;

  // if the field at (x,y) was not revealed - change flag status for this field 
  // Do nothing if any of the following is true
  // - field was already revealed
  // - either x or y is outside board
  // - game is already finished
  void toggleFlag(int x, int y);

  // try to reveal the field at (x,y)
  // Do nothing if any of the following is true
  // - field was already revealed
  // - either x or y is outside board
  // - game is already finished
  // - there is a flag on the field
  //
  // If the field was not revealed and there is no mine on it - reveal it
  // If the field was not revealed and there is a mine on it:  
  // - if its the first player action - move mine to another location, reveal field (not in DEBUG mode!)
  // - reveal it and finish game
  void revealField(int x, int y);

  // return true if the field was revealed
  bool isRevealed(int x, int y) const;

  // return current game state:
  // - FINISHED_LOSS - if the player revealed field with mine
  // - FINISHED_WIN - if the player won the game:
  // --- all unrevealed fields have mines 
  // - RUNNING - if the game is not yet finished 
  GameState getGameState() const;

  // convenience function - returns useful information about field in one function call
  // if x or y is outside board                             - return '#' character
  // if the field is not revealed and has a flag            - return 'F' character
  // if the field is not revealed and does not have a flag  - return '_' (underscore) character
  // if the field is revealed and has mine                  - return 'x' character
  // if the field is revealed and has 0 mines around        - return ' ' (space) character
  // if the field is revealed and has some mines around     - return '1' ... '8' (number of mines as a digit)
  char getFieldInfo(int x, int y) const;
};

#endif
```

```
// predefined mine field layout:
// field at coordinates x,y has mine, if any of the following is true
// - x==y (all fields on main diagonal have mines)
// - y==0 (all fields in first row have mines)
// - x==0 and y%2 == 0 (every second field in first column has mine)
// 
// Assuming we have 9x7 board size, debug_display() should show:

[M..][M..][M..][M..][M..][M..][M..][M..][M..]
[...][M..][...][...][...][...][...][...][...]
[M..][...][M..][...][...][...][...][...][...]
[...][...][...][M..][...][...][...][...][...]
[M..][...][...][...][M..][...][...][...][...]
[...][...][...][...][...][M..][...][...][...]
[M..][...][...][...][...][...][M..][...][...]
```

*******************************************************************
Saper - etap 3 (rozwinięcie etapu 1 oraz 2)
*******************************************************************

Dodaj do programu klasę **MSBoardTextView**, która będzie potrafiła wyświetlić planszę w trybie teksotwym w postaci takiej, jaką powinien zobaczyć gracz (czyli nie tak jak to robi `debug_display()` ).

Obiekt tej klasy powinien dostać referencję na planszę jako argument wywołania konstruktora, tak aby możliwe było napisanie programu:

```C++
int main() 
{ 
  MinesweeperBoard board (20, 10, GameMode::EASY); 
  MSBoardTextView view ( board ); 
  view.display(); 
  board.revealField(0,5);
  view.display(); 
} 
```

Wydzielenie funkcjonalności wyświetlania planszy do osobnej klasy może Wam się w tej chwili wydawać dziwne i nienaturalne, ale w przyszłości nam się to przyda. Dzięki temu, że rozdzielimy kwestię logiki (MinesweeperBoard) od sposobu jej prezentacji (MSBoardTextView), będziemy mogli bez modyfikacji użyć klasy MinesweeperBoard w aplikacji "graficznej".

*******************************************************************
Saper - etap 4 (rozwinięcie etapu 1, 2 oraz 3)
*******************************************************************
#### Informacja organizacyjna
Skoro już wszyscy mieliśmy okazje zobaczyć jakie robimy podstawowe błędy oraz jakie były komentarze do kodu przechodzimy do prawdziwej pracy.

Projekt saper (etap 1,2,3 i 4) oraz każdy kolejny projekt, oddajemy w następujący sposób:
- tworzymy prywatne repozytorium na github,
- dodajemy mnie jako collaborator (w swoim prywatnym repozytorium klikamy w `Settings` -> `Manage access` -> `Invite a collaborator`)

Osoby, które korzystają z https://zts.ita.pwr.wroc.pl/gitlab/users/sign_in - stosują się do instrukcji, która znajduje się na forum wykładu.

Termin:
- 2 kwietnia, wszystkie 4 etapy – kiedy projekt będzie Państwa zdaniem gotowy do oddania, proszę o maila.

Dodatkowo dla osób, które chcą wyższą ocenę to do 9 kwietnia należy rozbudować projekt „saper” o graficzny interfejs z wykorzystaniem biblioteki SFML.

W związku z tym, że przeszliśmy tylko na model konsultacji, oprócz kontaktu mailowego jestem dostępny również na: https://eagle.ita.pwr.wroc.pl/.

Dla tych co mają jeszcze problemy z gitem: https://rogerdudler.github.io/git-guide/index.pl.html


#### Treść zadania
Rozbuduj aplikację do kompletnej, działającej w trybie tekstowym gry.

Dodaj do projektu kolejną klasę - MSTextController. Konstruktor tej klasy powinien otrzymać planszę oraz "widok". Klasa ma jedną funkcję - play() - w tej funkcji implementujemy "komunikację" z graczem (człowiekiem).

W tej klasie MOŻNA używać cin ;)

```C++
int main() 
{ 
  MinesweeperBoard board (20, 10, GameMode::EASY); 
  MSBoardTextView view ( board ); 
  MSTextController ctrl ( board, view );
 
  ctrl.play();
}
```


