#include <iostream>
#include "board.h"

int main(){
    MinesweeperBoard *board = new MinesweeperBoard(9, 7, DEBUG);
    board->debug_display();
    std::cout << '\n';
    board = new MinesweeperBoard(9, 7, EASY);
    board->debug_display();
    std::cout << '\n';
    board = new MinesweeperBoard(9, 7, NORMAL);
    board->debug_display();
    std::cout << '\n';
    board = new MinesweeperBoard(9, 7, HARD);
    board->debug_display();
    /*std::cout << '\n';
    board->setField(0, 0, Field(true, false, false));
    board->setField(1, 1, Field(false, false, true));
    board->setField(2, 0, Field(true, true, false));
    board->debug_display();*/
    return 0;
}
