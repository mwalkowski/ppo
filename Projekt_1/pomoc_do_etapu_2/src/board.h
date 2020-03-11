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
    // --- all mines were flagged and there are no flags on fields without mines, or
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